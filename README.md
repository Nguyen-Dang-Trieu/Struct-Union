# Struct - Union

## Contents
- [Introduction](#Introduction)
  - [Struct](#Struct-Intr)
  - [Union](#Union)
- [How to declare and use them in C](#Declare)
  - [How to Declare a Struct?](#Struct-D)
  - [How to Declare a Union?](#Union-D)
- [How to access members of Struct - Union](#su-dung)
  - [Struct](#cach-1)
  - [Union](#cach-2)
- [Examples and applications of Struct - Union](#dong-gop)
  - [Struct](#yeu-cau)
  - [Union](#quy-trinh-dong-gop)


- [Giới thiệu](#gioi-thieu)
- [Cài đặt](#cai-dat)
- [Sử dụng](#su-dung)

## Giới thiệu<a name="gioi-thieu"></a>
Đây là một dự án mã nguồn mở thú vị...

## Cài đặt<a name="cai-dat"></a>
Hướng dẫn cài đặt...

## Sử dụng<a name="su-dung"></a>
Hướng dẫn sử dụng...


## <a name="Introduction"></a>Introduction
Đây là dự án mẫu để minh họa cách tạo mục lục trong tệp README. Dưới đây là các mục con trong phần Giới thiệu:

### <a name="Struct-Intro"></a> Struct
Nội dung mục 1...

### <a name="Union"></a> Union
Nội dung mục 2...

## <a name="Declare"></a>How to declare and use them in C
Dưới đây là các bước để cài đặt dự án. Bạn có thể tạo các mục con tương tự như trong phần Giới thiệu:

### <a name="Struct-D"></a>How to Declare a Struct?
Nội dung bước 1...

### <a name="Union-D"></a>How to Declare a Union?
Nội dung bước 2...

## <a name="su-dung"></a>Sử dụng
Đây là cách sử dụng dự án. Cũng tương tự như các phần trước, bạn có thể tạo các mục con cho phần này:

### <a name="cach-1"></a>Cách 1
Nội dung cách 1...

### <a name="cach-2"></a>Cách 2
Nội dung cách 2...

## <a name="dong-gop"></a>Đóng góp
Nếu bạn muốn đóng góp vào dự án, hãy làm theo các bước sau. Bạn cũng có thể tạo các mục con như đã thực hiện trong các phần trước:

### <a name="yeu-cau"></a>Yêu cầu
Nội dung yêu cầu...

### <a name="quy-trinh-dong-gop"></a>Quy trình đóng góp
Nội dung quy trình đóng góp...


# Union chỉ được sử dụng vùng nhớ lưu 1 giá trị  tại 1 thời điểm 
Ví dụ:
Nếu ta khai báo 1 kiểu "union GPIO"
 ~~~cpp
include<stdio.h>

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
