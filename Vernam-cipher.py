def Vernam(Plain, Key, Flag):
    result = ""
    for i in range(len(Plain)):
        char = Plain[i]
        if(Flag):
            result += chr((ord(char)-65 + ord(Key[i])-65) % 26 + 65)
        else:
            result += chr((ord(char) - ord(Key[i])+26) % 26 + 65)
    return result


choice = int(input("1. Encrypt Text 2. Decrypt Text\n"))
if choice == 1:
    Key = ''.join(input("Enter Message in upper case only: ").split())
    Plain = ''.join(input("Enter Key in upper case only: ").split())
    if(len(Key) != len(Plain)):
        print("Invalid Key!")
        exit()
    CipherText = Vernam(Plain, Key, True)
    print("CipherText: ", CipherText)
elif choice == 2:
    Cipher = ''.join(input("Enter CipherText in upper case only: ").split())
    Key = ''.join(input("Enter key in upper case only: ").split())
    if(len(Key) != len(Cipher)):
        print("Invalid Key!")
        exit()
    print("Plain Text: ", Vernam(Cipher, Key, False))
else:
    pass
