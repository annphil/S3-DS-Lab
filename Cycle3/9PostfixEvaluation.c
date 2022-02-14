#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX_SIZE 100
int top = -1;
int stack[MAX_SIZE];

void push(int element){
	if(top == MAX_SIZE-1)
		printf("Stack overflow\n");
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
	char exp[MAX_SIZE];
	int i;
	printf("Enter postfix expression: ");
	scanf("%s", exp);
	for(i=0; i<strlen(exp); i++){
		if(isdigit(exp[i]))
			push(exp[i] - '0');
		else{
			int op2 = pop();
			int op1 = pop();
			switch(exp[i]){
				case '+' : push( op1 + op2 ); 
					   break;
				case '-' : push( op1 - op2 ); 
					   break;
				case '*' : push( op1 * op2 ); 
					   break;				
				case '/' : push( op1 / op2 ); 
					   break;
			}
		}
	}
	int ans = pop();
	printf("Solution = %d\n", ans);
}
