#include<stdio.h>

struct store{
    double price;           
    union {
        struct 
        {
            char *title;    
            char *author;   
            int num_pages;  
        } book;

        struct 
        {
            int color;      
            int size;       
            char *design;   
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
    
    printf("\nSize of struct store: %d bytes\n",sizeof(struct store)); // Output: Size of struct store: 24 bytes

    //Hien thi ra man hinh
    printf("\n-Title: %s\n",s.items.book.title);
    printf("-Author: %s\n",s.items.book.author);
    printf("-Num_pages: %d\n",s.items.book.num_pages);
    printf("-Price: %0.2f\n",s.price);printf("\n");

    return 0;
}