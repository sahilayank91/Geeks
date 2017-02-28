#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct stack{
	int top1,top2;
	unsigned capacity;
	int *arr;
};

struct stack s;

void push2(int p){
	if(s.top2==s.top1+1){
		printf("Stack full\n");
		return;
	}
	s.top2--;
	s.arr[s.top2]=p;
}


void push1(int p){
	if(s.top1==s.top2-1){
		printf("Stack full\n");
		return;
	}
	s.top1++;
	s.arr[s.top1] = p;
		
}


int pop1(){
	if(s.top1==-1){
		printf("Stack empty\n");
		return 0;
	}
	
	int a = s.arr[s.top1];
	s.top1--;
	return a;
}

int pop2(){
	if(s.top2==s.capacity){
		printf("Stack empty\n");
		return 0;
	}
	
	int a = s.arr[s.top2];
	s.top2++;
	return a;
}

void createstack(unsigned capacity){
		
	s.arr = (int *)calloc(capacity,sizeof(int));
	s.top1=-1;
	s.top2 = capacity;
	s.capacity = capacity;
}


int main(){

	int exp1[]={1,4,5,7,4,56,7,8,4,3,54,65,57,34,2,45,4,32435,7,76,3};
	int exp2[]={4,354,45,47,567,58,68,68,9,329,89,459,659,7,653,5,2,4,534,56,65};
	
	int l1 = sizeof(exp1)/sizeof(int);
	int l2 = sizeof(exp2)/sizeof(int);
	
	
	createstack(l1+l2);
	int i,j;
	for(i=0;i<l1;i++){
		push1(exp1[i]);
	}

	for(i=0;i<l2;i++){
		push2(exp2[i]);
	}

	printf("First Stack\n");
	for(i=0;i<l1;i++){
		printf("%d ",pop1());
	}

	printf("\nSecond Stack\n");
	for(i=0;i<l2;i++){
		printf("%d ",pop2());
	}
	printf("\n");

return 0;

}



