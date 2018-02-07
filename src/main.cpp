#include <iostream>
#include <stdlib.h>  
#include "MatrixClass.h"


using namespace std;

int main(){
   Matrix test(2,3);
  // test.set(0,1,3);
  // test.print();  
   
   int input[2][3]={{1,2,3},{4,5,6}};
   
   int** pt1=new int*[2];
   pt1[0]=input[0];
   pt1[1]=input[1];

   Matrix test1(2,3,pt1);
   
   //test.array[0]=input[0];

   //test.print();
   test1.print();
   
   delete[] pt1;
   
   int input1[3][2]={{1,2},{3,4},{5,6}};
   int **pt2=new int*[3];

   pt2[0]=input1[0];
   pt2[1]=input1[1];
   pt2[2]=input1[2];

   Matrix test2(3,2,pt2);
   
   test2.print();

   delete[] pt2;

   Matrix result=test1*test2;
   result.print();

   /*
   int (*pt)[3];
   pt[0]=input[0];
   pt[1]=input[1];


   Matrix test1(2,3,pt);
   test1.print();
  */
   return 0;

}
