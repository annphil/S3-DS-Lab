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

/*void delete(int data, int check){
	struct listNode *node = (struct listNode*)malloc(sizeof(struct listNode));
	node->data = data;
	node->link = NULL;
	
	struct listNode *temp = head;
	
	if(head->data == check){
		head = head->link;
		printf("Hi %d",head->data);
		//free(temp);
	}
	else{
		struct listNode *trail = head;
		while(trail->link){
			if(temp->data == check){
				trail->link = temp->link;
				//free(temp);
				//printf("Hi %d",head->data);
				break;
			}
			else
				trail = temp;
				temp = temp->link;
		}	
	}
}*/

void insert(int data, int check){
	struct listNode *node = (struct listNode*)malloc(sizeof(struct listNode));
	node->data = data;
	node->link = NULL;
	
	struct listNode *temp = head;

	while(temp){
		if(temp->data == check){
			node->link = temp->link;
			temp->link = node;
			break;
		}
		else
			temp = temp->link;
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
		printf("\nEnter choice\n1. Insert at end\n2. Insert after a node\n3. Display List\n4. Exit\n");
		scanf("%d", &n);
		switch (n){
			case 1 : printf("Enter data to be inserted:");
				 int data;
				 scanf("%d", &data);
				 insertEnd(data);
				 break;
			case 2 : printf("Enter data and no. after which to be inserted:");
				 int dat, check;
				 scanf("%d %d", &dat, &check);
				 insert(dat, check);
				 break;
			case 3 : printf("Linked List: ");
				 displayList();
				 break;
			case 4 : flag = 0;
				 break;
		}
	}
}
