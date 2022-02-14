//Pgm to check whether a string is a Palindrome using Stack.

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#define max_size 20

void push(char *stack, int *top, char c){
	if(*top == max_size-1){
		printf("Stack Overflow! \n");
		exit(0);
		}
	else
		stack[++*top] = c;
}

char pop(char *stack, int *top){
	if(*top == -1){
		printf("Stack Underflow! \n");
		exit(0);
		}
	else 
		return stack[(*top)--];
}

int checkPalindrome(char *stack, int top1){
	char aux_stack[20];
	int k = (top1)/2, flag = 0, top2 = -1;
	char c;
	
	//To add elements to auxilliary stack in reverse order 
	if( (top1)%2 == 0 ){		// If no of elements in stack is odd (top is even).
		while((top1)>k){
			c = pop(stack, &top1);
			push(aux_stack, &top2, c);
		}
		c = pop(stack, &top1);	// To remove middle element.
	}
	else{				//If no of elements in stack is even.
		while( top1 >= k+1 ){
			c = pop(stack, &top1);
			push(aux_stack, &top2, c);
		}
	}
	
/*	printf("\n");
	while(top1!=-1){
		printf("%c \n", stack[top1]);
		top1--;
	}
	printf("\n");
	while(top2!=-1){
		printf("%c \n", aux_stack[top2]);
		top2--;
	}*/
	
	//Comparing stack and auxilliary stack. If each element is same, string is a Palindrome.
	while( top1>-1 ){
		if(stack[top1] == aux_stack[top2])
			flag = 1;
		else {
			flag = 0;
			break;
		}
		top1--;
		top2--;
	}
	return flag;
}

void main(){
	char s[20], str[20], ch;
	char stack[max_size];
	int top1 = -1;
	
	int i, flag = 1;
	printf("Enter word to be checked: ");
	scanf("%s", s);
	
	//C is case sensitive. Converting upper case letters to lowercase. 
	strcpy(str, s);
	for(i=0; i<strlen(s); i++){
		if(isupper(s[i]))
			str[i] = tolower(s[i]);
	}
	
	// Pushing each letter into stack
	for(i=0; i<strlen(str); i++){
		push(stack, &top1, str[i]);
	}
	
	int k = checkPalindrome(stack, top1);
	
	if(k == 1)
		printf("%s is a Palindrome.\n", s);
	else 
		printf("%s is not a Palindrome.\n", s);
}
