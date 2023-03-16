#include<stdio.h>
int count = 0;
void display(int A[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d\t",A[i]);
	}
}
void heapify(int A[],int i,int n){
	int l,r,largest;
	l = 2*i+1;
	r = 2*i+2;
	largest = i;
	if(l<n && A[l]>A[largest]){
		largest = l;
	}
	if(r<n && A[r]>A[largest]){
		largest = r;
	}
	if(largest!=i){
		int temp;
		temp = A[i];
		A[i]= A[largest];
		A[largest] = temp;
		heapify(A,largest,n);
	}	
	count +=10;
}
void build_heap(int A[],int n){
	int i;
	for(i=(n/2)-1;i>=0;i--){
		heapify(A,i,n);
	}
	count += 4;
}
void heap_sort(int A[],int n){
	int i;
	build_heap(A,n);
	for(i=n-1;i>0;i--){
		int temp;
		temp = A[0];
		A[0] = A[i];
		A[i] = temp;
		heapify(A,0,i);
		count+=7;
	}
	count+=1;
}
int main(){
	int A[] = {2,1,3,5,4,7};
	int n = sizeof(A)/sizeof(int);
	printf("The unsorted array is: \n");
	display(A,n);
	printf("\nThe sorted array is: \n");
	heap_sort(A,n);
	display(A,n);
	printf("\nTotal steps to complete heap_sort: %d",count);
	return 0;
}
