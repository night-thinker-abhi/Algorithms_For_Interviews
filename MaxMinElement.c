#include <stdio.h>
#include <stdlib.h>

typedef struct maxmin{
    int min,max;
}pair;

pair getmaxmin(int a[],int l,int r){
    pair k,x,y;
    if(l==r){
        k.max=a[l];
        k.min=a[l];
        return k;
    }
        int mid=(l+r)/2;
         x=getmaxmin(a,l,mid);
         y=getmaxmin(a,mid+1,r);
        if(x.max>y.max)
            k.max=x.max;
        else
            k.max=y.max;
        if(x.min<y.min)
            k.min=x.min;
        else
            k.min=y.min;
        return k;
}
int main()
{
    pair a;
    int i,n;
    printf("Enter the number of elements in array\n");
    scanf("%d",&n);
    int A[n];
    printf("Enter the elements of array\n");
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    a=getmaxmin(A,0,n-1);
    printf("\nMaximum: %d\n",a.max);
    printf("\nMinimum: %d\n",a.min);
    return 0;
}
