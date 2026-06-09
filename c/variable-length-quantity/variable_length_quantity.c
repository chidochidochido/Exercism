#include "variable_length_quantity.h"

int encode(const uint32_t *integers, size_t integers_len, uint8_t *output)
{
    int out_len = 0;
    for (size_t i = 0; i < integers_len; i++) {
        uint32_t val = integers[i];
        if (val == 0) {
            output[out_len++] = 0;
            continue;
        }
        
        uint8_t temp[5];
        int temp_len = 0;
        
        while (val > 0) {
            temp[temp_len++] = val & 0x7F;
            val >>= 7;
        }
        
        for (int j = temp_len - 1; j >= 0; j--) {
            uint8_t byte = temp[j];
            if (j > 0) {
                byte |= 0x80;
            }
            output[out_len++] = byte;
        }
    }
    return out_len;
}

int decode(const uint8_t *bytes, size_t buffer_len, uint32_t *output)
{
    int out_len = 0;
    uint32_t current_val = 0;
    int is_incomplete = 0;
    
    for (size_t i = 0; i < buffer_len; i++) {
        uint8_t byte = bytes[i];
        current_val = (current_val << 7) | (byte & 0x7F);
        
        if ((byte & 0x80) == 0) {
            output[out_len++] = current_val;
            current_val = 0;
            is_incomplete = 0;
        } else {
            is_incomplete = 1;
        }
    }
    
    if (is_incomplete) {
        return -1;
    }
    
    return out_len;
}
