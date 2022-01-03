#include<stdio.h>
#define MAX_SIZE 100
int top1 = -1;
int top2 = MAX_SIZE;
int stack[MAX_SIZE];

void push(int i, int element){
	if(top2 == top1+1)
		printf("Stack overflow\n");
	else if(i == 1)
		stack[++top1] = element;
	else if(i == 2)
		stack[--top2] = element;
}

int pop(int i){
	if(top1 == -1 || top2 == MAX_SIZE){
		return -1;
	}
	else if( i==1 )
		return stack[top1--];
	else if( i==2 ) 
		return stack[top2++];
}

void main(){
	int i, n, n2, element, k, p;
	printf("Enter no of elements to be pushed to stack 1: ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		printf("Enter element to be pushed: ");
		scanf("%d", &element);
		push(1, element);
	}
	printf("Enter no of elements to be pushed to stack 2: ");
	scanf("%d", &n2);
	for(i=0; i<n2; i++){
		printf("Enter element to be pushed: ");
		scanf("%d", &element);
		push(2, element);
	}
	printf("Which stack would you like to pop from, 1/2 ? ");
	scanf("%d", &k);
	if(k == 1){
		printf("Enter no of elements to be popped: ");
		scanf("%d", &n2);
		for(i=0; i<n2; i++){
			p = pop(1);
			if(p == -1)
				printf("Stack underflow\n");
			else
				printf("Popped element: %d\n", p);
		}
	}	
	if(k == 2){
		printf("Enter no of elements to be popped: ");
		scanf("%d", &n2);
		for(i=0; i<n2; i++){
			p = pop(2);
			if(p == -1)
				printf("Stack underflow\n");
			else
				printf("Popped element: %d\n", p);
		}
	}		
}
