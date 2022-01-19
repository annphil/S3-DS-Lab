#include<stdio.h>

typedef struct{
	int row;
	int col;
	int value;
}sparse;

sparse terms[100];
int a[20][20], p, q;

void input(){
	int i,j;
	printf("Enter order of matrix: ");
	scanf("%d %d", &p, &q);
	printf("Enter elements: ");
	for (i=0; i<p; i++){
		for(j=0; j<q; j++){
		scanf("%d", &a[i][j]);
		}
	}
}

void sparseDataInput(){
	int k=1, i, j, count=0;
	terms[0].row = p;
	terms[0].col = q;
	for (i=0; i<p; i++){
		for(j=0; j<q; j++){
			if(a[i][j]!=0){
			terms[k].row = i;
			terms[k].col = j;
			terms[k].value = a[i][j];
			k++;
			count++;
			}
		}
	}
	terms[0].value = count;
}

void displaySparseData(){
	int i;
	printf("Sparse Matrix Data\n");
	printf("row col value");
	for(i=0; i<=terms[0].value; i++){
		printf("%d %d %d\n", terms[i].row, terms[i].col, terms[i].value);
	}
}

void calSparsity(){
	float a,b;
	a = p;
	b = q;
	float sparsity = (a*b - terms[0].value) / (a*b) ;
	printf("Sparsity = %0.2f\n", sparsity);
}

void main(){
	input();
	sparseDataInput();
	calSparsity();
	displaySparseData();
}
