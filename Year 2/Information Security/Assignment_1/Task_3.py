# substitution_frequency.py
# Simple frequency analysis + interactive substitution for monoalphabetic cipher

ciphertext = "Iq ifcc vqqr fb rdq vfllcq na rdq cfjwhwz hr bnnb hcc hwhhbsqvqbre hwq vhlq"

# ───────────────────────────────────────────────
# Part 1: Count frequency of each letter
# ───────────────────────────────────────────────

freq = {}
total_letters = 0

for char in ciphertext:
    if char.isalpha():
        char = char.upper()           # make everything uppercase
        total_letters += 1
        if char in freq:
            freq[char] += 1
        else:
            freq[char] = 1

# Sort by frequency (highest first)
sorted_freq = sorted(freq.items(), key=lambda x: x[1], reverse=True)

print("Ciphertext length (letters only):", total_letters)
print("\nLetter frequency in ciphertext:")
print("Letter | Count | Percentage")
print("-" * 35)
for letter, count in sorted_freq:
    percent = (count / total_letters) * 100
    print(f"{letter:6} | {count:5} | {percent:6.2f}%")

# ───────────────────────────────────────────────
# Standard English frequencies (approximate %)
# ───────────────────────────────────────────────

english_freq = {
    'E': 12.7, 'T': 9.1, 'A': 8.2, 'O': 7.5, 'I': 7.0,
    'N': 6.7, 'S': 6.3, 'H': 6.1, 'R': 6.0, 'D': 4.3,
    'L': 4.0, 'C': 2.8, 'U': 2.8, 'M': 2.4, 'W': 2.4,
    'F': 2.2, 'G': 2.0, 'Y': 2.0, 'P': 1.9, 'B': 1.5,
    'V': 1.0, 'K': 0.8, 'J': 0.15, 'X': 0.15, 'Q': 0.1, 'Z': 0.07
}

print("\nMost common English letters (approx %):")
print("E T A O I N S H R D L C U M W F G Y P B ...")
print("≈12.7 9.1 8.2 7.5 7.0 6.7 6.3 6.1 6.0 4.3 ...\n")

# ───────────────────────────────────────────────
# Interactive substitution
# ───────────────────────────────────────────────

# This will store our guessed mapping: cipher letter → plain letter
mapping = {}

def show_decrypted():
    result = ""
    for char in ciphertext:
        if char.isalpha():
            upper = char.upper()
            if upper in mapping:
                plain = mapping[upper]
                # keep original case
                if char.islower():
                    result += plain.lower()
                else:
                    result += plain
            else:
                result += char   # still unknown → show original
        else:
            result += char       # space or punctuation
    print("\nCurrent decryption:")
    print(result)
    print("-" * 70)


print("\n=== Interactive Substitution ===")
print("Type:   cipher_letter plain_letter    (example: Q E)")
print("Type:   done                         to finish")
print("Type:   show                         to see current text")
print("Type:   clear X                      to remove mapping for letter X\n")

show_decrypted()

while True:
    cmd = input("\nYour guess → ").strip().upper()
    
    if cmd == "DONE":
        print("\nFinal version:")
        show_decrypted()
        break
    
    elif cmd == "SHOW":
        show_decrypted()
        continue
    
    elif cmd.startswith("CLEAR "):
        letter = cmd[6:].strip()
        if letter in mapping:
            del mapping[letter]
            print(f"Removed mapping for {letter}")
            show_decrypted()
        else:
            print(f"No mapping for {letter}")
        continue
    
    # Expecting two letters: cipher plain
    parts = cmd.split()
    if len(parts) != 2:
        print("Format:  cipher_letter plain_letter   (example: Q E)")
        continue
    
    cipher_let, plain_let = parts
    
    if len(cipher_let) != 1 or len(plain_let) != 1:
        print("Please enter single letters only.")
        continue
    
    if not cipher_let.isalpha() or not plain_let.isalpha():
        print("Only letters allowed.")
        continue
    
    # Save the mapping (we store uppercase → uppercase)
    mapping[cipher_let] = plain_let
    print(f"Set: {cipher_let} → {plain_let}")
    
    show_decrypted()