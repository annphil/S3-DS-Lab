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

void checkSymmetry()
{
	int i,j,flag;
	for(i=1;i<=terms[0].value;i++)
	{
		if((terms[i].row==transpose[i].row) && (terms[i].col==transpose[i].col) && (terms[i].value==transpose[i].value))
			flag = 1;
		else {
			flag = 0;
			break;
		}
	}
	
	if(flag==0)
	printf("Not symmetric\n");
	else
	printf("Symmetric\n");
}

void main(){
	input();
	sparseDataInput();
	numTerms();
	startPosition();
	sparseTranspose();
	checkSymmetry();
}
