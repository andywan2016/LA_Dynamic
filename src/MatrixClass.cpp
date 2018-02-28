#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include "MatrixClass.h"

using namespace std;
/*
the default constructor of matrix, row and col number default to be 2

*/
Matrix::Matrix(){
   
   
   cout<<"default constructor\n";
   this->row=2;
   this->col=2;
   this->name="system generated";
  /*
   this->array=new int*[2];
   this->array[0]=new int[2]();
   this->array[1]=new int[2]();
*/
   }





// constructor with row and column numbers
Matrix::Matrix(int r, int c,string n){
   this->name=n;
   cout<<"second constructor of "<<this->name<<endl;
   
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

Matrix::Matrix(int r,int c, int** arry,string n){
   this->name=n;
   cout<<"third constructor of "<<this->name<<endl;
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
   //delete[] this->array[0];
  // delete[] this->array[1];
   
   //delete[] this->array;
   
   cout<<"deconstructor of "<<this->name<<" at:"<<this<<" array deleted at:"<<this->array<<endl;  
  
   for(int i=0;i<this->row;i++)
   {
      if(array[i])
      {delete[] this->array[i];}
   // this->array[i]=NULL;
   }
   //free(this->array);
   if(this->array)
   {delete[] this->array;}
  
   // this->array=NULL;
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


Matrix& Matrix::operator=(const Matrix& Mx){

   
   cout<<"assingment operator overloaded\n";
   
   
   //delete original data part, free the heap memory first
  /*
   for(int i=0;i<this->row;i++){
   delete[] this->array[i];
   }
   delete[] this->array;
*/
/*
 Below part starts to reconstructing new matrix object
 */


   
   this->col=Mx.col;
   this->row=Mx.row;
   this->array=new int*[this->col]();

   for(int i=0;i<this->row;i++){
      this->array[i]=new int[this->col]();
   
   }

   for(int i=0;i<this->row;i++){
      memcpy(this->array[i],Mx.array[i],sizeof(int)*(this->col));
   }
     
   return *this;
}

Matrix& Matrix::operator*( const Matrix Mx){
  /*
   if(this->col!=Mx.row)
   {
      cout<<"column must be equal to row number!\n";
      return Matrix(1,1,"*generated");
   }
   cout<<this->row<<endl;
   cout<<Mx.col<<endl;
   */
  // Matrix output(this->row,Mx.col,"*generated");
  // cout<<"new matrix address is:"<<&output<<endl;
   cout<<"-----------------------"<<endl;
  
   int **pt=new int*[this->row];
   for(int i=0;i<this->row;++i){
      pt[i]=new int[Mx.col]();
   }
   
   
   // output.print();
  // cout<<"---------------"<<endl;
   /*
    Below part code is wrong, indexing out of boundary
      */
   /*
   for(int i=0;i<this->row;i++){
      for(int j=0;j<Mx.col;j++){
      int sum=1;
        // *sum=0;
         
         for(int k=0;k<this->col;k++){
	 *sum=*sum+this->array[i][k]*Mx.array[k][j];
	 cout<<*sum<<endl;
	 }
	 
      output.set(i,j,&sum);
      }


   
   }
*/ 
   
  // Matrix output(this->row,Mx.col,pt,"*generated");
   
   Matrix *output=new Matrix;
   output->array=pt;
   
   return *output;
}



void Matrix::set(int r,int c, int* num){
   
   memcpy(array[r]+c,num,sizeof(int));
   //this->array[r][c]=num;

}







