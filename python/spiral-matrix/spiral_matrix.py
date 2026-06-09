def spiral_matrix(size):
    matrix = []
    if size > 0:
        matrix = [[0 for _ in range(size)] for _ in range(size)]

        top_row = 0
        bottom_row = size - 1
        left_col = 0
        right_col = size - 1
        fill_number = 1

        while fill_number <= size * size:
            for column in range(left_col, right_col + 1):
                matrix[top_row][column] = fill_number
                fill_number += 1

            top_row += 1

            for row in range(top_row, bottom_row + 1):
                matrix[row][right_col] = fill_number
                fill_number += 1

            right_col -= 1

            for column in range(right_col, left_col - 1, -1):
                matrix[bottom_row][column] = fill_number
                fill_number += 1

            bottom_row -= 1

            for row in range(bottom_row, top_row - 1, -1):
                matrix[row][left_col] = fill_number
                fill_number += 1

            left_col += 1

    return matrix