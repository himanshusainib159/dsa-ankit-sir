#include<stdio.h>
typedef struct nodetype{
	int info;
	struct node *next;
	}node;
void insertatbeginning(node **head){
	int data;
	node *temp=(node *)malloc(sizeof(node));
	printf("Enter element : ");
	scanf("%d",&data);
	temp->info=data;
	temp->next=*head;
	*head=temp;
	printf("Element successfully inserted\n");
}
void main(){
	int c;
	node *head;
	while(1){
		printf("Menu :\n1. Insert at beginning\n2. Insert at end\n3. Traverse\n4.Exit\nEnter choice :");
		scanf("%d",&c);
		switch(c){
			case 1:
			insertatbeginning(**head);
			break;
			case 2:
			break;
			case 3:
			break;
			case 4:exit(0);
		}
	}
}