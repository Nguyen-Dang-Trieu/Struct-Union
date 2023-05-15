#include<stdio.h>

/*
  A store sells two kinds of items:
    1. Books
    2. Shirts
  Store owners want to keep records of the above mentioned items along with the relevant
  information.

  Book: Title, Author, number of pages, price
  Shirts: Color, size, design, price

*/
struct store
{
    double price;     // 8 bytes
    char *title;      // 4 bytes
    char *author;     // 4 bytes
    int num_pages;    // 4 bytes
    int color;        // 4 bytes
    int size;         // 4 bytes
    char *design;     // 4 bytes
};


int main()
{   
    struct store book;
    //Book variable doesn't possess these properties
    //Therefore, its a wastage of memory
    book.title = "The 7 habits of highly effective people";
    book.author = "Stephen Covey";
    book.num_pages = 350;
    book.price = 10;
    
    
    printf("\nSize of struct store: %d bytes\n",sizeof(struct store));

    //Hien thi ra man hinh
    printf("\n-Title: %s\n",book.title);
    printf("-Author: %s\n",book.author);
    printf("-Num_pages: %d\n",book.num_pages);
    printf("-Price: %0.2f\n",book.price);printf("\n");
    
    return 0;
}
