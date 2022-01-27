#include<stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int stack1[MAX_SIZE], stack2[MAX_SIZE];
int top1 = -1, top2 = -1;

void push(int *stack, int *top, int element){
	if(*top == MAX_SIZE-1)
		printf("Stack overflow\n");
	else
		stack[++*top] = element;
}

int pop(int *stack, int *top){
	if(*top == -1){
		return -1;
	}
	else
		return stack[(*top)--];
}

void sortedPushStack(int element){
	// Adding directly when element is greater than greatest in ascendingly sorted stack || when stack is empty
	if( element >= stack1[top1] || top1==-1 )
		push(stack1, &top1, element);
	else {
		// To keep adding numbers smaller than element to auxiliary stack && stopping when it reaches end of stack 
		while( element<stack1[top1] && top1!=-1 ){
			stack2[++top2] = pop(stack1, &top1);
		}
		// Adding element to right position
		push(stack1, &top1, element);
		// Putting elements back into original stack from auxiliary stack
		while(top2!=-1){
			stack1[++top1] = pop(stack2, &top2);
		}
	}
}

void main(){
	int i, n, element;
	printf("Enter no of elements to be pushed: ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		printf("Enter element to be pushed: ");
		scanf("%d", &element);
		sortedPushStack(element);
	}
	printf("Sorted elements: ");
	for(i=0; i<n; i++){
		printf("%d ", stack1[i]);
	}			
}
