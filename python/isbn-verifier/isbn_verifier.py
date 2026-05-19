def is_valid(isbn):
    isbn = isbn.strip("-")
    print(isbn)

    isbnVerifierPolynomial = 0
    factor = 10

    for char in isbn[:-1]:

        if char.isdigit():
            isbnVerifierPolynomial =  isbnVerifierPolynomial + (int(char) * factor)
            factor = factor - 1
        
    if isbn[-1] == 'X':
        char = 10
    elif isbn[-1].isdigit():
        char = int(char)
    
    isbnVerifierPolynomial += int(char) * factor

    if isbnVerifierPolynomial % 11 == 0:
        return True
    else:
        return False