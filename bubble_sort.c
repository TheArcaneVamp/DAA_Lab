#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int x, int y){
	int temp = a[x];
	a[x] = a[y];
	a[y] = temp;
}

int Bubble_Sort(int n, int *a){
        for(int i=0; i<(n-1);i++){
                for(int j=0; j< (n-1-i); j++){
                	if(a[j] > a[j+1]){
                		swap(a, j, j+1);
                	}
                }
        }
}

void main(){
        unsigned long n;
        int *a;
        FILE *fptr = fopen("test_bubble.txt", "a");
        clock_t start_t, end_t;
        double total_t;
        printf("Enter the size of inputs:");
        scanf("%ld", &n);
        fprintf(fptr,"For the input size:%ld\n", n);
        a = (int*)malloc(n*sizeof(int));
        
	srand(time(0));
	
	//fprintf(fptr, "The Inputs are:\n");
	for(int i=0; i<n; i++){
		a[i] = rand();
		//fprintf(fptr, "Array[%d]:%d\n",i,a[i]);
	}
	
	start_t = clock();
	
	Bubble_Sort(n, a);
	
	/*(fprintf(fptr, "The Outputs are:\n");
	for(int i=0; i<n;i++){
		fprintf(fptr, "Array[%d]:%d\n", i, a[i]);
	}*/
	
	end_t = clock();
	
	total_t = (double)(end_t - start_t)/CLOCKS_PER_SEC;
	
	fprintf(fptr, "The total time of execution is:%lf\n", total_t);
	
}

