import os
import re

# --- POKÉMON GBA GEN 3 FONT WIDTHS --------------------
POKEMON_GBA_FONT_WIDTHS = {
    " ": 3, "!": 3, '"': 5, "#": 7, "$": 7, "%": 7, "&": 7, "'": 3,
    "(": 4, ")": 4, "*": 7, "+": 7, ",": 3, "-": 4, ".": 3, "/": 7,
    "0": 6, "1": 5, "2": 6, "3": 6, "4": 6, "5": 6, "6": 6, "7": 6,
    "8": 6, "9": 6,
    ":": 3, ";": 3, "<": 7, "=": 7, ">": 7, "?": 6,
    "A": 7, "B": 7, "C": 7, "D": 7, "E": 7, "F": 7, "G": 7, "H": 7,
    "I": 3, "J": 6, "K": 7, "L": 6, "M": 7, "N": 7, "O": 7, "P": 7,
    "Q": 7, "R": 7, "S": 7, "T": 7, "U": 7, "V": 7, "W": 7, "X": 7,
    "Y": 7, "Z": 7,
    "a": 6, "b": 6, "c": 6, "d": 6, "e": 6, "f": 4, "g": 6, "h": 6,
    "i": 3, "j": 3, "k": 6, "l": 3, "m": 7, "n": 6, "o": 6, "p": 6,
    "q": 6, "r": 4, "s": 6, "t": 4, "u": 6, "v": 6, "w": 7, "x": 6,
    "y": 6, "z": 6,
    "’": 3, "“": 5, "”": 5, "…": 9,
}

# Allowed width (Gen 3)
MAX_WIDTH = 240

# ---- CONTROL CODE HANDLING ----------------------------

# Codes that produce TEXT (must be expanded)
TEXT_CODES = {
    "PLAYER": "PLAYER",
    "RIVAL": "RIVAL",
    "POKEBLOCK": "POKEBLOCK",
    "STR_VAR_1": "VALUE1",
    "STR_VAR_2": "VALUE2",
    "STR_VAR_3": "VALUE3",
}

# Regex for `{SOMETHING}`
CTRL_PATTERN = re.compile(r"\{([^}]+)\}")

def process_control_codes(text):
    """
    Replace text-producing codes with their text,
    and remove non-text control codes.
    """
    def repl(match):
        code = match.group(1)

        # Text-producing codes
        if code in TEXT_CODES:
            return TEXT_CODES[code]

        # Everything else → ignored (0-width)
        return ""

    return CTRL_PATTERN.sub(repl, text)

# --------------------------------------------------------

def measure_line_width(text):
    text = process_control_codes(text)

    total = 0
    for ch in text:
        total += POKEMON_GBA_FONT_WIDTHS.get(ch, 7)
    return total


def check_dialogue_line(text, filename, line_number):
    match = re.search(r'\.string\s+"([^"]*)"', text)
    if not match:
        return

    raw = match.group(1)

    segments = re.split(r'\\n|\\p', raw)

    for seg in segments:
        cleaned = process_control_codes(seg)
        width = measure_line_width(cleaned)

        if width > MAX_WIDTH:
            excess = width - MAX_WIDTH
            print(f"\n⚠️ Overflow Warning")
            print(f"   File: {filename}")
            print(f"   Line: {line_number}")
            print(f"   Text: {cleaned!r}")
            print(f"   Width: {width}px (exceeds by {excess}px)")


def check_folder(path):
    for root, dirs, files in os.walk(path):
        for fname in files:
            fullpath = os.path.join(root, fname)
            with open(fullpath, "r", encoding="utf-8", errors="ignore") as f:
                for i, line in enumerate(f, start=1):
                    if ".string" in line:
                        check_dialogue_line(line.rstrip(), fname, i)


# ------------------------------
FOLDER = "/home/eneko/Desktop/pokeemerald-eusk/data/text"
check_folder(FOLDER)
