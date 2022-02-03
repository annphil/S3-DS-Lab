#include<stdio.h>

typedef struct{
	int expon;
	int coef;
} polynomial;

void polyInput(polynomial *x, int* n){
	int i;
	printf("Enter number of terms: ");
	scanf("%d", n);
	for (i=0; i<*n; i++){
		printf("Enter exponent and coefficient of term %d: ", i+1);
		scanf("%d %d", &x[i].expon, &x[i].coef); 
	}
}

void polyDisplay(polynomial* x, int n){
	int i;
	for (i=0; i<n; i++)
		printf("Exponent and coefficient of term %d: %d, %d\n", i+1, x[i].expon, x[i].coef);
}

void polyAddition(polynomial *a, polynomial *b, polynomial *c, int n1, int n2, int *n3){		
	int i=0,j=0,k=0, l;
	while( i<n1 && j<n2 ){
		if (a[i].expon < b[j].expon){ 
			c[k].expon = a[i].expon;
			c[k].coef = a[i].coef;
			i++;
			k++;
		}
		else if(a[i].expon > b[j].expon){
			c[k].expon = b[j].expon;
			c[k].coef = b[j].coef;
			j++;
			k++;
		}
		else {
			c[k].expon = b[j].expon;
			c[k].coef = a[i].coef + b[j].coef;
			i++;
			j++;
			k++;
		}
	}
	for ( ; i<n1; i++){
		c[k].expon = a[i].expon;
		c[k].coef = a[i].coef;
		i++;
		k++;
	}
	for ( ; j<n2; j++){
		c[k].expon = b[j].expon;
		c[k].coef = b[j].coef;
		j++;
		k++;
	}
	*n3 = k;
}

void main(){
	polynomial a[100], b[100], c[100];
	int n1, n2, n3=0;
	polyInput(a, &n1);
	polyInput(b, &n2);
	polyAddition(a, b, c, n1, n2, &n3);
	polyDisplay(c, n3);
}
