#include <stdio.h>
#include <stdlib.h>

int nextPerm(int a[],int n){
int i=n-1;
if(n==0){
    return 0;
}
while(i>0&&a[i-1]>=a[i]){
    i--;
}
if(i<=0){
    return 0;
}
int j=n-1;
while(a[j]<=a[i-1]){
    j--;
}
int tmp=a[i-1];
a[i-1]=a[j];
a[j]=tmp;

j=n-1;
while(i<j){
    tmp=a[i];
    a[i]=a[j];
    a[j]=tmp;
    i++;
    j--;
}
return 1;

}

int main()
{
    int n,i,j,wt;
    printf("Enter size: ");
    scanf("%d",&n);
    int ind[n];
    for(i=0;i<n;i++){
        ind[i]=i;
    }
    printf("Enter weight of knapsack: ");
    scanf("%d",&wt);
    int w[n];
    int c[n];
    for(i=0;i<n;i++){
        int w1,c1;
        printf("Enter weight ans cost of %d element: ",i+1);
        scanf("%d%d",&w[i],&c[i]);
    }
     //printf("Check point 1");

    int sel[n];
    for(i=0;i<n;i++){
        sel[i]=0;
    }
    int minC=0;
    int w1=0;
    do{
            //printf("Check point 2 ");
            int sel1[n];
        for(i=0;i<n;i++){
            sel1[i]=0;
        }
        w1=0;
        int c1=0;
        i=0;

        while(w1<wt&&i<n){
            if((w1+w[ind[i]])<=wt){
                w1=w1+w[ind[i]];
                c1=c1+c[ind[i]];
                sel1[ind[i]]=1;

            }
            i++;
        }
        if(c1>minC){
            minC=c1;
            for(i=0;i<n;i++){
                sel[i]=sel1[i];
            }

        }


    }while(nextPerm(ind,n)==1);
    printf("Maximum cost is: %d \n",minC);
    for(i=0;i<n;i++){
        printf("%d ",sel[i]);
    }
    return 0;
}
