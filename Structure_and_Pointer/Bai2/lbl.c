/* File: lbl.c
   Other Source Files: lblutil.c
   Header Files: lbl.h, lblutil.h
   This program reads and prints data for on lable */

#include <stdio.h>
#include "lbl.h"
#include "lblutil.h"

int main(){
    struct label person;

    printf("***Label Data for a Person***\n\n");
    readlabel(&person);
    printf("\nLabel Data:\n");
    printlabel(&person);
}
