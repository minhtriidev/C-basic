# **C-basic**
TRẦN MINH TRÍ

Lịch học: thứ 3, 7; 8:9 pm
## **Lesson 1: Biến và Hàm** 
Ngày: 7/11/2023
### **Biến**
- Các biến nguyên thủy: float, double....
- Trong ngành Nhúng ta sử dụng thư viện "stdint" để định nghĩa lại.
- Thư viện "stdio.h" giao tiếp với màn hình console (standard input output).
- Để xác định kích thước của biến ta dùng hàm sizeof(). Lưu ý đối kích thước ta truyền với kiểu %lu. VD:
```c
#include <stdio.h>
#include <stdint.h>
uint8_t var; 
int main() {
    printf("size: %lu byte", sizeof(var));
    return 0;
}
```
- Ta thấy kết quả: 

>size: 1 byte

- Định nghĩa "uint8_t" trong thư viện "stdint.h"

>typedef unsigned char uint8_t;

unsigned: số dương.

unit8_t là kiểu số nguyên dương.

Kích thước 1 byte = 8 bit ~ phạm vi [0 - 255].

VD: 
```c
#include <stdio.h>
#include <stdint.h>

uint8_t var; // 8 bit = 1 byte ~ 2^8 = 256  0-255


int main() {
  var = 256;
  printf("size: %lu byte\n", sizeof(var));

  printf("var = %d\n", var);
  return 0;
}
```
- Ta thấy kết quả:
```
lesson_1.c:8:9: warning: large integer implicitly truncated to unsigned type [-Woverflow]
   var = 256;
         ^~~
size: 1 byte
var = 0
```
- Định nghĩa "int8_t" trong thư viện "stdint.h".

unit8_t là kiểu số nguyên dương và âm.

Kích thước 1 byte = 8 bit ~ phạm vi [-128 - 127].

VD: 
```C
#include <stdio.h>
#include <stdint.h>

int8_t var; // 8 bit = 1 byte

int main() {
  var = 256;
  printf("size: %lu byte\n", sizeof(var));

  printf("var = %d\n", var);
  return 0;
}
```

- Ta có kết quả:
```
lesson1.c:8:9: warning: overflow in implicit constant conversion [-Woverflow]     
   var = 256;
         ^~~
size: 1 byte
var = 0
```

- Định nghĩa "int32_t" trong thư viện "stdint.h".

unit8_t là kiểu số nguyên dương và âm.

Kích thước 1 byte = 8 bit ~ phạm vi [-2^32 - 2^32-1].

- Trong lập trình Nhúng ta không dùng kiểu:

>int: kiểu số nguyên, kích thước 4 byte khi kiến trúc 64 bit còn nếu 2 byte với kiến trúc 32 bit. Vì thế người ta không thể dùng cho các chip khác nhau. 

- Định nghĩa float: kiểu số thực, kích thước 4 byte.
- Định nghĩa double: kiểu số thực, kích thước 8 byte. 

- Trong lập trình nhúng bộ nhớ giới hạn nên việc khai báo biến cực kì cẩn thận.

**Hàm**

VD: Hàm không trả về
```C
#include <stdio.h>
#include <stdint.h>

void hienThi(uint16_t id, char* ten, uint8_t tuoi){

    printf("ID: %d, TEN: %s, TUOI: %d\n", id, ten, tuoi);

}
int main() {
    
    // printf("ID: 1001, TEN: HOANG, TUOI: 19\n");
    // printf("ID: 1001, TEN: TUAN, TUOI: 14\n");
    // printf("ID: 1001, TEN: QUAN, TUOI: 148\n");
    // printf("ID: 1001, TEN: NAM, TUOI: 17\n");
    hienThi(1000, "Hoang", 19);
    return 0;
}
```
- Ta thấy kết quả:
```
ID: 1000, TEN: Hoang, TUOI: 19
```
VD: Hàm trả về giá trị kiểu "**uint8_t**"
```C
#include <stdio.h>
#include <stdint.h>

uint8_t tong(uint8_t a, uint8_t b){
    return a+ b;
}


int main() {

    printf("Tong a + b = %d\n", tong(7, 8));
    return 0;
}
```
- Ta thấy kết quả:
```
Tong a + b = 15
```

VD: Hàm trả về giá trị kiểu "**float**"
```c
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

```
- Ta thấy kết quả:
```
Thuogn a / b = 0.875000
```

**Tính chất hàm:**
- Hàm có thể có hoặc không có tham số.
- Có sự lặp đi lặp lại nhiều lần

## **Lesson 2: Câu điều kiện: if else và switch case** 

VD: 
```


```
