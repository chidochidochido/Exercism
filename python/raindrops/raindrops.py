def convert(number):
    outputString = ""
    factor = False
    
    if number % 3 == 0:
        outputString += "Pling"
        factor = True

    if number % 5 == 0:
        outputString += "Plang"
        factor = True

    if number % 7 == 0:
        outputString += "Plong"
        factor = True

    if factor == False:
        outputString += str(number)

    return outputString