#include<stdio.h>
#include<stdlib.h>


struct stack{
	int top;
	unsigned capacity;
	int *arr;
};




void createstack(struct stack *s,unsigned capacity){
	s->arr = (int *)calloc(capacity,sizeof(int));
	s->capacity = capacity;
	s->top=-1;
}
void push(struct stack *s,int data){

	if(s->top==s->capacity){
		printf("Stack full\n");
		return;
	}
	s->top++;
	s->arr[s->top] = data;
}


void traversal(struct stack *s){
	int i;
	for(i=0;i<s->capacity;i++){
		printf("%d  ",s->arr[i]);
		
	}
	
	printf("\n");
}
int getmin(struct stack *a){
	
	return a->arr[a->top];
}

void setstack(struct stack *sp,struct stack *au,struct stack *ac){
	int i;
	push(au,sp->arr[sp->top]);
	push(ac,sp->arr[sp->top]);
	sp->top--;
	for(i=1;i<sp->capacity;i++)
	{
		if((sp->arr[sp->top]) < au->arr[au->top] ){
			push(au,sp->arr[sp->top]);
			sp->top--;
		}else{
			push(ac,sp->arr[sp->top]);
			sp->top--;
		}
		
	}


}


int main(){

struct stack sp;
struct stack ac;
struct stack au;
	int exp[]={1,2,3,4,5,56,6,7,8,9,32,65,62,24,64,34,75,75,7,547,58,5,857,875,87,5,45,467,6,342,33,5,36,46,456,4,64,65,62,34,5,352,5,35,23};
	int len = sizeof(exp)/sizeof(int);
	int i;
	createstack(&sp,len);
	
	createstack(&au,len);
	
	createstack(&ac,len);
	
	for(i=0;i<len;i++){
		push(&sp,exp[i]);
	}
	
	setstack(&sp,&au,&ac);
	int min = getmin(&au);
	
	printf("Minimum of the stack is %d\n",min);
	
		
}

