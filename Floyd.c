#include<stdio.h>
#define INF 10000000

void Floyd(int W[5][5]) {
	int n = 5, i, j, k, D[5][5];
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			D[i][j] = W[i][j];
		}
	}
	
	for(k=0;k<n;k++) {
		for(i=0;i<n;i++) {
			for(j=0;j<n;j++) {
				if(D[i][j] > D[i][k] + D[k][j]) {
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			printf("%d\t", D[i][j]);
		}
		printf("\n");
	}
	
	
	
}

int main() {
	int W[5][5] = {{0, 3, 8, INF, -4},{INF, 0, INF, 1, 7}, {INF, 4, 0, INF, INF}, {2, INF, 5, 0, INF}, {INF, INF, INF, 6, 0}};
	Floyd(W);
	return 0;
}