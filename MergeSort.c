#include <stdio.h>
#include <stdlib.h>

void merge(int A[],int l,int m,int r)
{
    int i,j,k,a,b;
    a=m-l+1;
    b=r-m;

    int L[a],R[b];

    for(i=0;i<a;i++)
        L[i]=A[l+i];
    for(j=0;j<b;j++)
        R[j]=A[m+1+j];

    i=0;j=0;k=l;

    while(i<a && j<b)
    {
        if(L[i]<= R[j])
        {
                A[k]=L[i];
                i++;
        }
        else
        {
            A[k]=R[j];
            j++;
        }
        k++;
    }

     while(i<a)
     {
         A[k]=L[i];
         i++;
         k++;
     }

     while(j<b)
     {
         A[k]=R[j];
         j++;
         k++;
     }
}

void merge_sort(int A[],int l,int r)
{
    if(l<r)
    {
        int m = l+(r-l)/2;
        merge_sort(A,l,m);
        merge_sort(A,m+1,r);
        merge(A,l,m,r);

    }
}

int main()
{
  int n,i,A[20];
  printf("Enter the value of n: ");
  scanf("%d",&n);
  printf("The given array is: ");
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
  printf("\n");
  merge_sort(A,0,n-1);
  printf("The sorted array is: ");
  for(i=0;i<n;i++)
    printf("%d ",A[i]);

    return 0;
}
