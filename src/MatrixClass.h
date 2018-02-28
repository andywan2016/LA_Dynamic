#ifndef MATRIXCLASS_H
#define MATRIXCLASS_H



#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Matrix{
   public:
      Matrix();//default constructor
      Matrix(int r,int c, string n);//constructor with row and column number, values are all zero
      Matrix(int r,int c, int** arry,string n);//constructor with row/col number, and with a 2D array
      ~Matrix();
      
      string name;
      int row;  //number of row
      int col;  //number of column
      int **array;   //=(int*)malloc(row*col*sizeof(int));
     // int get(int r,int c);
      void set(int r, int c ,int* num);
      void print();
      //operator overload for matrix multiputation`
      Matrix& operator*(const Matrix Mx);
      Matrix& operator=(const Matrix& Mx); 	   

};



#endif


