#include <stdio.h>

#define FALSE 0
#define TRUE  1

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 File: lbl.h
    This file contains structure tags for labels. Label has two members, name and address
    , each of which is a structure type.
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct name_recd {
    char last[15];
    char first[15];
    char middle[15];
};

struct addr_recd {
    char street[25];
    char city[15];
    char state[15];
    long zip;
};

struct label {
    struct name_recd name;
    struct addr_recd address;
};  // <- Thêm dấu chấm phẩy ở đây

// File: lblutil.h
void printlabel(struct label * personptr);
int readlabel(struct label * personptr);

int main(){
    struct label person;

    printf("***Label Data for a Person***\n\n");
    readlabel(&person);
    printf("\nLabel Data:\n");
    printlabel(&person);
}

/* This routine prints the label data */
void printlabel(struct label * pptr){
    printf("\n%s %s %s\n%s\n%s %s %ld\n",
            pptr->name.first,
            pptr->name.middle,
            pptr->name.last,
            pptr->address.street,
            pptr->address.city,
            pptr->address.state,
            pptr->address.zip);  // <- Thêm dấu phẩy ở đây
}

/* This routine reads the label data. */
int readlabel(struct label * pptr){
    int x;

    printf("Enter Name <First Middle Last>, EOF to quit: ");
    x = scanf("%s %s %s%*c",pptr->name.first,
                            pptr->name.middle,
                            pptr->name.last);
    if(x == EOF)  // <- Sửa thành x == EOF
        return FALSE;
    printf("Enter Street Address: ");
    fgets(pptr->address.street, sizeof(pptr->address.street), stdin);  // <- Sử dụng fgets thay cho gets
    printf("Enter City State Zip: ");
    scanf("%s %s %ld%*c",pptr->address.city,
                         pptr->address.state,
                         &pptr->address.zip);  // <- Sử dụng &pptr->address.zip
    return TRUE;
}



