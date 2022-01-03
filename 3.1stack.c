#include<stdio.h>
#define MAX_SIZE 100
int top1 = -1;
int stack[MAX_SIZE];

void push(int element){
	if(top == MAX_SIZE-1)
		printf("Stack overflow");
	else
		stack[++top] = element;
}

int pop(){
	if(top == -1){
		return -1;
	}
	else
		return stack[top--];
}

void main(){
	int i, n, n2, element, p;
	printf("Enter no of elements to be pushed: ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		printf("Enter element to be pushed: ");
		scanf("%d", &element);
		push(element);
	}
	printf("Enter no of elements to be popped: ");
	scanf("%d", &n2);
	for(i=0; i<n2; i++){
		p = pop();
		if(p == -1)
			printf("Stack underflow");
		else
			printf("Popped element: %d\n", p);
	}		
}
