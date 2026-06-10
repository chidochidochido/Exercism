pub fn spiral_matrix(size: u32) -> Vec<Vec<u32>> {
    let size_usize = size as usize;
    let mut matrix = vec![vec![0; size_usize]; size_usize];

    if size == 0 {
        return matrix;
    }

        
    let mut top_row = 0;
    let mut bottom_row = size_usize - 1;
    let mut left_col = 0;
    let mut right_col = size_usize - 1;
    let mut fill_number = 1;

    while fill_number <= size * size {
        for column in left_col..=right_col {
            matrix[top_row][column] = fill_number;
            fill_number += 1;
        }

        if fill_number > size * size { break; } 

        top_row += 1;

        for row in top_row..=bottom_row {
            matrix[row][right_col] = fill_number;
            fill_number += 1;
        }

        if fill_number > size * size { break; } 

        right_col -= 1;

        for column in (left_col..=right_col).rev() {
            matrix[bottom_row][column] = fill_number;
            fill_number += 1;
        }

        if fill_number > size * size { break; } 

        bottom_row -= 1;
        
        for row in (top_row..=bottom_row).rev() {
            matrix[row][left_col] = fill_number;
            fill_number += 1;
        }

        if fill_number > size * size { break; } 

        left_col += 1;
    }

    matrix
}

