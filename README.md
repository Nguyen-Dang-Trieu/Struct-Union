# Struct - Union


## Declare a *Struct* ?
**Refrence:** 
- https://www.programiz.com/c-programming/c-structures
- https://dev.to/its_srijan/structure-in-c-storage-pointers-functions-and-self-referential-structure-1gl3
  
**The syntax is as follows:**
~~~cpp
union structureName {
   type1 variable1;
   type2 variable2;
   ...
   type variable;
}; 
~~~
- For example:
~~~cpp
struct Person {
  char name[50];
  int citNo;
  float salary;
};
~~~

## Declare a *Union* ?
- The syntax is as follows
~~~cpp
union Unionname {
   type1 variable1;
   type2 variable2;
   ...
   type variable;
}; 
~~~
- For example:
~~~cpp
#include<stdio.h>

union Hardware
{
   float _cpu;
   short _ram;
   int	 _ssd;
};
int main()
{
   Hardware latop;
   h._cpu = 3.2f;
   h._ram = 256;
   h._ssd = 1024;
   return 0;
}
~~~


## Problem: *Structure Padding*
- Architecture of a computer processor is such a way that it can read 1 word from memory at a time.
- 1 word is equal to 4 bytes for 32 bit processor and 8 bytes for 64 bit processor. So, 32 bit processor always reads 4 bytes at a time and 64 bit processor always reads 8 bytes at a time => *This concept is very useful to increase the processor speed.*

 **Giả sử 2 ví dụ bên dưới sử dụng `prossesor là 32 bit`**.
Mỗi `Ô VUÔNG` là 1 byte.
 
`Ví dụ 1:`
~~~cpp
#include <stdio.h>

struct example_1 {
   char a; // 1byte
   char b; // 1byte
   int c;  // 4bybtes
};

int main()
{
   struct example_1 variable_name;
   printf("%d",sizeof(variable_name));
}
~~~

**Output:**
~~~cpp
8
~~~
<p align="center">
    <img src="./Images/Vi_du_1.png" width="700px" alt="">
</p>

`Ví dụ 2:`
~~~cpp
#include <stdio.h>

struct example_2 {
   char a;  // 1byte
   int b;   // 4byte
   char c;  // 1bybtes
};

int main()
{
   struct example_2 variable_name;
   printf("%d",sizeof(variable_name));
}
~~~

**Output:**
~~~cpp
12
~~~
<p align="center">
    <img src="./Images/Vi_du_2.png" width="700px" alt="">
</p>

## Cách để tránh Padding trong struct
Sử dụng `__attribute__((packed))`.

**Example:**
~~~c
#include <stdio.h>
#include <stdint.h>

struct MyStruct1 {
    uint8_t a;    // 1 byte
    uint16_t b;   // 2 bytes
    uint32_t c;   // 4 bytes
};

struct MyStruct2 {
    uint8_t a;    // 1 byte
    uint16_t b;   // 2 bytes
    uint32_t c;   // 4 bytes
} __attribute__((packed));

int main() {
    struct MyStruct1 s1;
    struct MyStruct2 s2;

    printf("Size of MyStruct1 (without packed): %lu bytes\n", sizeof(struct MyStruct1));
    printf("Address of s1.a: %p\n", (void*)&s1.a);
    printf("Address of s1.b: %p\n", (void*)&s1.b);
    printf("Address of s1.c: %p\n", (void*)&s1.c);

    printf("\nSize of MyStruct2 (with packed): %lu bytes\n", sizeof(struct MyStruct2));
    printf("Address of s2.a: %p\n", (void*)&s2.a);
    printf("Address of s2.b: %p\n", (void*)&s2.b);
    printf("Address of s2.c: %p\n", (void*)&s2.c);

    return 0;
}
~~~
**Output:**
~~~
Size of MyStruct1 (without packed): 8 bytes
Address of s1.a: 0x7ffe2e705230
Address of s1.b: 0x7ffe2e705232
Address of s1.c: 0x7ffe2e705234

Size of MyStruct2 (with packed): 7 bytes
Address of s2.a: 0x7ffe2e705229
Address of s2.b: 0x7ffe2e70522a
Address of s2.c: 0x7ffe2e70522c
~~~
## Phân tích asm cho việc sử dụng _attribute_((packed))
https://fastbitlab.com/microcontroller-embedded-c-programming-lecture-150-assembly-code-analysis-of-packed-and-non-packed-structure/

## Union chỉ được sử dụng vùng nhớ lưu 1 giá trị  tại 1 thời điểm 
Ví dụ:
Nếu ta khai báo 1 kiểu "union GPIO"
 ~~~cpp
include <stdio.h>

union GPIO {
  uint8_t INPUT;
  uint8_t OUTPUT;
};

int main()
{
  //PC13 là 1 chân GPIO (Port C) của stm32.
  union GPIO PC13;
  //Ta chỉ có thể sử dụng INPUT or OUTPUT tại 1 thời điểm (do kiểu union thì các biến thành viên dùng chunng 1 vị trí để lưu trữ).
  PC13.INPUT = 1 (or 0) // PC.OUTPUT = 1 or 0
  //Sau câu lệnh PC13.INPUT = 1 thì vùng nhớ Union sẽ chứa giá trị là 0x01.
    
  //Nếu sử dụng của 2 thì nó sẽ lưu giá trị của câu lệnh cuối cùng.
  PC13.INPUT = 1;
  PC13.OUTPUT = 0;
  //Sau 2 câu lệnh trên thì vùng nhớ Union sẽ chứa giá trị 0x00.
  return 0;
}

~~~
