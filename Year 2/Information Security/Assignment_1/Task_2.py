from math import gcd

def affine_encrypt(text, a, b):
    result = ""
    for char in text:
        # There was no lowercase requested, so it's only upper case check..
        x = ord(char) - 65
        y = (a * x + b) % 26
        new_char = chr(y + 65)
        result = result + new_char
    return result


def affine_decrypt(text, a, b):
    result = ""
    
    # Find modular inverse of a.
    a_inv = None
    for i in range(1, 26):
        if (a * i) % 26 == 1:
            a_inv = i
            break
    
    for char in text:
        y = ord(char) - 65
        # x = a_inv * (y - b) mod 26
        x = (a_inv * (y - b)) % 26
        new_char = chr(x + 65)
        result = result + new_char
    
    return result

# Main part.
a = 5
b = 7
plaintext = "SECRET"

# Checks if it's valid (coprime with 26).
if gcd(a, 26) != 1:
    print("Error: a and 26 are not coprime!")
    print("gcd(", a, ", 26) =", gcd(a, 26))
else:
    encrypted = affine_encrypt(plaintext, a, b)
    decrypted = affine_decrypt(encrypted, a, b)
    
    print("Plaintext  :", plaintext)
    print("Key        : a =", a, " b =", b)
    print("Encrypted  :", encrypted)
    print("Decrypted  :", decrypted)