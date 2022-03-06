// Pgm for priority queue using Linked List. Insertion done normally without sorting. Deletion done based on priority.

#include<stdio.h>
#include<stdlib.h>

struct Queue{
	int data;
	int priority;
	struct Queue *link;
};

typedef struct Queue q;

q *front, *rear = NULL;

q *createNode(int data, int priority){
	q *node = (q*)malloc(sizeof(q));
	node->data = data;
	node->priority = priority;
	node->link = NULL;
}

void insert(int item, int priority){
	q *node = createNode(item, priority);
	if(front == NULL)
		front = rear = node;
	else {
		rear->link = node;
		rear = node;
	}
}

int delete(){
	if(front == NULL){
		printf("Queue empty :/\n");
		return -1;
	}
	else {	
		int del;
		int high = -1;
		q *temp = front;
		q *delNode = NULL;		//Node to be deleted.
		while(temp){			//To find node with highest priority.
			if(temp->priority > high){
				high = temp->priority; 
				delNode = temp;	
			}
			temp = temp->link;
		}
		
		del = delNode->data;	
		
		temp = front;
		q *trail = temp;
		while(temp){
			if(temp == delNode){
				if(temp == front)
					front = front->link;	
				else
					trail->link = temp->link;
				break;
			}
			else{
				trail = temp;
				temp = temp->link;
			}
		}
		return del;
	}
}

void displayQ(){
	if(front == NULL)
		printf("Queue Empty :/\n");
	else{
		printf("Queue: \n");
		q *temp = front;
		while(temp){
			printf("Data: %d, Priority: %d\n", temp->data, temp->priority);
			temp = temp->link;
		}
	}
}

void main(){
	int c;
	int flag = 1;
	while(flag == 1){
		printf("\nKindly enter the choice :\n1. Enter element\n2. Delete element\n3. Display\n4. Exit\n");
		scanf("%d", &c);
		int item, priority;
		int del;
		switch(c){
			case 1: printf("Enter value to be inserted and it's priority: ");
				scanf("%d %d", &item, &priority);
				insert(item, priority);
				break;
			case 2: del = delete();
				if(del!=-1)
					printf("Deleted value: %d\n", del);
				break;
			case 3: displayQ();
				break;
			case 4: flag = 0;
				break;
		}
	}
}
