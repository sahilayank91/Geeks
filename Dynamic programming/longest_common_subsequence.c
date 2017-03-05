#include<stdio.h>
#include<stdlib.h>
#include<string.h>



/*Function to calculate the maximum of two integers*/

int max(int a,int b){
return (a>b)?a:b;
}


int lcs(char *x,char *y,int a, int b){

	int arr[a+1][b+1];
	int lp[a+1][b+1];
	int i,j; 
	char cs[a];
	int n=0;
	
	
	/*Appliying the dynamic solution for the lcs problem*/
	
	for(i=0;i<=a;i++){
		
		for(j=0;j<=b;j++){
			
			if(i==0 || j==0){
				arr[i][j]=0;
				lp[i][j]=0;
			}
			
			else if(x[i] == y[j]){
				arr[i][j]=1+arr[i-1][j-1];
				lp[i][j] = 1;
			}
			else if(x[i] != y[j]){
				arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
				if(arr[i-1][j]>=arr[i][j-1]){
					lp[i][j]=2;
				}else{
					lp[i][j]=3;
				}
			}
			
	/* For testing and getting the values of arr*/		
			
			printf("arr[%d][%d] = %d\n",i,j,arr[i][j]);
			
		}
		
	}
	
	i=a,j=b;
	
	
	while(lp[i][j]!=0){
		
		if(lp[i][j]==1){
			//printf("lp[%d][%d] = %d \n",i,j,lp[i][j]);
			cs[n]=x[i-1];
			n++;
			i=i-1;
			j=j-1;
			
		}
		
		else if(lp[i][j]==2){
			i=i-1;
		}
		
		else if(lp[i][j]==3){
			j=j-1;
		}
		
	}
	
	
	printf("The longest common subsequence is: ");
	for(i=n-1;i>=0;i--){
		printf("%c",cs[i]);
	}
	printf("\n");
	
return arr[a][b];
}



int main(){
	char x[50];
	char y[50];
	
	printf("Enter the first sequence..\n");
	scanf("%s",x);
	fflush(stdin);
	printf("Enter the second sequence..\n");
	scanf("%s",y);
	
	/*Getting the length of the string*/
	
	int p = strlen(x);
	int q = strlen(y);
	
	printf("The longest length of the common subsequence is: %d\n",lcs(x,y,p,q));
	
return  0;
}

