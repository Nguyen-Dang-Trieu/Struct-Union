/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 File: Part.c
    This program reads and prints inventory data for a part.
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <stdio.h>

struct inventory{
    int part_no;
    float cost;
    float price;
};

void read_part(struct inventory * partptr);
void print_part(struct inventory * partptr);

int main(){
    struct inventory item;
    
    printf("***Part Inventory Data***\n\n");
    read_part(&item);
    print_part(&item);
}

/* Prints data for a single part pointed to by partptr. */
void print_part(struct inventory * partptr){
    /* Method 1
    printf("Part no. = %d, Cost = %5.2f, Retail price = %5.2f\n",
          (*partptr).part_no, (*partptr).cost, (*partptr).price); */
          
    // Method 2  
    printf("Part no. = %d, Cost = %5.2f, Retail price = %5.2f\n",
          partptr->part_no, partptr->cost, partptr->price);      
}

/* Reads data for a single part into an object pointed to by partptr. */

void read_part(struct inventory * partptr){
    int n;
    float x;
    struct inventory part; 
    printf("Part Number: "); scanf("%d",&n);
    (*partptr).part_no = n;
    
    printf("Cost: "); scanf("%f", &x);
    (*partptr).cost = x;
    
    printf("Price: "); scanf("%f", &x);
    (*partptr).price = x;
     
}
