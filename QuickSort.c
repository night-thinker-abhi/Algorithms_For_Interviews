#include<stdio.h>

int partition(int A[], int p, int r) {
	int x, i, j, temp, temp2;
	x = A[r];
	i = p-1;
	for(j=p;j<r;j++) {
		if(A[j] <= x) {
			i = i+1;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	temp2 = A[r];
	A[r] = A[i+1];
	A[i+1] = temp2;
	return i+1;
}
void quicksort(int A[], int p, int r) {
	if(p<r) {
		int q = partition(A, p, r);
		quicksort(A, p, q-1);
		quicksort(A, q+1, r);
	}	
}

int main() {
	int Arr[50];
	int n, i;
	printf("Enter the size of Array: ");
	scanf("%d", &n);
	printf("Enter the elements of Array:\n");
	for(i=0;i<n;i++) {
		scanf("%d", &Arr[i]);
	}
	printf("\nOriginal Array: ");
	for(i=0;i<n;i++) {
		printf("%d ", Arr[i]);
	}
	quicksort(Arr, 0, n-1);
	printf("\nSorted Array: ");
	for(i=0;i<n;i++) {
		printf("%d ", Arr[i]);
	}
	return 0;
}