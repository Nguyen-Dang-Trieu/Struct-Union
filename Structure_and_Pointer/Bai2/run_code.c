#include <stdio.h>
#define FALSE 0
#define TRUE  1

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
};  

void printlabel(struct label * personptr);
int readlabel(struct label * personptr);

int main(){
    struct label person;

    printf("***Label Data for a Person***\n\n");
    readlabel(&person);
    printf("\nLabel Data:\n");
    printlabel(&person);
}

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

int readlabel(struct label * pptr){
    int x;

    printf("Enter Name <First Middle Last>, EOF to quit: ");
    x = scanf("%s %s %s%*c",pptr->name.first,
                            pptr->name.middle,
                            pptr->name.last);
    if(x == EOF) 
        return FALSE;
    printf("Enter Street Address: ");
    fgets(pptr->address.street, sizeof(pptr->address.street), stdin);  
    printf("Enter City State Zip: ");
    scanf("%s %s %ld%*c",pptr->address.city,
                         pptr->address.state,
                         &pptr->address.zip);  
    return TRUE;
}



