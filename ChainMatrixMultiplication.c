#include<stdio.h>
int chain(int n, int A[][n], int d[], int i, int j) {
	if(i==j){
		A[i][j]=0;
		return 0;
	}
	if(A[i][j]!=-1){
		return A[i][j];
	}
	int res = 1000000, k;
	for(k=i;k<=j-1;k++){
		int temp = chain(n,A,d,i,k) + chain(n,A,d,k+1,j) + d[i-1]*d[j]*d[k];
		if(temp<res){
			res=temp;
		}		
	}
	A[i][j]=res;
	return res;	
}


int main() {
	int n,i,j;
	printf("Enter no of dimensions: ");
	scanf("%d", &n);
	int d[n];
	int A[n][n];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			A[i][j] = -1;
		}
	}
	printf("Enter %d dimensions seperated by sapce:\n ",n);
	for(i=0;i<n;i++){
		scanf("%d", &d[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i<=j)
				A[i][j]=chain(n,A,d,i,j);
			else
				A[i][j]=-1;
		}
	}
	printf("Result Matrix is:\n");
	for(i=1;i<n;i++){
		for(j=1;j<n;j++){
			printf("%6d",A[i][j]);
		}
		printf("\n");
	}

	return 0;
}
