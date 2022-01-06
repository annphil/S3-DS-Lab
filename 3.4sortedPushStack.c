#include<stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct listnode* link;
}listnode;

listnode* first = NULL;

listnode* createNode(int value){
	listnode* node = (listnode*)malloc(sizeof(listnode));
	node->data = value;
	node->link = NULL;
	return node;
}

void insertNode(int value){
	listnode* node = createNode(value);
	if( first->data == NULL )
		first->data = value;
	else if( value <= first->data ){
		node->link = first;
		first = node;
	}
	else if( value > first->data){
		listnode* temp1 = first->link;
		listnode* temp2 = temp1->link;
		if( first->link == NULL )
			first->link = node;
		else if( value <= temp1->data){    // When there are just 2 nodes in list
			first->link = node;
			node->link = temp1;
		}
		else {
			while(temp2->link ){
				if(value >= temp1->data && value <= temp2->data ){
					temp1->link = node;
					node->link = temp2;
					break;	
				}
				else {
					temp2 = temp2->link;
					temp1 = temp1->link;
				}	
			}
			if(temp2->link == NULL && value >= temp1->data && value <= temp2->data){
				temp1->link = node;
				node->link = temp2;
			}
			else if(temp2->link == NULL && value > temp2->data)
				temp2->link = node;	
		}		
	}			
}

void display(){
	listnode* temp = first;
	while(temp){
		printf("%d\t", temp->data);
		temp = temp->link;
	}
	printf("%d\t", temp->data);
}	

void main(){
	int i, n, element ;
	printf("Enter no of elements to be pushed: ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		printf("Enter element to be pushed: ");
		scanf("%d", &element);
		insertNode(element);
	}
	for(i=0; i<n; i++){
		printf("Sorted elements: ");
		display();
	}
		
}
