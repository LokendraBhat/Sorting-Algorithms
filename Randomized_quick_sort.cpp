#include<stdio.h>
#include<stdlib.h>
int count = 0;
int partition(int A[],int l,int r){
	int pivot = A[l];
	int x = l;
	int y = r;
	int temp;
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
int Rand_partition(int A[],int l, int r){
	int m,temp;
	m = rand()%(r-l)+l;
	temp = A[l];
	A[l] = A[m];
	A[m] = temp;
	return partition(A,l,r);
	count+=7;
}

void Rand_QuickSort(int A[],int l,int r){
	if(l<r){
		int p = Rand_partition(A,l,r);
		Rand_QuickSort(A,l,p-1);
		Rand_QuickSort(A,p+1,r);
	}	
	count+=4;
}
void display(int A[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d\t",A[i]);
	}
}
int main(){
	int A[] = {2,7,8,9,1,4,3,5,6,2};
	int n = sizeof(A)/sizeof(int);
	printf("The unsorted array of size %d is:\n",n);
	display(A,n);
	Rand_QuickSort(A,0,n-1);
	printf("\nThe array after Randomized QuickSort:\n");
	display(A,n);
	printf("\nTotal number of steps = %d with array size = %d",count,n);
	return 0;
}
