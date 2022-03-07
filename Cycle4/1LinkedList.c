//Linked List

#include<stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
struct listNode{
	int data;
	struct listNode *link;
};

struct listNode *head = NULL;

//1. Create a linked list with n elements by adding elements at the end
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

//2. Given a node data, insert a new node after it
void insertAfter(int data, int check){
	struct listNode *node = (struct listNode*)malloc(sizeof(struct listNode));
	node->data = data;
	node->link = NULL;
	
	struct listNode *temp = head;
	int flag = 0;

	while(temp){
		if(temp->data == check){
			node->link = temp->link;
			temp->link = node;
			flag = 1;
			break;
		}
		else
			temp = temp->link;
	}
	
	if(flag == 0)
		printf("Node not found :/\n");
}

//3. Given a node data, insert a new node before it
void insertBefore(int data, int check){
	struct listNode *node = (struct listNode*)malloc(sizeof(struct listNode));
	node->data = data;
	node->link = NULL;
	
	struct listNode *temp = head;
	struct listNode *trail = head;
	int flag = 0;

	if(head->data == check){
		node->link = head;
		head = node;
	}
	
	else{
		while(trail){
			if(temp->data == check){
				node->link = temp;
				trail->link = node;
				flag = 1;
				break;
			}
			else{
				trail = temp;
				temp = temp->link;
			}
		}
	}
	
	if(flag == 0)
		printf("Node not found :/\n");
}

//4. Insert a new node in the given position
void insertAtPos(int pos, int data){
	struct listNode *node = (struct listNode *)malloc(sizeof(struct listNode));
	node->data = data;
	node->link = NULL;
	
	int flag = 0; 
	
	if(pos == 1){
			node->link = head;
			head = node;
		}
	
	else{
		struct listNode *temp = head->link;
		struct listNode *trail = head;
		int p=2;
		while(p<=pos){
			if(p == pos){
				node->link = temp;
				trail->link = node;
				flag = 1;
				break;
			}
			else{
				trail = temp;
				temp = temp->link;
				p++;
			}
		}
	}
	
	if(flag == 0)
		printf("Node not found :/\n");
}

//5. Delete a node, given the key data value.
void delete(int del){
	struct listNode *temp = head;
	int flag = 0;
	
	if(head->data == del){
		head = head->link;
		free(temp);
	}
	else{
		struct listNode *trail = head;
		while(temp){
			if(temp->data == del){
				trail->link = temp->link;
				free(temp);
				flag = 1;
				break;
			}
			else
				trail = temp;
				temp = temp->link;
		}	
	}
	
	if(flag == 0)
		printf("Node not found :/\n");
}

//6. Delete a node given the position.
void deletePos(int pos){
	struct listNode *temp = head;
	int flag = 0, p = 1;
	
	struct listNode *trail = head;
	while(p<=pos){
		if(p == pos){
			if(p == 1)					//If head
				head = head->link;
			else
				trail->link = temp->link;
			free(temp);
			flag = 1;
			break;
		}
		else{
			trail = temp;
			temp = temp->link;\
			p++;
		}
	}	
	
	if(flag == 0)
		printf("Node not found in given position :/\n");
}

void displayList(){
	struct listNode *temp = head;
	
	if(head == NULL){
		printf("Empty List\n");
		return;
	}
	while(temp->link){
		printf("%d ", temp->data);
		temp = temp->link;
	}
	printf("%d\n", temp->data);	
}

void main(){
	int n, flag = 1;
	while(flag!=0){
		printf("\nEnter choice\n1. Insert at end\n2. Insert after a node\n3. Insert before a node\n4. Insert new node at given position\n5. Delete data\n6. Delete node at given position\n7. Display List\n8. Exit\n");
		scanf("%d", &n);
		switch (n){
			case 1 : printf("Enter data to be inserted: ");
				 int data;
				 scanf("%d", &data);
				 insertEnd(data);
				 break;
			case 2 : printf("Enter data and no. after which data is to be inserted: ");
				 int dat, check;
				 scanf("%d %d", &dat, &check);
				 insertAfter(dat, check);
				 break;
			case 3 : printf("Enter data and no. before which data is to be inserted: ");
				 int x, before;
				 scanf("%d %d", &x, &before);
				 insertBefore(x, before);
				 break;
		   	case 4 : printf("Enter position and data to be inserted: ");
				 int d, pos;
				 scanf("%d %d", &pos, &d);
				 insertAtPos(pos, d);
				 break;
			case 5 : printf("Enter data to be deleted: ");
				 int del;
				 scanf("%d", &del);
				 delete(del);
				 break;
			case 6 : printf("Enter position at which data is to be deleted: ");
				 int po;
				 scanf("%d", &po);
				 deletePos(po);
				 break;
			case 7 : printf("Linked List: ");
				 displayList();
				 break;
			case 8 : flag = 0;
				 break;
		}
	}
}

