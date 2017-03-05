#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 65536

int matrixmul(int arr[],int,int);


int main(){
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int value;
	value = matrixmul(arr,1,9);
	printf("The lowest number of the scalar multiplication is: %d\n",value);
	
	return 0;
}


int matrixmul(int arr[],int i,int j){

	if(i==j){
		return 0;		
	}
	int n,temp;
	int min = MAX;

	for(n=i;n<j;n++){
		
		temp = matrixmul(arr,i,n) + matrixmul(arr,n+1,j) + arr[n-1]*arr[n]*arr[j]; 
		printf("Matrix scalar multiplication value for i = %d, j = %d, k = %d is %d\n",i,j,n,temp);
		if(temp<min){
			min = temp;
		}
		
				
		
	}
	
	return min;
	

}
