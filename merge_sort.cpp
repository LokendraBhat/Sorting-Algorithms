#include<stdio.h>
int count = 0;
void merge(int A[],int l,int m,int r){
	int B[r+1];
	int k=l;
	int x=l;
	int y=m;
	count+=4;
	while(x<m&&y<=r){
		if(A[x]<A[y]){
			B[k] = A[x];
			x++;
			count+=3;
		}
		else{
			B[k] = A[y];
			y++;
			count+=3;
		}
		k++;
		count+=2;
	}
	while(x<m){
		B[k] = A[x];
		k++;
		x++;
		count+=5;
	}
	while(y<=r){
		B[k] = A[y];
		k++;
		y++;
		count+=5;
	}
	for(k=l;k<r+1;k++){
		A[k] = B[k];
		count+=5;
	}
}
void merge_sort(int A[],int l, int r){
	if(l<r){
		int m = (l+r)/2;
		merge_sort(A,l,m);
		merge_sort(A,m+1,r);
		merge(A,l,m+1,r);
	}
	count+=6;
}
void display(int A[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d\t",A[i]);
	}
}
int main(){
	int A[]= {2,7,8,9,1,4,3,5,6,22,34,1,75,45,31,17,23,42,11,60};
	int n = sizeof(A)/sizeof(int);
	printf("The unsorted array is: \n");
	display(A,n);
	
	merge_sort(A,0,n-1);
	printf("\n\nThe sorted array after Merge Sort: \n");
	display(A,n);
	printf("\n\nNumber of steps = %d with size of array = %d\n",count,n);
}
