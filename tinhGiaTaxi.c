#include <stdio.h>
#include <stdint.h>

// tính giá taxi với yêu cầu như sau:
// giá mở cửa: 1km: 14,000VND
// nếu đi được 30km: 12,000VND 
// nếu đi được trên 30km: 10,000VND

int main(){

    float km, price = 0;
    printf("Nhap vao so km: ");
    scanf("%f", &km);

    if (km <= 1){
        price = 14000;
    }
    else if(km <= 30){
        price = 14000 + (km - 1) * 12000;
    }
    else{
        price = 14000 + 29 * 12000 + (km - 29 - 1) * 10000;
    }

    printf("So tien phai thanh toan: %.0f VND", price);
    return 0;
}