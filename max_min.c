#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct MAXMIN{
	int max;
	int min;
} MAXMIN;

int max(int a, int b){
	if(a>=b){
		return a;
	}
	else{
		return b;
	}
}

int min(int a, int b){
	if(a<=b){
		return a;
	}
	else{
		return b;
	}
}

MAXMIN *maxMin(int* a, unsigned long x, unsigned long y){
	MAXMIN *temp = (MAXMIN*)malloc(sizeof(MAXMIN));
	if(y-x <= 1){
		temp->max = max( a[x], a[y]);
		temp->min = min( a[x], a[y]);
		return temp; 
	}
}

void main(){
	unsigned long n;
	clock_t start_t, end_t;
	double total_t;
	FILE *fptr = fopen("max_min.txt", "a");
	if(getc(fptr)==EOF){
		fprintf(fptr, "INPUT SIZE\tCPU TIME\n");
	}
	printf("Enter the number of inputs:");
	scanf("%ld", &n);
	srand(time(0));
	
	int *a = (int*)malloc(n*sizeof(int));
	
	for(int i=0; i<n;i++){
		a[i] = rand();
	}
	
	start_t = clock();
	
	maxMin(a, n, 0);
	
	end_t = clock();
	
	total_t = (double)(end_t - start_t)/CLOCKS_PER_SEC;
	
	fprintf(fptr, "%ld\t\t%lf\n", n, total_t); 
	}
