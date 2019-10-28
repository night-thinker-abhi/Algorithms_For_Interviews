#include<stdio.h>
#include<stdlib.h>

int main(){
	int n,b=1,i=0,j=0;
	printf("Enter the number of jobs: ");
	scanf("%d",&n);
	int s[n],f[n],a[n];
	a[0]=1;
	for(i=0;i<n;i++)
	{
		printf("Enter the start and finish time of job %d :",i+1);
		scanf("%d %d", &s[i], &f[i]);
	}
	j=0;
	for(i=1;i<n;i++){
		if(s[i]>=f[j]){
			a[b++]=i+1;
			j=i;
		}			
	}
	for(i=0;i<b-1;i++)
		printf("%d ->",a[i]);
	printf("%d ->",a[b-1]);
	return 0;		
} 
