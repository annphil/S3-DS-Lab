#include<stdio.h>
#include<math.h>

typedef struct{
	int expon;
	int coef;
} polynomial;
//To input the polynomial
void polyInput(polynomial *p, int* n){
	int i;
	printf("Enter number of terms: ");
	scanf("%d", n);
	for (i=0; i<*n; i++){
		printf("Enter exponent and coefficient of term %d: ", i+1);
		scanf("%d %d", &p[i].expon, &p[i].coef); 
	}
}
//To evaluate the polynomial for a value of x
float polyEvaluate(polynomial* p, int n, float x){
	int i;
	float sum=0;
	for (i=0; i<n; i++){
		int j = p[i].expon;
		sum += p[i].coef*pow(x, j);
	}
	return sum;
}

void main(){
	polynomial a[20];
	int n1;
	float x, sum;
	polyInput(a, &n1);
	printf("Enter value of x: ");
	scanf("%f", &x);
	sum = polyEvaluate(a, n1, x);
	printf("Value = %0.2f", sum);
}
