def caesar_encrypt(text, key):
    result = ""
    
    for char in text:
        # Check if there is a upper case alphabet.
        if char >= 'A' and char <= 'Z':
            # As A=65 ... Z=90, so I'm minusing it with 65
            # ord() fucntion convert char to int.
            new_char = chr( (ord(char) - 65 + key) % 26 + 65 )
            result = result + new_char
            
        # Check if it's a lowercase letter.
        elif char >= 'a' and char <= 'z':
            # a=97 ... z=122
            new_char = chr( (ord(char) - 97 + key) % 26 + 97 )
            result = result + new_char
            
        # It will keep spaces, numbers the same.
        else:
            result = result + char
            
    return result


def caesar_decrypt(text, key):
    # Decryption is just encrypting with negative key.
    return caesar_encrypt(text, -key)


# Main part 

message = "Cryptography is fun!"
k = 17

print("Original message :", message)

encrypted = caesar_encrypt(message, k)
print("Encrypted  (key=" + str(k) + ") :", encrypted)

decrypted = caesar_decrypt(encrypted, k)
print("Decrypted  (key=" + str(k) + ") :", decrypted)