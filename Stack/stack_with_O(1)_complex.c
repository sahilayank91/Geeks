#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *prev;
	int data;
	struct node *next;	
};
struct node *head=NULL;

struct stack{
	struct node *head;
	struct node *mid;
	int count;
};



void push(struct stack *s,int data){
	if(s->head==NULL){
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		temp->data = data;
		temp->prev = NULL;
		temp->next = NULL;
		s->head = temp;
		s->count++;
		
	}else{
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		temp->data = data;
		temp->prev = s->head;
		temp->next = NULL;
		s->head->next = temp;
		s->head = temp;
		s->count++;
	}
}

int pop(struct stack *s){
	if(s->head==NULL){
		printf("Stack Empty\n");
		return 0;	
	}
	
	int a = s->head->data;
	s->head = s->head->prev;
	return a;
}

void traversal(struct stack *s){
	struct node *n = s->head;

	while(n->prev!=NULL){
		printf("%d  ",n->data);
		n=n->prev;
	}
	
	printf("%d\n",n->data);	
}

struct stack * createstack(){
	struct stack *s = (struct stack *)malloc(sizeof(struct stack));
	s->count = 0;
	return s;
}
int main(){
	int arr[]={1,2,345,345,3,643,47,56,756,775,86,9,79,796,856,734,64,35,324};
	int len = sizeof(arr)/sizeof(int);
	int i;
	struct stack *s = createstack();
	for(i=0;i<len;i++){
		push(s,arr[i]);
	}
	printf("Popped: %d \n",pop(s));
	printf("No of nodes: %d \n",s->count);
	
	
	traversal(s);
}
