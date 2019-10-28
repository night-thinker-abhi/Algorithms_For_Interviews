#include<stdio.h>
#define INF 1000000

void dijkstra(int G[5][5], int n, int u) {
	int cost[5][5], dis[5], pred[5];
	int visited[5], count, mindis, next, i, j;
	for(i=0;i<5;i++) {
		for(j=0;j<5;j++) {
			if(G[i][j]==0) {
				cost[i][j] == INF;
			}
			else {
				cost[i][j] = G[i][j];
			}
		}
	}
	for(i=0;i<5;i++) {
		dis[i] = cost[u][i];
		pred[i] = u;
		visited[i] = 0;
	}
	
	dis[u] =0;
	visited[u] = 1;
	count = 1;
	
	while(count<4) {
		mindis = INF;
		for(i=0;i<5;i++) {
			if(dis[i]<mindis && !visited[i]) {
				mindis = dis[i];
				next = i;
			}
		}
		visited[next] = 1;
		for(i=0;i<5;i++) {
			if(!visited[i]){
				if(mindis + cost[next][i]<dis[i]) {
					dis[i] = mindis + cost[next][i];
					pred[i] = next;
				}
			}
		}
		count++;		
	}
	
	for(i=0;i<5;i++) {
		if(i!=u) {
			printf("\nDistance of node %d = %d", i+1, dis[i]);
			printf("\nPath = %d", i+1);
			j =i;
			do{
				j=pred[j];
				printf("<-%d", j+1);
			}while(j!=u);
		}
	}
}

int main() {
	int G[5][5] = {{0, 5, 2, 10, 6}, {5, 0 ,13, 4, INF}, {2, 13, 0 ,9 ,3}, {10, 4, 9, 0 ,4}, {6, INF, 3, 4, 0}};
	int i, j, n, u;
	printf("Enter the starting node: ");
	scanf("%d", &u);
	dijkstra(G, 5, u-1);
	return 0;
	
}