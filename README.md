# **C-basic**
Trần Minh Trí

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

**Mệnh đề if-else trong C** được sử dụng để kiểm tra một biểu thức điều kiện nào đó có đúng hay không, nếu đúng thì thực thi những câu lệnh bên trong khối lệnh if và ngược lại nếu sai thì nó sẽ bỏ qua những câu lệnh đó. Có ba dạng của câu lệnh if trong C.

- Mệnh đề if.
Mệnh đề if được sử dụng để kiểm tra giá trị dạng boolean của điều kiện. Khối lệnh sau if được thực thi nếu giá trị của điều kiện là True. **Chỉ có 0 là False, còn khác 0 đều là True**. Cú pháp:
```
if (condition) {  
  // khối lệnh này được thực thi nếu condition = true
}
```
VD: 
```c
#include <stdio.h>
#include <stdint.h>

int main()
{
    int test = 2;

    if (test)
    {
        printf("Test\n");
    }
    return 0;
}
```
- Ta thấy kết quả:
```
Test
```
- Mệnh đề if-else.
Mệnh đề if được sử dụng để kiểm tra giá trị dạng boolean của điều kiện. Khối lệnh sau if được thực thi nếu giá trị của điều kiện là True, nếu là False thì chỉ có khối lệnh sau else được thực hiện. Cú pháp:
```
if (condition) {  
  // khối lệnh này được thực thi nếu condition = true
} else {
  // khối lệnh này được thực thi nếu condition = false
}
```
VD: 
```c
#include <stdio.h>
#include <stdint.h>

int main()
{
    int test = 0;

    if (test)
    {
        printf("True\n");
    }
    else{
        printf("False\n");
    }
    return 0;
}
```
- Ta thấy kết quả:
```
False
```
- Mệnh đề if-elseif-else.
Mệnh đề if-elseif-else cũng kiểm tra giá trị dạng boolean của điều kiện. Nếu giá trị điều kiện if là True thì chỉ có khối lệnh sau if sẽ được thực hiện. Nếu giá trị điều kiện else if nào là True thì chỉ có khối lệnh sau if else đó sẽ được thực hiện… Nếu tất cả điều kiện của if và if else là False thì chỉ có khối lệnh sau else sẽ được thực hiện. Cú pháp:
```
if (condition1) {  
  // khối lệnh này được thực thi nếu condition1 = true
} else if (condition2) {
  // khối lệnh này được thực thi nếu condition1 = false và condition2 = true
...
} else {
  // khối lệnh này được thực thi nếu nếu tất cả những điều kiện trên = false
}
```
VD: 
```c
#include <stdio.h>
#include <stdint.h>

int main()
{
    float a = 9;

    if (a >= 8.0)
    {
        printf("HOC SINH GIOI\n");
    }
    else if (a >= 6.5)
    {
        printf("HOC SINH KHA\n");
    }
    else if (a >= 5)
    {
        printf("HOC SINH TRUNG BINH\n");
    }
    else
    {
        printf("HOC SINH YEU\n");
    }
    return 0;
}
```
- Ta thấy kết quả:
```
HOC SINH GIOI
```