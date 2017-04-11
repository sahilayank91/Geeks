#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void searchPattern(char *text,char *pat){
	
int l1 = strlen(text);
int l2 = strlen(pat);

int i,j;

if(l2>l1){
		printf("Pattern is greater in length than that of the string ...\n");
		return;
}
for(i=0;i<=l1-l2;i++){
	
	for(j=0;j<l2;j++){
			if(text[i+j]!=pat[j]){
				break;
			}
	}
	if(j==l2){
		printf("Pattern found at the index is %d\n",i+1);
		return;			
	}		
}	
}

int main(){
	char text[100] = "My name is sahil ayank";
	char pat[100] = "name";
	searchPattern(text,pat);
return 0;	
}
