# validation.py
import re
from python.config import constants
# from python.data import creature_descriptors


def check_for_name(text, attempt, word):
    """
    Check if the creature name appears in the description.
    Returns cleaned text or empty string if rejected.
    """
    # Split by sentences and take the first one
    sentences = re.split(r'(?<=[.!?])\s+', text)
    if sentences:
        text = sentences[0]

    # STRICT CHECK: Reject if the creature name appears ANYWHERE in the text
    creature_name_lower = word.lower()
    text_lower = text.lower()

    if creature_name_lower in text_lower:
        print(f"  ✗ Attempt {attempt + 1}: Contains creature name '{word}' - REJECTED")
        return ""

    # Also check for common variations
    variations = [
        f"the {creature_name_lower}",
        f"a {creature_name_lower}",
        f"an {creature_name_lower}",
        creature_name_lower + "s",  # plural
        creature_name_lower + "'s",  # possessive
    ]
    for var in variations:
        if var in text_lower:
            print(f"  ✗ Attempt {attempt + 1}: Contains '{var}' - REJECTED")
            return ""

    # Also check for "this creature" or similar generic references
    if re.search(r'\b(this|the) creature\b', text_lower):
        print(f"  ✗ Attempt {attempt + 1}: Contains generic 'the creature' reference")
        return ""

    print(f"  First sentence: {text}")
    return text


def validate_creature_description(word, clean_text, descriptors, attempt):
    """
    Validate a description against creature-specific requirements.
    Returns (is_valid, matches) tuple.
    """
    if not descriptors:
        return True, 0

    if word not in descriptors:
        return True, 0

    validation = descriptors[word]
    required_terms = validation["required_terms"]
    forbidden_terms = validation.get("forbidden_terms", [])
    min_matches = validation.get("min_matches", 2)

    text_lower = clean_text.lower()

    # Check required terms
    matches = sum(1 for term in required_terms if term in text_lower)

    # Check forbidden terms - track which ones were found
    forbidden_found = []
    for term in forbidden_terms:
        if term in text_lower:
            forbidden_found.append(term)

    if forbidden_found:
        print(f"  ✗ Attempt {attempt + 1}: Contains forbidden term(s) for {word}: {', '.join(forbidden_found)}")
        return False, matches

    if matches < min_matches:
        # Show which required terms were found vs missing
        found_terms = [term for term in required_terms if term in text_lower]
        missing_terms = [term for term in required_terms if term not in text_lower][:5]  # Show first 5 missing

        print(f"  ✗ Attempt {attempt + 1}: Only {matches}/{min_matches} matches for {word} characteristics")
        print(f"     Found: {', '.join(found_terms[:5])}...")
        print(f"     Missing: {', '.join(missing_terms)}...")
        print(f"     Text: {clean_text[:150]}...")
        return False, matches

    return True, matches


def check_length_and_format(clean_text, attempt, max_attempts):
    """
    Check if the response meets length criteria and isn't truncated.
    Returns (is_valid, word_count) tuple.
    """
    word_count = len(clean_text.split())

    # Check if the response meets criteria
    if constants.MIN_CHARS <= len(clean_text) <= constants.MAX_CHARS:
        if clean_text.endswith(('...', '..', '. .')):
            print(f"  ✗ Attempt {attempt + 1}/{max_attempts}: Truncated ending")
            return False, word_count

        return True, word_count
    else:
        print(f"  ✗ Attempt {attempt + 1}/{max_attempts}: {len(clean_text)} chars, {word_count} words, retrying...")
        return False, word_count


def get_terms_hint(word, descriptors, attempt, max_hint_attempts=constants.MAX_HINT_ATTEMPTS):
    """
    Get a hint with random required terms for the first X attempts.
    """
    if not descriptors:
        RED = '\033[91m'
        RESET = '\033[0m'

        print(f" {RED} ⚠ No validation data for {word}{RESET}")  # Debug output
        return ""

    # Check if creature exists in validation
    if word not in descriptors:
        RED = '\033[91m'
        RESET = '\033[0m'

        print(f" {RED} ⚠ No validation data for {word}{RESET}")  # Debug output
        return ""

    # Check attempt limit
    if attempt >= max_hint_attempts:
        return ""

    # Get required terms
    required_terms = descriptors[word].get("required_terms", [])

    # If no terms, log warning
    if not required_terms:
        print(f"  ⚠ No required_terms for {word}")
        return ""

    # Select random terms
    import random
    num_terms = min(5, len(required_terms))
    selected_terms = random.sample(required_terms, num_terms)

    return f"Include elements like: {', '.join(selected_terms)}."


def build_prompt(validation, word, attempt):
    # System instruction
    system_instruction = "You are a folklore expert specializing in mythical creatures. Provide only the description asked for, no explanations, DO NOT describe anything other than what is asked for. STRICTLY do NOT include the creature's name in the description."

    # Get terms hint from validation module
    terms_hint = validation.get_terms_hint(word, attempt)

    # Build prompt
    prompt = f"{system_instruction}\n\nDescribe a fantasy {word} creature in one vivid short sentence, {terms_hint} around 20-25 words please:"
    return prompt


def clean_text_for_c_string(text):
    """Clean and escape text for use in C string literals"""
    if not text:
        return ""

    # Remove any code blocks or markdown
    text = re.sub(r'```.*?```', '', text, flags=re.DOTALL)
    text = re.sub(r'`.*?`', '', text)

    # Clean up whitespace
    text = ' '.join(text.split())

    # Escape for C string
    text = text.replace('\\', '\\\\')
    text = text.replace('"', '\\"')
    text = text.replace('\n', '\\n')
    text = text.replace('\r', '\\r')
    text = text.replace('\t', '\\t')

    return text.strip()


def clean_reasoning_text(text):
    """Clean up the reasoning process to get just the description"""
    # Remove common thinking process patterns
    patterns_to_remove = [
        r'Thinking Process:.*?\n\n',
        r'Thought:.*?\n',
        r'Reasoning:.*?\n',
        r'Step \d+:.*?\n',
        r'\d+\.\s+.*?\n',
        r'\*\*.*?\*\*',
        r'Analysis:.*?\n',
        r'Let me think.*?\n',
        r'I need to.*?\n',
        r'First,.*?\n',
        r'Second,.*?\n',
        r'Finally,.*?\n',
        r'In summary,.*?\n',
        r'Therefore,.*?\n',
        r'^[A-Z][a-z]+:\s*',  # "Command:", "Request:", etc.
    ]

    for pattern in patterns_to_remove:
        text = re.sub(pattern, '', text, flags=re.IGNORECASE | re.DOTALL)

    # Take the last sentence if multiple (often the actual answer is at the end)
    sentences = re.split(r'[.!?]', text)
    if len(sentences) > 1:
        # Filter out empty sentences
        sentences = [s.strip() for s in sentences if s.strip()]
        if sentences:
            # Often the last sentence is the actual description
            text = sentences[-1] + "."

    return text.strip()
