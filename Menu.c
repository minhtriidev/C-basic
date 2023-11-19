#include "lib.h"

/*----------------------Khai bao bien----------------------*/
int phim = 0;
float khoangCach, dienTich;

/*----------------------Khai bao ham-----------------------*/
int khoangCachGiuaHaiDiem(int x1, int y1, int x2, int y2);
int dienTichTamGiac(int x1, int y1, int x2, int y2, int x3, int y3);
void Menu();
void Menu2();
void xuLyMenu();

/*----------------------Ham chuc nang-----------------------*/
void Menu()
{
    do
    {
        printf("Chuong trinh toan hoc:\n");
        printf("1. Chuong trinh tinh khoang cach 2 diem\n");
        printf("2. Chuong trinh tinh dien tich tam giac\n");
        printf("0. Thoat\n");
        printf("Vui long chon:...");
        scanf("%d", &phim);
    }while (phim != 0 && phim != 1 && phim != 2);
    xuLyMenu();

}

void Menu2()
{
    do
    {   printf("\n");
        printf("1. Quay lai Menu chinh\n");
        printf("0. Thoat\n");
        printf("Vui long chon:...");
        scanf("%d", &phim);
    }while (phim != 0 && phim != 1);

    switch (phim)
    {
    case 1:
        Menu();
        break;
    default:
        break;
    }
}

void xuLyMenu()
{
    int x1, x2, x3, y1, y2, y3;

    switch (phim)
    {
    case 1:
        printf("Tinh khoang cach 2 diem:\n");
        printf("Vui long nhap:\n");
        printf("Toa do diem A(x1; y1)\n");
        printf("x1:...");
        scanf("%d", &x1);
        printf("y1:...");
        scanf("%d", &y1);

        printf("\n");
        printf("Toa do diem B(x2; y2)\n");
        printf("x2:...");
        scanf("%d", &x2);
        printf("y2:...");
        scanf("%d", &y2);

        printf("\n");
        khoangCachGiuaHaiDiem(x1, y1, x2, y2);
        printf("Khoang cach diem A(%d, %d) va B(%d, %d) = %.2f", x1, y1, x2, y2, khoangCach);
        Menu2();
        break;

    case 2:
        printf("Tinh dien tich hinh tam giac:\n");
        printf("Vui long nhap:\n");
        printf("Toa do diem A(x1; y1)\n");
        printf("x1:...");
        scanf("%d", &x1);
        printf("y1:...");
        scanf("%d", &y1);

        printf("\n");
        printf("Toa do diem B(x2; y2)\n");
        printf("x2:...");
        scanf("%d", &x2);
        printf("y2:...");
        scanf("%d", &y2);

        printf("\n");
        printf("Toa do diem C(x3; y3)\n");
        printf("x3:...");
        scanf("%d", &x3);
        printf("y3:...");
        scanf("%d", &y3);

        printf("\n");
        dienTichTamGiac(x1, y1, x2, y2, x3, y3);
        printf("Dien tich tam giac ABC = %.2f",  dienTich);
        Menu2();
        break;
    default:
        break;
    }
}

int khoangCachGiuaHaiDiem(int x1, int y1, int x2, int y2)
{
    khoangCach = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return khoangCach;
}

int dienTichTamGiac(int x1, int y1, int x2, int y2, int x3, int y3)
{
    dienTich = fabs((float)(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2);
    return dienTich;
}
