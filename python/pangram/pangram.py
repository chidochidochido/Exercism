def is_pangram(sentence):
    sentence = sentence.lower()
    letterFlags = {
        'a': False,
        'b': False,
        'c': False,
        'd': False,
        'e': False,
        'f': False,
        'g': False,
        'h': False,
        'i': False,
        'j': False,
        'k': False,
        'l': False,
        'm': False,
        'n': False,
        'o': False,
        'p': False,
        'q': False,
        'r': False,
        's': False,
        't': False,
        'u': False,
        'v': False,
        'w': False,
        'x': False,
        'y': False,
        'z': False
    }

    isPangram = True

    for letter in sentence:
        if letter.isalpha():
            letterFlags[letter] = True

    for key in letterFlags:
        if letterFlags[key] == False:
            isPangram = False

    return isPangram