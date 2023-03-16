#include<stdio.h>
int count = 0;
int partition(int A[], int l, int r){
	int x,y,pivot;
	x = l;
	y = r;
	pivot = A[l];
	while(x<y){
		while(A[x]<=pivot){
			x++;
			count+=2;
		}
		while(A[y]>pivot){
			y--;
			count+=2;
		}
		if(x<y){
			//swap(A[x],A[y]);
			int temp;
			temp = A[x];
			A[x] = A[y];
			A[y] = temp;
		}
		count+=6;
	}
	A[l] = A[y];
	A[y] = pivot;
	return y;
	count+=7;
}
void quick_sort(int A[], int l, int r){
	int p;
	if(l<r){
		p = partition(A,l,r);
		quick_sort(A,l,p-1);
		quick_sort(A,p+1,r);
	}
	count+=4;	
}
void display(int A[],int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d\t",A[i]);
}
int main(){
	//2,7,8,9,1,4,3,5,6,22,34,1,75,45,31,17,23,42,11,60
	int A[] = {1,2,3,4,5,6,7,8,9,22};
	int n = sizeof(A)/sizeof(int);
	printf("The unsorted array is:\n");
	display(A,n);
	printf("\nThe sorted array is:\n");
	quick_sort(A,0,n-1);
	display(A,n);
	printf("\n\nTotal number of steps = %d for size of array = %d",count,n);
}
