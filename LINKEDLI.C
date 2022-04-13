#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define structure
typedef struct nodetype
{
	int info;
	struct nodetype* next;
}node;
//function prototype
void createemptylist(node **head );
void traverseinorder(node *head);
void insertatbeginning(node **head,int item);

void main()
{
	node *head;
	int choice,element,after;
	clrscr();
	createemptylist(&head);
	while(1)
	{
		printf("operations available are \n");
		printf("1. Insert at begining \n");
		printf("2. Traverse in order \n");
		printf("Enter choice 1 or 2\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("\nEnter element : ");
				scanf("%d",&element);
				insertatbeginning(&head,element);
				break;
			case 2:if(head==NULL)
				printf("\nList is empty");
				else
				traverseinorder(head);
				printf("\Press any key to continue");
				getch();
				break;
			default:exit(0);
		}
	}
}
void createemptylist(node **head)
{
	*head=NULL;
}
void insertatbeginning(node **head,int item)
{
	node* ptr;
	ptr=(node*)malloc(sizeof(node));
	ptr->info=item;
	if(*head==NULL)
	ptr->next=NULL;
	else
	ptr->next=*head;
	*head=ptr;
}
void traverseinorder(node *head)
{
	while(head!=NULL)
	{
		printf("\n%d",head->info);
		head=head->next;
	}
}