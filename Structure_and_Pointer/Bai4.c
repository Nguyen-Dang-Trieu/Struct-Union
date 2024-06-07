#include <iostream>
using namespace std;

struct Complex {
 int real;
 float img;
};

int main()
{
  // creating a Complex structure variable
  struct Complex var1[2];
  /* creating a pointer of Complex type &  assigning address of var1 to this pointer */
  struct Complex *ptr;
  ptr=var1;
  
  /* assigning values to Complex array var1 */
  var1[0].real = 5;
  var1[0].img = 0.33;
  var1[1].real = 7;
  var1[1].img = 0.56; 
 // accessing values of var1 using pointer    
 
 for(int i=0;i<2;i++){
 	cout << "Real part of  array element" << (i+1) <<" : " << (ptr+i)->real <<endl;
    cout << "Imaginary part of array element" << (i+1) <<" : " << (ptr+i)->img <<endl;
 }
  
 return 0;
}
