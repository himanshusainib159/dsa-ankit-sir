#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<process.h>

typedef struct lklist{
	  int info;
	  struct lklist *next;
}node;

void main(){
	void insert(node**);
	void insertEnd(node**);
	void traverse(node*);
	void search(node*,int);
	void deleteFromBeg(node**);
	void deleteFromEnd(node*);
	void deleteList(node**);
	void insertAfter(node*);
	void deleteAfter(node*);

	node *head=NULL;
	int choice, data, item;
	clrscr();
	while(1){
		printf("\n\nMENU\n1.Insert at beginning.\n2.Insert At End.\n3.Traverse.\n4.Search\n5.Delete From Beginning.\n6.Delete From End.\n7.Delete List\n8.Insert After Element\n9.Delete After Element.\n10.Exit.\nEnter you choice :");
		scanf("%d", &choice);
		switch(choice){
			case 1: insert(&head);
					break;
			case 3: traverse(head);
					break;
			case 2: insertEnd(&head);
					break;
			case 4: printf("Enter new int value to insert: ");
					scanf("%d", &data);
					search(head,data);
					break;
			case 5: deleteFromBeg(&head);
					break;
			case 6: if (head->next == NULL)
						deleteFromBeg(&head);
					else
						deleteFromEnd(head);
					break;
			case 7: deleteList(&head);
					break;
			case 8: if (head == NULL)
						printf("\nLink List empty. Operation invalid.");
					else
						insertAfter(head);
					break;
			case 9: if (head == NULL)
						printf("\nLink List empty. Operation invalid.");
					else if(head->next == NULL)
						printf("\nToo less nodes. Operation invalid.");
					else
						deleteAfter(head);
					break;
			case 10: exit(1);
					 break;
			default: printf("Invalid choice");
		}
	}
	getch();

}

void insert(node** head){
	int data;
	node* temp = (node*)malloc(sizeof(node));
	if (temp == NULL) {
		printf("Memory not allocated.");
		return;
	}
	printf("Enter new int value to insert: ");
	scanf("%d", &data);
	temp->info = data;
	temp->next = *head;
	*head=temp;

	printf("\nInserted %d at beginning.", data);
}

void insertEnd(node** head){
	node *temp, *pos=*head;
	int data;
	temp = (node*)malloc(sizeof(node));
	if (temp == NULL) {
		printf("Memory not allocated.");
		return;
	}
	printf("Enter new int value to insert: ");
	scanf("%d", &data);
	temp->info = data;
	temp->next = NULL;
	while(pos->next!=NULL){
		pos=pos->next;
	}
	pos->next = temp;
}

void insertAfter(node* head){
	node *temp, *ptr;
	int data, item;
	printf("\nEnter element to insert: ");
	scanf("%d", &data);
	printf("Enter element to insert after: ");
	scanf("%d", &item);

	temp = (node*)malloc(sizeof(node));
	if (temp == NULL) {
		printf("Memory not allocated.");
		return;
	}
	ptr = head;
	while(ptr->info!=item)
		ptr=ptr->next;
	temp->info = data;
	temp->next=ptr->next;
	ptr->next=temp;
	printf("%d inserted after %d.",data, item);

}

void deleteFromBeg(node** head){
	node* temp;
	temp = *head;
	*head = (*head)->next;
	printf("\nDeleting %d",temp->info);
	free(temp);
}

void deleteList(node** head){
	node* temp;
	while(temp->next != NULL){
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	*head = NULL;
	printf("\nList deleted.");
}

void deleteFromEnd(node* head){
	node* temp = head;
	while((temp->next)->next != NULL)
		temp = temp->next;
	printf("\nDeleting %d", (temp->next)->info);
	free(temp->next);
	temp->next = NULL;
}

void deleteAfter(node* head){
	node *temp, *ptr;
	int item;

	printf("Enter element to delete after: ");
	scanf("%d", &item);

	ptr = head;
	while(ptr->info!=item)
		ptr=ptr->next;

	temp= ptr->next;
	ptr->next=temp->next;
	printf("Deleting %d after %d", temp->info, ptr->info);
	free(temp);

}

void search(node* head, int item){
	node* temp=head;
	int pos=1;
	while(temp!=NULL){
		if (temp->info == item) {
			printf("\nValue found at position : %d", pos);
			break;
		}
		temp=temp->next;
		pos+=1;
	}
}

void traverse(node* head){
	node* temp = head;
	printf("\nLinked List currently\n");
	while(temp!=NULL){
		printf("%d ", temp->info);
		temp=temp->next;
	}
}