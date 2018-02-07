#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "MatrixClass.h"

using namespace std;


//default constructor
Matrix::Matrix(int r, int c){
   this->row=r;
   this->col=c;
   
   this->array=new int*[this->row];

   for(int i=0;i<this->row;i++)
      {this->array[i]=new int[this->col]();}
      
      
      
     // [(this->row)*(this->col)];
   //this->array=(int*)malloc((this->row)*(this->col)*sizeof(int));
   
   /*
   for(int i=0;i<(this->row)*(this->col);i++)
   {
   this->array[i]=0;
   }
*/
}

Matrix::Matrix(int r,int c, int** arry){

   this->row=r;
   this->col=c;
   this->array=new int*[this->row];

   for(int i=0;i<this->row;i++){
      this->array[i]=new int[this->col]();  
   }
   for(int i=0;i<this->row;i++){
      memcpy(array[i],arry[i],sizeof(int)*c);
   }
}

//get value of array[r][c]

/*
int Matrix::get(int r,int c){


   return this->array[(this->col)*r+c];
}

*/
Matrix::~Matrix(){
   for(int i=0;i<this->row;i++)
   {delete[] this->array[i];}
   //free(this->array);
   delete this->array;
}


//function to print matrix  
void Matrix::print(){
   for(int i=0;i<this->row;i++){
      cout<<"|";
      for(int j=0;j<this->col-1;j++){
         cout<<this->array[i][j];
         cout<<",";
      }
      cout<<this->array[i][this->col-1];
      cout<<"|"<<endl;
   
   }
   
   
}


Matrix Matrix::operator*(Matrix Mx){
   if(this->col!=Mx.row)
   {
      cout<<"column must be equal to row number!\n";
      return Matrix(1,1);
   }

   Matrix output(this->row,Mx.col);
   for(int i=0;i<this->row;i++){
      for(int j=0;j<Mx.col;j++){
      int *sum;
         *sum=0;
         for(int k=0;k<this->col;k++){
	 *sum=*sum+this->array[i][k]*Mx.array[k][j];
	 }
      output.set(i,j,sum);
      }


   
   }

   return output;
}



void Matrix::set(int r,int c, int* num){
   
   memcpy(array[r]+c,num,sizeof(int));
   //this->array[r][c]=num;

}







