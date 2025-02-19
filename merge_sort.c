#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int* Allocate(int n){
	int *temp;
	temp = (int*)malloc(n*sizeof(n));
	return temp;
}

void Merge(int *A, int p, int q, int r){
	int n1 = q-p+1;
	int n2 = r-q;
	int i, j;
	int* L = Allocate(n1+2);
	int *R = Allocate(n2+2);
	
	for(int i = 1; i< n1+1; i++){
		L[i] = A[p+i-1];
	}
	
	for(int j = 1; j<n2+1; j++){
		R[j] = A[q+j];
	}
	L[n1+1] = (int)INFINITY;
	R[n2+1] = (int)INFINITY;
	i=1, j=1;
	for( int k = p; k<r+1; k++){
		if(L[i]<=R[j]){
			A[k] = L[i];
			i = i+1;
		}
		else{
			A[k] = R[j];
			j = j+1;
		}
	}
} 

void Merge_Sort(int *A, int p, int r){
	int q;
	if(p<r){
		q = (int)((p+r)/2);
		Merge_Sort(A, p, q);
		Merge_Sort(A, q+1, r);
		Merge(A, p, q, r);
	}
} 

void main(){
	unsigned long n;
	clock_t start_t, end_t;
	double total_t;
	FILE *fptr = fopen("merge_sort.txt", "a");
	if(getc(fptr)==EOF){
		fprintf(fptr, "INPUT SIZE\tCPU TIME\n");
	}
	printf("Enter the number of inputs:");
	scanf("%ld", &n);
	srand(time(0));
	
	int *a = (int*)malloc((n+2)*sizeof(int));
	fprintf(fptr, "The inputs are:-\n");
	for(int i=1; i<n+1;i++){
		a[i] = rand()%1000;
		fprintf(fptr, "Array[%d]:%d\n", i, a[i]); 
	}
	
	start_t = clock();
	
	Merge_Sort(a, 0, n);
	
	end_t = clock();
	
	total_t = (double)(end_t - start_t)/CLOCKS_PER_SEC;
	
	fprintf(fptr, "%ld\t\t%lf\n", n, total_t);
	
	fprintf(fptr,"The outputs are:\n");
	for(int i=1; i<n+1; i++){
		fprintf(fptr, "Array[%d]:%d\n",i, a[i] );
	} 
}
