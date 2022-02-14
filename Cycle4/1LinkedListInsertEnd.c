#include<stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
struct listNode{
	int data;
	struct listNode *link;
};

struct listNode *head = NULL;

void insertEnd(int data){
	struct listNode *node = (struct listNode*)malloc(sizeof(struct listNode));
	node->data = data;
	node->link = NULL;
	
	if(head == NULL)
		head = node;
	else{
		struct listNode *temp;
		temp = head;
		while(temp->link){
			temp = temp->link;
		}
		temp->link = node;
	}	
}

void displayList(){
	struct listNode *temp = head;
	while(temp->link){
		printf("%d ", temp->data);
		temp = temp->link;
	}
	printf("%d\n", temp->data);	
}

void main(){
	int n, flag = 1;
	while(flag!=0){
		printf("\nEnter choice\n1. Insert at end\n2. Display List\n3. Exit\n");
		scanf("%d", &n);
		switch (n){
			case 1 : printf("Enter data to be inserted:");
				 int data;
				 scanf("%d", &data);
				 insertEnd(data);
				 break;
			case 2 : printf("Linked List: ");
				 displayList();
				 break;
			case 3 : flag = 0;
				 break;
		}
	}
}
