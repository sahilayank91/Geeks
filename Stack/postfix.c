#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

struct stack{
	int top;
	unsigned cap;
	int *arr;
};

struct stack s;

void push(int data){
	if(s.top+1==s.cap)	{
		printf("Stack Full\n");
		return;
	}
	
	s.top++;
	s.arr[s.top] = data;
}



int pop(){
	if(s.top==-1){
		printf("Stack empty\n");
		return 0;
	}
	
	
	int a = s.arr[s.top];
	s.top--;
	return a;
}

int isEmpty(){
	if(s.top==-1){
	return 1;
	}else return 0;
}




void createstack(unsigned capacity){
	
	s.arr = (int *)calloc(capacity,sizeof(int));
	s.cap = capacity;
	s.top=-1;
} 




int evaluateexpression(char *exp){
	
	int len = strlen(exp);
		
	createstack(len);
	int i,j,k;

	for(i=0;i<len;i++){
		if(isdigit(exp[i])) 
		{
			j = exp[i]-48;
			printf("%d pushed\n",j);
			push(j);			
		
		}else{
			int a = pop();
			int b = pop();
	
			
			switch(exp[i])
			{
				case '+': push(a+b);	break;
				case '-': push(b-a);	break;
				case '*': push(a*b);    break;
				case '/': push(b/a);	break;
				default : printf("Not a valid expression..\n");					
			}			
		
		}
		
	
	}
	
	
	return pop();	
	
}

int main(){
	
	char exp[] ="231*+9-";
	
	printf("Value of postfix expression %s  is  %d",exp,evaluateexpression(exp));
return 0;
}
