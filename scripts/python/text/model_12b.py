# model_12b.py
import requests
import time
from python.data import _data
from python.data import db_manager
import validation  # Import our new validation module
from ..config import constants

# Model identification
MODEL_NAME = constants.MODEL_NAMES["olmo"]

def generate_response(word, max_attempts=1000000):
    """Send prompt to llama-server and get a proper description"""

    for attempt in range(max_attempts):
        # Skip if we already have enough for this creature/model
        if not db_manager.needs_generation(word, MODEL_NAME, desired_count=1):
            print(f"  ✅ Already have description for {word} with {MODEL_NAME}, skipping")
            return None

        prompt = validation.build_prompt(validation, word, attempt)

        payload = {
            "prompt": prompt,
            "max_tokens": 150,
            "temperature": 0.7 + (attempt * 0.0001),
            "top_p": 0.9,
        }

        try:
            response = requests.post(constants.SERVER_URL, json=payload, timeout=60)
            response.raise_for_status()
            result = response.json()
            text = result.get("content", "").strip()

            # Check for creature name in description
            text = validation.check_for_name(text, attempt, word)
            if text == "":
                continue

            # Normalize whitespace
            clean_text = ' '.join(text.split())
            print(f" Raw text: {clean_text}")

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
            print(f"  ✓ Valid response for {word} ({word_count} words)")
            print(f"{clean_text}")

            # Save to database immediately
            db_manager.save_to_db(
                creature_name=word,
                description=clean_text,
                attempt_num=attempt + 1,
                matches=matches,
                model_name=MODEL_NAME,
                prompt_version=constants.PROMPT_VERSION,
                temperature=payload["temperature"]
            )

            return clean_text

        except Exception as e:
            print(f"  ✗ Attempt {attempt + 1}/{max_attempts} failed: {str(e)[:50]}...")

    print(f"  ⚠ Failed to generate for {word} after {max_attempts} attempts")
    return None


def main():
    # Initialize database
    db_manager.init_database()

    print("Generating descriptions...")
    responses = []
    successful = 0
    skipped = 0

    for i, word in enumerate(_data.Creatures):
        print(f"\n  {i + 1}/{len(_data.Creatures)}: {word}")

        # Check if we need this creature
        if not db_manager.needs_generation(word, model_name=None, desired_count=1):
            print(f"  ✅ Already have {MODEL_NAME} description, skipping")
            skipped += 1
            continue

        response = generate_response(word)

        if response:
            responses.append(response)
            successful += 1
        else:
            print(f"  ⚠ Failed to generate for {word}")

        time.sleep(1)


if __name__ == "__main__":
    main()