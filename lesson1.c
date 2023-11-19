/*
Ngày: 
*/
#include <stdio.h>
#include <stdint.h>

float thuong(uint8_t a, uint8_t b){
    if (b == 0)
        printf("ERROR!! Mau bang 0\n");
    return (float)a/b;
}


int main() {

    printf("Thuong a / b = %f\n", thuong(7, 8));
    return 0;
}


// int32_t var; // 8 bit = 1 byte

// int main() {
//   var = 256;
//   printf("size: %lu byte\n", sizeof(var));

//   printf("var = %d\n", var);
//   return 0;
// }