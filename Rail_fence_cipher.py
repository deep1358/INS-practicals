def encryptText(text, key):

    encryptRail = [['\n' for i in range(len(text))] for j in range(key)]

    dir_down = False
    row, col = 0, 0

    for i in range(len(text)):

        # check the direction of flow reverse the direction if we've just filled the top or bottom rail
        if (row == 0) or (row == key - 1):
            dir_down = not dir_down

        encryptRail[row][col] = text[i]
        col += 1
        # find the next row using direction flag
        if dir_down:
            row += 1
        else:
            row -= 1

    # now we can construct the cipher using the rail matrix
    result = []
    for i in range(key):
        for j in range(len(text)):
            if encryptRail[i][j] != '\n':
                result.append(encryptRail[i][j])
    return("" . join(result))


def decryptText(cipher, key):
    decryptRail = [['\n' for i in range(len(cipher))] for j in range(key)]
    dir_down = None
    row, col = 0, 0
    for i in range(len(cipher)):
        if row == 0:
            dir_down = True
        if row == key - 1:
            dir_down = False

        decryptRail[row][col] = '*'
        col += 1
        # find the next row using direction flag
        if dir_down:
            row += 1
        else:
            row -= 1

    # now we can construct the fill the rail matrix
    index = 0
    for i in range(key):
        for j in range(len(cipher)):
            if ((decryptRail[i][j] == '*') and (index < len(cipher))):
                decryptRail[i][j] = cipher[index]
                index += 1

    # now read the matrix in zig-zag manner
    result = []
    row, col = 0, 0
    for i in range(len(cipher)):
        if row == 0:
            dir_down = True
        if row == key-1:
            dir_down = False

        if (decryptRail[row][col] != '*'):
            result.append(decryptRail[row][col])
            col += 1

        if dir_down:
            row += 1
        else:
            row -= 1

    return("".join(result))


choice = int(input("1. Encrypt 2. Decrypt \n"))
if choice == 1:
    plain = input("Plain Text : ")
    key = int(input("Key : "))
    cipher = encryptText(plain, key)
    print("Encrypted Text :", cipher)
elif choice == 2:
    cipher = input("Cipher Text : ")
    key = int(input("Key :"))
    plain = decryptText(cipher, key)
    print("Decrypted Text :", plain)
else:
    print("Invalid Input !!")
