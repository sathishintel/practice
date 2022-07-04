/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void function(int (*arr)[3],int rows) {
    int i,j;
    for (i = 0; i < rows ;i++) {
	    for(j = 0 ; j < 3 ; j++) {
	        printf("%d ",arr[i][j]);
	    }
	    printf("\n");
    }

}


void function1(int *arr,int rows,int cols) {
    int i,j;
    printf("%s \n",__FUNCTION__);
    for (i = 0; i < rows ;i++) {
	    for(j = 0 ; j < cols ; j++) {
	        printf("%d ",*((arr + i*cols)+j));
	    }
	    printf("\n");
    }

}

void function2(int arr[][3],int rows) {
    int i,j;
    printf("%s \n",__FUNCTION__);
    for (i = 0; i < rows ;i++) {
	    for(j = 0 ; j < 3 ; j++) {
	        printf("%d ",arr[i][j]);
	    }
	    printf("\n");
    }

}

int main() {

    int arr[4][3] = {{1,2,3},{6,7,8},{9,11,23},{123,34,56}};

    /*pointer to an array
      means *Arr is array pointer 
      and *arr[3] pointer to an array of 3*/
    void (*func_p)(int (*arr)[],int rows);
    func_p = function;
    func_p(arr,4);
    
    /*below approch is using single pointer*/
    void (*func_p1)(int *arr,int rows, int cols);
    func_p1 = function1;
    func_p1((int *)arr,4,3);
    
    /*below approach is using arry */
    void (*func_p2)(int arr[][3],int rows);
    func_p2 = function2;
    func_p2(arr,4);
    
    
    return 0;

}



