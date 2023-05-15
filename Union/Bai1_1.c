#include<stdio.h>

#pragma pack(1)

/* Khi bạn sử dụng #pragma pack(1), bạn đang yêu cầu trình biên dịch không thêm bất kỳ byte trống (padding) nào 
vào giữa các thành phần của cấu trúc. Thay vào đó, các thành phần sẽ được căn chỉnh liền kề nhau, với kích thước
tối thiểu cần thiết.
   Việc sử dụng #pragma pack(1) có thể giúp tối ưu kích thước bộ nhớ và đảm bảo tính nhất quán trong việc truy cập
và trao đổi dữ liệu.
   Tuy nhiên, cần lưu ý rằng việc loại bỏ padding có thể ảnh hưởng đến hiệu suất của chương trình, do truy cập
vào các thành phần của cấu trúc có thể chậm hơn nếu các thành phần không được căn chỉnh tối ưu cho kiến trúc của
máy tính. Điều này đặc biệt quan trọng đối với các kiến trúc bộ nhớ yêu cầu dữ liệu phải căn chỉnh đúng.*/
struct store{
    double price;            // 8 bytes
    union {
        struct 
        {
            char *title;    // 4 bytes
            char *author;   // 4 bytes
            int num_pages;  // 4 bytes
        } book;

        struct 
        {
            int color;      // 4 bytes
            int size;       // 4 bytes
            char *design;   // 4 bytes
        } shirt;
    } items;
};

int main()
{
    struct store s;
    s.items.book.title = "The 7 habits of highly effective people";
    s.items.book.author = "Stephen Covey";
    s.items.book.num_pages = 350;
    s.price = 10;
    
    printf("\nSize of struct store: %d bytes\n",sizeof(struct store)); // Output: Size of struct store: 20 bytes

    //Hien thi ra man hinh
    printf("\n-Title: %s\n",s.items.book.title);
    printf("-Author: %s\n",s.items.book.author);
    printf("-Num_pages: %d\n",s.items.book.num_pages);
    printf("-Price: %0.2f\n",s.price);printf("\n");

    return 0;
}