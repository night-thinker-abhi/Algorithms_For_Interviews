#include <stdio.h>
int coloring(int n,int graph[n][n],int color[], int v,int count){
			//printf("graph %d\n",graph[v][0]);
			for(int j=0;j<count;j++){
				if(graph[count][j]==1&&v==color[j])
					return 0;
			}
	return 1;
}

void backtrack(int col,int n,int graph[n][n],int color[],int min[]){
	if(col==5){
		int count=0;
		for(int j=1;j<5;j++){
			if(color[0]!=color[j])
				count++;
		}
			if(count<min[0])
				min[0]=count;
		return;
	}
	for(int r=0;r<5;r++){
		if(coloring(5,graph,color,r,col)==1){
			color[col]=r;
			backtrack(col+1,5,graph,color,min);
		}
	}

}

int main(){
	int min[1]={6};
	int graph[5][5]={{-1,1,1,1,1},{1,-1,1,1,-1},{1,1,-1,1,-1},{1,1,1,-1,1},{1,-1,-1,1,-1}};
	int color[5]={0};
	backtrack(0,5,graph,color,min);
	printf("%d\n",min[0]);
	return 0;
}