def affine_encrytption(text, a, b):
    result = ""
    for char in text:
        new_char = char((a * (ord(char) - 65) + b) % 26 + 65)
        result = result + new_char

    return result

# main part

a = 5
b = 7
plaintext = "SECRET"

encrypted = affine_encrytption(plaintext, a, b)