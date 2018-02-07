#ifndef MATRIXCLASS_H
#define MATRIXCLASS_H



#include <iostream>
#include <stdlib.h>



class Matrix{
   public:
      Matrix(int r,int c); //defualt constructor
      Matrix(int r,int c, int** arry);
      ~Matrix();

      int row;  //number of row
      int col;  //number of column
      int **array;   //=(int*)malloc(row*col*sizeof(int));
     // int get(int r,int c);
      void set(int r, int c ,int* num);
      void print();
      //operator overload for matrix multiputation`
      Matrix operator*(Matrix Mx);


};



#endif


