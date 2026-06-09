#include <stdlib.h>
#include "spiral_matrix.h"

spiral_matrix_t* spiral_matrix_create(int spiral_size) {
    spiral_matrix_t* result = malloc(sizeof(spiral_matrix_t));

    result->size = spiral_size;

    if(spiral_size == 0) {
        result->matrix = NULL;
    }
    else {
        result->matrix = malloc(spiral_size * sizeof(int*));

        for(int i = 0; i < spiral_size; i++) {
            result->matrix[i] = malloc(spiral_size * sizeof(int));
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
            for(int i = 0; i < matrix->size; i++) {
                free(matrix->matrix[i]);
            }
            free(matrix->matrix);
        }
        free(matrix);
    }
}