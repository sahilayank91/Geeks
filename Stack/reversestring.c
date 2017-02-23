#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stack{
	int top;
	unsigned capacity;
	char *arr;
};


struct stack s;

void push(char a){
	if(s.top+1==s.capacity) {
		printf("Stack full\n");
		return;
	}
	
	s.top++;
	s.arr[s.top] = a;
}

char pop(){
	if(s.top==-1){
	printf("Stack empty\n");
	return '\0';
	}
	
	char p = s.arr[s.top];
	s.top--;
	return p;
}

void createstack(unsigned cap){


	s.arr = (char *)calloc(cap,sizeof(char));
	s.capacity = cap;
	s.top=-1;	


}


void reversestring(char *exp){
	int i;
	
	int len = strlen(exp);
	createstack(len);
	
	for(i=0;i<len;i++){
		push(exp[i]);
	}	

	for(i=0;i<len;i++){
		printf("%c",pop(exp[i]));
	}
	printf("\n");	
}

int main(){
	
	char exp[]="Hello Deepshi aaj to mast lage chu";
	reversestring(exp);
return 0;
}


