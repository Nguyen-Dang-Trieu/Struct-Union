## Pointer to Data Unions

~~~cpp
#include <stdio.h>
#include <string.h>

// Define a union containing various data types
union Data {
    int i;
    float f;
    double d;
    char str[13];
};

int main() {
    // Declare a union variable
    union Data data;

    // Print the size of the union
    printf("Size of union Data: %lu bytes\n", sizeof(data));

    // Declare a pointer to the union
    union Data *ptr = &data;

    // Use a pointer to manipulate the members of the union
    ptr->i = 42;
    printf("\nValue of data.i: %d\n", ptr->i);

    ptr->f = 3.14f;
    printf("Value of data.f: %f\n", ptr->f);

    ptr->d = 2.71828;
    printf("Value of data.d: %lf\n", ptr->d);

    strcpy(ptr->str, "Hello World!");
    printf("Value of data.str: %s\n", ptr->str);

    // Print the addresses of the members in the union
    printf("\nAddress of data.i: %p\n", (void*)&data.i);
    printf("Address of data.f: %p\n", (void*)&data.f);
    printf("Address of data.d: %p\n", (void*)&data.d);
    printf("Address of data.str: %p\n", (void*)&data.str);

    return 0;
}
~~~
**Output**:
~~~cpp
Size of union Data: 16 bytes

Value of data.i: 42
Value of data.f: 3.140000
Value of data.d: 2.718280
Value of data.str: Hello World!

Address of data.i: 0x7fffa44ed0a0
Address of data.f: 0x7fffa44ed0a0
Address of data.d: 0x7fffa44ed0a0
Address of data.str: 0x7fffa44ed0a0
~~~
