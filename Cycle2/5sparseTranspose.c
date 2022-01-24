#include<stdio.h>

typedef struct{
	int row;
	int col;
	int value;
}sparse;

sparse terms[100], transpose[100];
int a[20][20], p, q;
int count[20], startPos[20];

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
	printf("row 	col 	value\n");
	for(i=0; i<=terms[0].value; i++){
		printf("%d 	%d 	%d\n", terms[i].row, terms[i].col, terms[i].value);
	}
}

void displayTranspose(){
	int i;
	printf("Transpose Matrix Data\n");
	printf("row 	col 	value\n");
	for(i=0; i<=transpose[0].value; i++){
		printf("%d 	%d 	%d\n", transpose[i].row, transpose[i].col, 			transpose[i].value);
	}
}

void numTerms(){
	int i,j,k;
	for (k=0; k<terms[0].col; k++)
		count[k] = 0;
	for(i=1; i<=terms[0].value; i++){
		j = terms[i].col;
		count[j]++;
	}
	
}

void startPosition(){
	int i;
	startPos[0] = 1;
	for(i=1; i<terms[0].col; i++)
		startPos[i] = startPos[i-1] + count[i-1] ;
	
}

void sparseTranspose(){
	int i,j;
	transpose[0].col = terms[0].row;
	transpose[0].row = terms[0].col;
	transpose[0].value = terms[0].value;
	for( i=1; i<=terms[0].value; i++){
		j = startPos[terms[i].col];
		transpose[j].col = terms[i].row;
		transpose[j].row = terms[i].col;
		transpose[j].value = terms[i].value;
		startPos[terms[i].col]++;
		
	}
}

void main(){
	input();
	sparseDataInput();
	numTerms();
	startPosition();
	sparseTranspose();
	displaySparseData();
	displayTranspose();
}

//1 0 0 0 2 4 5 0 0
//15 0 0 22 0 -15 0 11 3 0 0 0 0 0 0 -6 0 0 0 0 0 0 0 0 91 0 0 0 0 0 0 0 28 0 0 0

