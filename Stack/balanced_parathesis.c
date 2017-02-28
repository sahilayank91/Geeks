#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

int ismatch(char a, char b){

	if(a=='(' && b==')') return 1;
	if(a=='{' && b=='}') return 1;
	if(a=='[' && b==']') return 1;
	else return 0;
}

void check(char *exp){
	
	int i;
	int len = strlen(exp);
	for(i=0;i<len;i++){
		if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
			push(exp[i]);
		}
		if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
			char b = pop();	
			if(ismatch(b,exp[i])){
				continue;
			}			
			else{
				printf("Paranthesis not in a correct sequence..\n");
				break;
			}
		}

	}

	if(s.top==-1){
		printf("Paranthesis are balanced..\n");
	}else{
		printf("Paranthesis not balanced\n");
	}

}

int main(){

	char exp[]="{()}[]";
	int len = strlen(exp);
	createstack(len);
	check(exp);
return 0;
}
