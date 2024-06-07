#include <stdio.h>
#include "lbl.h"
#include "lblutil.h"

#define FALSE 0
#define TRUE  1

/* This routine prints the label data */
void printlabel(struct label * pptr){
    printf("\n%s %s %s\n%s\n%s %s %ld\n",
            pptr->name.first,
            pptr->name.middle,
            pptr->name.last,
            pptr->address.street,
            pptr->address.city,
            pptr->address.state,
            pptr->address.zip);  
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
    fgets(pptr->address.street, sizeof(pptr->address.street), stdin);  
    printf("Enter City State Zip: ");
    scanf("%s %s %ld%*c",pptr->address.city,
                         pptr->address.state,
                         &pptr->address.zip);  
    return TRUE;
}
