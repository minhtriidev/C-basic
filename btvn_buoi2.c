#include <stdio.h>
#include <stdint.h>

#define HINH_CHU_NHAT 1
#define HINH_VUONG 2
#define HINH_TAM_GIAC_VUONG_CAN 3


void hinhChuNhat(int chieuDai, int chieuRong){
    for(int i=1; i<=chieuDai; i++){
        for(int j=1; j<=chieuRong; j++){
            if(i==1 || i==chieuDai || j==1 || j==chieuRong){
                printf("*  ");
            }
            else{
                printf("   ");
            }
        }
        printf("\n");
    }
}

void hinhVuong(int canh){
    for(int i=1; i<=canh; i++){
        for(int j=1; j<=canh; j++){
            if(i==1 || i==canh || j==1 || j==canh){
                printf("*  ");
            }
            else{
                printf("   ");
            }
        }
        printf("\n");
    }
}

// void hinhTamGiacVuongCan(int canhBen){
//     for(int i=1; i<=canhBen; i++){
//         for(int j=1; j<=canhBen; j++){
//             if(i==1 || j==canhBen || i==j){
//                 printf("*  ");
//             }
//             else{
//                 printf("   ");
//             }
//         }
//         printf("\n");
//     }
// }

void hinhTamGiacVuongCan(int canhBen){
    for (int i=canhBen; i>=1; i--){
        for (int j=canhBen; j>=1; j--){
            if (i==1 || j==canhBen || i==j){
                printf("*  ");
            } else{
                printf("   ");
            }
        }
        printf("\n");
    }
}


int main(){

    int loaiHinh, chieuDai, chieuRong, canh, canhBen;
    printf("Menu: \n1. Hinh chu nhat \n2. Hinh vuong \n3. Hinh tam giac vuong can \nMoi chon loai hinh: ");
    scanf("%d", &loaiHinh);

    switch (loaiHinh)
    {
    case HINH_CHU_NHAT:
        printf("Ban chon Hinh chu nhat, vui long nhap: \n");
        printf("Chieu dai (cot): ");
        scanf("%d", &chieuDai);
        printf("Chieu rong (hang): ");
        scanf("%d", &chieuRong);
        hinhChuNhat(chieuDai, chieuRong);
        break;

    case HINH_VUONG:
        printf("Ban chon Hinh vuong, vui long nhap: \n");
        printf("Canh: ");
        scanf("%d", &canh);
        hinhVuong(canh);
        break;

    case HINH_TAM_GIAC_VUONG_CAN:
        printf("Ban chon Hinh tam giac vuong can, vui long nhap: \n");
        printf("Canh ben: ");
        scanf("%d", &canhBen);
        hinhTamGiacVuongCan(canhBen);
        break;

    default:
        printf("So ban chon khong hop le");
        break;
    }

    return 0;
}