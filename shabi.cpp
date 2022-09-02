#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define return_hex(a) ((a >= 97) ? (a - 97 + 10) : (a - 48))
#define return_base64(a) (((a < 26) ? 1 : 0) == 1 ? (a + 65) : (((a < 52) ? 1 : 0) == 1) ? (a + 97 - 26) : (((a < 62) ? 1 : 0) == 1) ? (a + 48 - 52) : (((a == 62) ? 1 : 0) == 1) ? 43 : 47)
#define check_not_equal(a, b) ((a == b) ? false : true)
char *convert_helper(uint8_t *hex_array, int n) {
    uint8_t mask1 = 252, mask2 = 240, mask3 = 192, c;
    char *base64 = (char*)malloc(sizeof(char) * n);
    int size = 0, temp = 0;
    for(int i = 0; i < n; i += 3, temp++) {
        if(check_not_equal(size++, n)) {
            c = (mask1 & hex_array[i]) >> 2;
            base64[temp * 4] = return_base64(c);
        }
        else
            break;
        if(check_not_equal(size++, n)) {
            c = (((255 - mask1) & hex_array[i]) << 4) | ((mask2 & hex_array[i + 1]) >> 4);
            base64[temp * 4 + 1] = return_base64(c);
        }
        else
            break;
        if(check_not_equal(size++, n)) {
            c = (((255 - mask2) & hex_array[i + 1]) << 2) | ((mask3 & hex_array[i + 2]) >> 6);
            base64[temp * 4 + 2] = return_base64(c);
        }
        else
            break;
        if(check_not_equal(size++, n)) {
            c = (255 - mask3) & hex_array[i + 2];
            base64[temp * 4 + 3] = return_base64(c);
        }
        else
            break;
    }    
    return base64;
}

char *convert_to_base64(char *hex_string, int n) {
    int size = ceil((n * 4) / 6.0);
    uint8_t *hex_binary_array = (uint8_t*)malloc(sizeof(char) * size);
    for(int i = 0; i < n; i += 2) {
        if(i == n - 1) {
            hex_binary_array[i / 2] = return_hex(hex_string[i]) << 4;
        }
        else {
            uint8_t first = return_hex(hex_string[i]), second = return_hex(hex_string[i + 1]);
            hex_binary_array[i / 2] = first << 4 | second;
        }
    }
    
    char *base64_string = convert_helper(hex_binary_array, size);
    free(hex_binary_array);
    return base64_string;
}

int main()
{

    
    char *string;

    string = convert_to_base64("fd347a67d1e", 11);
    printf("%s\n", string);
    return 0;
}