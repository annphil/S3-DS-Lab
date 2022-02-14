#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 50
int stack1[MAXSIZE];
int stack2[MAXSIZE];
int top1=-1,top2=-1;
int num;

void DectoBin(){
	int temp=num;
	do{
	stack1[++top1]=temp%2;
	temp=temp/2;
	}while(temp >= 1);

	printf("Binary equivalent of %d is: ",num);
	for(int i=top1;i>-1;i--){
		printf("%d",stack1[i]);
	}
	printf("\n");
}

void DectoHex(){
	int temp=num;
	do{
	stack2[++top2]=temp%16;
	temp=temp/16;
	}while(temp > 0);
	
	printf("The Hexadecimal equivalent of %d is: ",num);
	for(int i=top2;i>-1;i--){
		if(stack2[i] > 9){
			switch(stack2[i]){
				case 10:if(stack2[i]==10);
						printf("A");
						break;
	
				case 11:if(stack2[i]==11);
						printf("B");
						break;
	
				case 12:if(stack2[i]==12);
						printf("C");
						break;
					
				case 13:if(stack2[i]==13);
						printf("D");
						break;
	
				case 14:if(stack2[i]==14);
						printf("E");
						break;
	
				case 15:if(stack2[i]==15);
						printf("F");
						break;
			}
	}
	else 
		printf("%d",stack2[i]);
	}
	printf("\n");
}

void main(){
	printf("Enter the decimal number: ");
	scanf("%d",&num);
	DectoBin();
	DectoHex();
}
