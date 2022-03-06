#include<stdio.h>
#include<stdlib.h>
#define max_size 20

struct Queue{
	int data;
	struct Queue *link;
};

typedef struct Queue q;

q *front, *rear = NULL;

q *createNode(int data){
	q *node = (q*)malloc(sizeof(q));
	node->data = data;
	node->link = NULL;
}

void insert(int item){
	q *node = createNode(item);
	if(front == NULL)
		front = rear = node;
	else {
		rear->link = node;
		rear = node;
	}
}

int delete(){
	if(front == NULL){
		printf("Queue empty\n");
		return -1;
	}
	else {
		int del = front->data;
		front = front->link;
		return del;
	}
}

void displayQ(){
	if(front == NULL)
		printf("Empty\n");
	else{
		printf("Queue: ");
		q *temp = front;
		while(temp){
			printf("%d ", temp->data);
			temp = temp->link;
		}
	}
}

void main(){
	int c;
	int flag = 1;
	while(flag == 1){
		printf("\nKindly enter choice:\n1. Enter element\n2. Delete element\n3. Display\n4. Exit\n");
		scanf("%d", &c);
		int item;
		int del;
		switch(c){
			case 1: printf("Enter value to be inserted: ");
				scanf("%d", &item);
				insert(item);
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
