#include<stdio.h>
#include<stdlib.h>


struct node {
	struct node *left;
	struct node *right;
	int data; 
};

struct node * create(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = temp->right  = NULL;
return temp;	
}

struct node * insert(struct node *head,int data){
	
	if(head==NULL){
		return create(data);
	}else if((head->data)<data)
	{	
		head->right = insert(head->right,data);
	}else if (data<(head->data)){
		head->left = insert(head->left,data);
	}else{
		return head;
	}
}

void preorder(struct node *head){
	if(head!=NULL){
		printf("%d ",head->data);
		preorder(head->left);
		preorder(head->right);
	}
	
}

int printAncestors(struct node *root,int data){
	if(root==NULL){
		return 0;
	}
	
	if(root->data==data){
		return 1;
	}
	
	if(printAncestors(root->left,data)|| printAncestors(root->right,data)){
		printf("%d ",root->data);
		return 1;	
	}else return 0;
}
int main(){
	struct node *head = NULL;
	int arr[]={1,3,34,53,646,314,75,845,2347,5321,523,55675,7,78,7328,6,5433,532,5233,5,73,623,51,252};
	int len = sizeof(arr)/sizeof(int);
	int i;
	for(i=0;i<len;i++){
		head = insert(head,arr[i]);
	}
	preorder(head);
	printf("\n\n\n");
	printf("Ancestors of 51 are: \n");
	printAncestors(head,51);
return 0;
}


