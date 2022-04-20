// Pgm to check if a given expression has balanced parentheses

#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define max_size 50

void push(char *stack, int *top, char c){
	if(*top == max_size-1)
		printf("Stack Overflow!");
	else
		stack[++*top] = c;
}

void pop(char *stack, int *top){
	if(*top == -1)
		printf("Stack Underflow!");
	else 
		--*top;
}

bool balancedParentheses(char *str, char *stack, int *top ){
	int i;
	for(i=0; i<strlen(str); i++)
	{
		if(str[i] == ')')					//When ')', pop till '(' unless stack is empty. Push if empty.
		{
			if(*top == -1)					// If stack is empty
				push(stack, top, str[i]);
			else
			{
				while( ( stack[*top] ) != '(')	// pops till '('
					pop(stack, top);
				pop(stack, top);			//to pop '('
			}
		}
		else
			push(stack, top, str[i]);			// push if it's anything other than ')'
	}
	
	if(*top == -1)
		return true;
	else
		return false;
}

void main(){
	char stack[max_size], s[max_size];
	bool k;
	int top = -1;
	
	printf("Please enter expression: ");
	scanf("%s", s);
	
	k = balancedParanthesis(s, stack, &top);
	
	if(k==true)
		printf("Expression has balanced parentheses\n");
	else
		printf("Expression does not have balanced parentheses\n");	
}
