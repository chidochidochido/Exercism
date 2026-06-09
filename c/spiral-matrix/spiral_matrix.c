#include <stdlib.h>
#include "spiral_matrix.h"

spiral_matrix_t* spiral_matrix_create(int spiral_size) {
    spiral_matrix_t* result = malloc(sizeof(spiral_matrix_t));

    result->size = spiral_size;

    if(spiral_size == 0) {
        result->matrix = NULL;
    }
    else {
        // 1. Allocate the array of row pointers (as usual)
        result->matrix = malloc(spiral_size * sizeof(int*));

        // 2. Allocate ALL the integers in one single block of memory
        int* all_data = malloc(spiral_size * spiral_size * sizeof(int));

        // 3. Aim the row pointers at the correct offsets within that single block
        for(int i = 0; i < spiral_size; i++) {
        result->matrix[i] = &all_data[i * spiral_size];
        // or equivalently: all_data + (i * spiral_size)
        }
    
        int top_row = 0;
        int bottom_row = spiral_size - 1;
        int left_col = 0;
        int right_col = spiral_size - 1;
        int fill_number = 1;

        while(fill_number <= spiral_size * spiral_size) {
            for(int column = left_col; column <= right_col; column++) {
                result->matrix[top_row][column] = fill_number++;
            }

            top_row += 1;

            for(int row = top_row; row <= bottom_row; row++) {
                result->matrix[row][right_col] = fill_number++;
            }

            right_col -= 1;

            for(int column = right_col; column >= left_col; column--) {
                result->matrix[bottom_row][column] = fill_number++;
            }

            bottom_row -= 1;
            
            for(int row = bottom_row; row >= top_row; row--) {
                result->matrix[row][left_col] = fill_number++;
            }

            left_col += 1;
        }
    }
    
    return result;
}

void spiral_matrix_destroy(spiral_matrix_t* matrix) {
    if(matrix != NULL) {
        if(matrix->matrix != NULL) {
            free(matrix->matrix[0]); // 3. Frees the giant integer block 'all_data'
            free(matrix->matrix);    // 2. Frees the array of row pointers
        }
        free(matrix);                // 1. Frees the struct itself
    }
}