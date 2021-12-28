#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int row;
	int col;
	int value;
}sparse;

void Add(sparse* a, sparse* b, sparse* c, int m,int n,int p,int q){
	if(m==p && n==q){
		c[0].row=a[0].row;
		c[0].col=a[0].col;
		int pa=1,pb=1,pc=1;
		while(pa<=a[0].value || pb<=b[0].value){
			if(a[pa].row==b[pb].row && a[pa].col==b[pb].col){
			c[pc].row=a[pa].row;
			c[pc].col=a[pa].col;
			c[pc].value=a[pa].value+b[pb].value;
			pa++;
			pb++;
			pc++;
			}
			else if(a[pa].row==b[pb].row){
				if(a[pa].col<b[pb].col){
					c[pc].row=a[pa].row;
					c[pc].col=a[pa].col;
					c[pc].value=a[pa].value;
					pa++;
					pc++;
				}	
				else{
					c[pc].row=b[pb].row;
					c[pc].col=b[pb].col;
					c[pc].value=b[pb].value;
					pb++;
					pc++;
				}
			}
			else if(a[pa].row<b[pb].row){
				c[pc].row=a[pa].row;
				c[pc].col=a[pa].col;
				c[pc].value=a[pa].value;
				pa++;
				pc++;
			}
			else{
				c[pc].row=b[pb].row;
				c[pc].col=b[pb].col;
				c[pc].value=b[pb].value;
				pb++;
				pc++;
			}
		}
		c[0].value=pc-1;
	}
	else {
		printf("Wrong input\n");
		exit(0);
	}
}

void DisplaySparse(sparse* c){
	int i;
	printf("Row\tCol\tValue\n");
	for(i=0;i<=c[0].value;i++)
		printf("%d\t%d\t%d\n",c[i].row,c[i].col,c[i].value);
}

void input(int mat[10][10], int*e, int*f){
	int i,j;
	printf("Enter order of matrix: ");
	scanf("%d %d", e, f);
	printf("Enter elements: ");
	for (i=0; i<*e; i++){
		for(j=0; j<*f; j++){
			scanf("%d", &mat[i][j]);			
		}
	}
}

void sparseDataInput(int mat[10][10], sparse* z, int*e, int*f){
	int k=1, i, j, count=0;
	z[0].row = *e;
	z[0].col = *f;
	for (i=0; i<*e; i++){
		for(j=0; j<*f; j++){
			if(mat[i][j]!=0){
				z[k].row = i;
				z[k].col = j;
				z[k].value = mat[i][j];
				k++;
				count++;
			}
		}
	}
	z[0].value = count;
}

void main(){
	sparse a[10],b[10],c[10];
	int m,n,p,q;
	int i,j;
	int mat1[10][10],mat2[10][10];
	input(mat1, &m, &n);
	input(mat2, &p, &q);
	sparseDataInput(mat1, a, &m, &n);
	printf("Sparse Data 1: \n");
	DisplaySparse(a);
	sparseDataInput(mat2, b, &p, &q);
	printf("Sparse Data 2: \n");
	DisplaySparse(b);
	Add(a, b, c, m, n, p, q);
	printf("Resultant Sparse data: \n");
	DisplaySparse(c);
}
