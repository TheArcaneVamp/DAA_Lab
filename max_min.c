#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int *maxMin(int* a, unsigned long x, unsigned long y){
	
	int *arr = (int*)malloc(2*sizeof(int));
	
	if(y-x <= 1){
		arr[0] = max( a[x], a[y]);
		arr[1] = min( a[x], a[y]);
		return arr; 
	}
	else{
			int *arr1, *arr2;
			arr1 = maxMin(a, x, ((x+y)/2));
			arr2 = maxMin(a, ((x+y)/2) +1, y);
			arr[0] = max(arr1[0], arr2[0]);
			arr[1] = min(arr1[1], arr2[1]);
			return arr;
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
	fprintf(fptr, "The inputs are:-\n");
	for(int i=0; i<n;i++){
		a[i] = rand();
		fprintf(fptr, "Array[%d]:%d\n", i, a[i]); 
	}
	
	int *arr;
	
	start_t = clock();
	
	arr = maxMin(a, 0, n);
	
	end_t = clock();
	
	total_t = (double)(end_t - start_t)/CLOCKS_PER_SEC;
	
	fprintf(fptr, "%ld\t\t%lf\n", n, total_t);
	
	fprintf(fptr,"The outputs are:\nThe maximum is:%d\nThe minimum is:%d\n", arr[0], arr[1]); 
}
