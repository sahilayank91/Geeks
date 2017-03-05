/* This is the program to implement the min cost path dynamic problem */

#include<stdio.h>
#include<stdlib.h>


int min(int a, int b, int c){

	if(a<b){
		return a<c?a:c;
	}else{
		return b<c?b:c;
	}
}

/* Here we can input the i and j so that we can ask user from which coordinate you want to take the minimum cost  instead of self initializing from (1,1)*/


int mincostpath(int arr[3][3],int m, int n){
	
	
	int mc[3][3];       // array to store the cummulative added cost
	int i,j;
	
	mc[0][0] = arr[0][0];
	
	
	/* this method works on the principle of cummulative addition of the cost in the path occured*/
	
	for(i=1;i<=m;i++){
		mc[i][0] = mc[i-1][0] + arr[i][0];
	}
	
	for(i=1;i<=n;i++){
		mc[0][i] = mc[0][i-1] + arr[0][i];
	}
	
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			mc[i][j] = arr[i][j] + min(mc[i-1][j-1],mc[i][j-1],mc[i-1][j]);
		}
	}
	return mc[m][n];					// the minimum is always at the last element when doing dynamic programming*/
}



int main(){
	int arr[3][3] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
	
	printf("The minimum cost to reach 9 is: %d\n",mincostpath(arr,2,2));




return 0;
}
