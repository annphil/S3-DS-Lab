#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX_SIZE 50

char stack[MAX_SIZE];
int top = -1;

void push(char element){
	if(top == MAX_SIZE-1)
		printf("Stack overflow\n");
	else
		stack[++top] = element;
}

char pop(){
	if(top == -1){
		return -1;
	}
	else
		return stack[top--];
}
char peek(){
	return stack[top];
}

int prec(char c){
	switch(c){
		case '+': return 1;
					break;
		case '-': return 1;
					break;
		case '*': return 2;
					break;
		case '/': return 2;
					break;
		case '^': return 3;
					break;
	}
	return -1;
}

void display(){
	while(top!=-1){
		peek();
	}
}

void infixToPostfix(char *exp){
	int i, m, n;
	char c;
printf("%s\n", exp);
		for(i=0; i<strlen(exp); i++){
			if( isalpha(exp[i]) || isdigit(exp[i]) )	//print if char or digit
				printf("%c", exp[i]);
			else if(exp[i] == '(')						//push '('
				push(exp[i]);
			else if(exp[i] == ')'){
				while( peek() != '(' ){					//if ')', pop & print till ')'
/*Check
}
printf("%s\n", exp);
/* a*(b+c)*d*/					c = pop();
					printf("%c", c);
				}
				pop();							//To pop '('
			}

			else{
				int m = prec(exp[i]);
				int n = prec(peek());
				if( m >= n ){
					c = pop();
					printf("%c", c);
					push(exp[i]);
				}
				else
					push(exp[i]);
			}
		}
			

		while(top!=-1)
			printf("%c", pop() );
	
}

void main(){
	char exp[MAX_SIZE];
	
	printf("Enter infix expression: ");
	scanf("%s", exp);
printf("%s\n", exp);	
	infixToPostfix(exp);
//	display();
}
