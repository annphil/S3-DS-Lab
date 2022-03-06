#include<stdio.h>
#define max_size 20

int ar[max_size];
int front = -1, rear = -1;

void insert(int item){
	if(rear == max_size-1)
		printf("Queue full");
	else if(front == -1){
		front++;
		ar[++rear] = item;
	}
	else 
		ar[++rear] = item;
}

int delete(){
	if(front == max_size){
		printf("Queue empty");
		return -1;
	}
	else 
		return ar[front--];
}

void displayQ(){
	if(front == -1 || front == max_size)
		printf("Empty");
	else{
		int fr = front;
		printf("Queue: ");
		while(fr != (rear+1) ){
			printf("%d ", ar[fr]);
			fr++;
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
				printf("Deleted value: %d\n", del);
				break;
			case 3: displayQ();
				break;
			case 4: flag = 0;
				break;
		}
	}
	

}
