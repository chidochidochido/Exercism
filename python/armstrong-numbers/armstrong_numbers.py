def is_armstrong_number(number):
    number_of_digits = len(str(number))
    digits_index = 0
    armstrong_counter = 0

    while digits_index < number_of_digits:
        armstrong_counter += int(str(number)[digits_index]) ** number_of_digits
        digits_index += 1

    return armstrong_counter == number