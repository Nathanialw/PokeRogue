# model_24b.py
import requests
import time
import re
from python.data import _data
from python.data import db_manager
import validation  # Import validation module
from ..config import constants  # Import constants

# Model identification
MODEL_NAME = constants.MODEL_NAMES["qwen"]  # Use constant


def extract_description(text):
    """Extract the final description using multiple strategies"""
    # Simple cleanup after getting the text
    text = re.sub(r'<think>.*?</think>', '', text, flags=re.DOTALL).strip()

    # Strategy 1: Look for explicit markers
    for marker in ['Final Description:', 'Final Answer:', 'Best Description:', 'Selected Description:']:
        if marker in text:
            parts = text.split(marker)
            candidate = parts[-1].strip().split('\n')[0].strip()
            if candidate and len(candidate.split()) > 5:
                return candidate

    # Strategy 2: Look for the last description-like sentence
    sentences = re.split(r'[.!?]', text)
    for s in reversed(sentences):
        s = s.strip()
        words = s.split()
        if 10 <= len(words) <= 30 and re.match(r'^[A-Z][a-z]*(?:\s+(?:a|an|the))?', s):
            return s + "."

    # Strategy 3: Take the last paragraph that isn't thinking
    paragraphs = [p.strip() for p in text.split('\n\n') if p.strip()]
    for p in reversed(paragraphs):
        if not any(word in p.lower() for word in ['draft', 'attempt', 'step', 'analyze']):
            if len(p.split()) > 8:
                return p

    return text


def generate_response(word, max_attempts=1000000):
    """Send prompt to llama-server and get a proper description - never gives up!"""

    for attempt in range(max_attempts):
        # Double-check we still need this before each attempt
        if not db_manager.needs_generation(word, MODEL_NAME, constants.DESIRED_COUNT):
            print(f"  ✅ {word} already has {constants.DESIRED_COUNT} descriptions from {MODEL_NAME}")
            return None, attempt

        prompt = validation.build_prompt(validation, word, attempt)

        payload = {
            "prompt": prompt,
            "max_tokens": 4096,
            "temperature": 0.7 + (attempt * 0.01),
            "top_p": 0.95,
            "stop": []
        }

        try:
            print(f"  Sending request for {word} (attempt {attempt + 1})...")
            response = requests.post(
                f"{constants.SERVER_URL}",
                json=payload,
                timeout=120
            )

            if response.status_code != 200:
                print(f"  Status code: {response.status_code}, retrying...")
                continue

            result = response.json()
            text = result.get("content", "").strip()

            if not text:
                print(f"  ✗ Attempt {attempt + 1}: Empty response, retrying...")
                continue

            # Extract the actual description
            text = extract_description(text)

            # Check for creature name in description (uses validation module)
            text = validation.check_for_name(text, attempt, word)
            if text == "":
                continue

            # Clean the text
            clean_text = ' '.join(text.split())

            # Check length (minimum words)
            words = clean_text.split()
            if len(words) < constants.MIN_WORDS:
                print(f"  ✗ Attempt {attempt + 1}: Too short ({len(words)} words), retrying...")
                continue

            # Validate against creature-specific requirements
            is_valid, matches = validation.validate_creature_description(
                word, clean_text, attempt
            )
            if not is_valid:
                continue

            # Check length and format
            is_valid, word_count = validation.check_length_and_format(
                clean_text, attempt, max_attempts
            )
            if not is_valid:
                continue

            # Valid response!
            print(f"  ✓ Valid response ({word_count} words)")
            return clean_text, attempt + 1

        except Exception as e:
            print(f"  ✗ Attempt {attempt + 1}: {type(e).__name__} - {str(e)[:50]}, retrying...")
            time.sleep(2)

    print(f"  ⚠ Impossible: Exhausted all attempts for {word}")
    return None, max_attempts


def main():
    # Initialize database
    db_manager.init_database()

    print("=" * 60)
    print(f"Generating descriptions for model: {MODEL_NAME}")
    print(f"Prompt version: {constants.PROMPT_VERSION}")
    print(f"Desired per creature: {constants.DESIRED_COUNT}")
    print("=" * 60)

    responses = []
    generated = 0
    skipped = 0
    failed = 0

    for i, word in enumerate(_data.Creatures):
        print(f"\n  {i + 1}/{len(_data.Creatures)}: {word}")

        # Check if we already have enough descriptions for this creature/model
        if not db_manager.needs_generation(word, MODEL_NAME, constants.DESIRED_COUNT):
            existing = db_manager.get_existing_count(word, MODEL_NAME)
            print(f"  ✅ Already have {existing}/{constants.DESIRED_COUNT} descriptions from {MODEL_NAME}, skipping")
            skipped += 1
            continue

        # Generate until we have enough
        while db_manager.needs_generation(word, MODEL_NAME, constants.DESIRED_COUNT):
            result = generate_response(word)

            if result is None or result[0] is None:
                print(f"  ⚠ Failed to generate for {word}")
                failed += 1
                break

            response, attempt_num = result

            # Calculate matches for database (reuse validation but don't reject)
            matches = 0
            if word in _data.CREATURE_VALIDATION:
                validation_data = _data.CREATURE_VALIDATION[word]
                required_terms = validation_data["required_terms"]
                text_lower = response.lower()
                matches = sum(1 for term in required_terms if term in text_lower)

            # Save to database
            db_manager.save_to_db(
                creature_name=word,
                description=response,
                attempt_num=attempt_num,
                matches=matches,
                model_name=MODEL_NAME,
                prompt_version=constants.PROMPT_VERSION,
                temperature=0.7 + ((attempt_num - 1) * 0.01)
            )

            responses.append(response)
            generated += 1

            # Small delay between requests
            time.sleep(1)

    # Print summary
    print("\n" + "=" * 60)
    print("GENERATION COMPLETE")
    print("=" * 60)
    print(f"Total creatures: {len(_data.Creatures)}")
    print(f"Newly generated: {generated}")
    print(f"Skipped (already exist): {skipped}")
    print(f"Failed: {failed}")

    # Show database stats
    print("\n" + "=" * 60)
    print("DATABASE STATISTICS")
    print("=" * 60)

    # Stats for this model
    stats = db_manager.get_model_stats(MODEL_NAME)
    if stats:
        total, avg_words, _, unique = stats[0]
        print(f"Model: {MODEL_NAME}")
        print(f"  Total descriptions: {total}")
        print(f"  Unique creatures: {unique}")
        print(f"  Average words: {avg_words:.1f}")

    # Overall stats
    all_stats = db_manager.get_model_stats()
    if len(all_stats) > 1:
        print("\nAll models:")
        for stat in all_stats:
            if len(stat) == 4:
                model, total, avg_words, unique = stat
                print(f"  {model}: {total} desc, {unique} creatures, {avg_words:.1f} words")


if __name__ == "__main__":
    main()