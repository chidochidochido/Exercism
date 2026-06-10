#include "spiral_matrix.h"

namespace spiral_matrix {
    std::vector<std::vector<uint32_t>> spiral_matrix(int spiral_size)
    {
        std::vector<std::vector<uint32_t>> result(spiral_size, std::vector<uint32_t>(spiral_size, 0));

        int top_row = 0;
        int bottom_row = spiral_size - 1;
        int left_col = 0;
        int right_col = spiral_size - 1;
        uint32_t fill_number = 1;

        while(fill_number <= static_cast<uint32_t>(spiral_size * spiral_size)) {
            for(int column = left_col; column <= right_col; column++) {
                result[top_row][column] = fill_number++;
            }

            top_row += 1;

            for(int row = top_row; row <= bottom_row; row++) {
                result[row][right_col] = fill_number++;
            }

            right_col -= 1;

            for(int column = right_col; column >= left_col; column--) {
                result[bottom_row][column] = fill_number++;
            }

            bottom_row -= 1;
            
            for(int row = bottom_row; row >= top_row; row--) {
                result[row][left_col] = fill_number++;
            }

            left_col += 1;
        }

        return result;
    }
}  // namespace spiral_matrix
