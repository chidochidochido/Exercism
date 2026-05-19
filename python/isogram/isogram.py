def is_isogram(string):
    string = string.lower()
    letterFlags = {}
    isIsogram = True

    for char in string:
        if char.isalpha():
            if char in letterFlags:
                if letterFlags[char] == True:
                    isIsogram = False
            else:
                letterFlags[char] = True
    return isIsogram