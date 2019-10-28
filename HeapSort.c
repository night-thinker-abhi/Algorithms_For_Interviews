#include<stdio.h>

void buildheap(int A[], int n) {
	int i, c, temp, p;
		for(i=1;i<n;i++) {
			c = i;
			do {
				p =(c-i)/2;
				if(A[c] > A[p]) {
					temp = A[i];
					A[i] = A[p];
					A[p] = temp;
				}
				else {
					break;
				}
				c = p;
			}while(c!=0);
		}

}

void delheap(int A[], int n) {
	int i, temp;
	for(i=n-1;i>0;i--) {
		temp = A[i];
		A[i] = A[0];
		A[0] = temp;
		buildheap(A, i);
	}
}

void heapsort(int A[], int n) {
	buildheap(A, n);
	delheap(A, n);
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
	heapsort(Arr, n);
	printf("\nSorted Array: ");
	for(i=0;i<n;i++) {
		printf("%d ", Arr[i]);
	}
	return 0;
}
