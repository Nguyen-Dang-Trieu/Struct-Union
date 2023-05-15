# Tên Dự án

## Mục lục
- [Giới thiệu](#gioi-thieu)
- [Cài đặt](#cai-dat)
- [Sử dụng](#su-dung)
- [Đóng góp](#dong-gop)

## <a name="gioi-thieu"></a>Giới thiệu

Đây là dự án mẫu để minh họa cách tạo mục lục trong tệp README.

## <a name="cai-dat"></a>Cài đặt

Dưới đây là các bước để cài đặt dự án:

1. Clone repository về máy của bạn.
2. Chạy lệnh `npm install` để cài đặt các phụ thuộc.
3. Chạy lệnh `npm start` để khởi chạy ứng dụng.

## <a name="su-dung"></a>Sử dụng

Đây là cách sử dụng dự án:

1. Chạy ứng dụng bằng lệnh `npm start`.
2. Mở trình duyệt và truy cập `http://localhost:3000` để xem ứng dụng.

## <a name="dong-gop"></a>Đóng góp

Nếu bạn muốn đóng góp vào dự án, hãy làm theo các bước sau:

1. Fork repository này.
2. Tạo một nhánh mới.
3. Thực hiện các thay đổi.
4. Gửi yêu cầu Pull (Pull Request) từ nhánh của bạn.

# Struct-Union
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
