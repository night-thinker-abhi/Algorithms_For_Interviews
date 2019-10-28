#include<stdio.h>
#include<conio.h>

int m=0,n=4;

int cal(int temp[10][10],int t[10][10])
{
	int i,j,m=0;
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
		{
			if(temp[i][j]!=t[i][j])
			m++;
		}
	return m;
}

int check(int a[10][10],int t[10][10])
{
	int i,j,f=1;
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			if(a[i][j]!=t[i][j])
				f=0;
	return f;
}


int main()
{
    printf("----------------------\n");
    printf("----15 PUZZLE GAME----\n");
    printf("----------------------\n");
	int i,j,n=4,a[10][10],t[10][10],temp[10][10],r[10][10];
	int m=0,x=0,y=0,d=1000,dmin=0,l=0,pos=1,z=0,v=0;
	printf("\nEnter the matrix to be solved,space with zero :\n");
	for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("Position %d:",pos);
            scanf("%d",&a[i][j]);
            if((a[i][j]>15)||(a[i][j])<0)
            {
                j--;
                pos=pos-1;
                printf("Enter number between 0 and 15!\n");
            }
            if(a[i][j]==0)
            {
                z=i;
                v=j;
            }
            pos=pos+1;
        }
    }
	pos=1;
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
        {
            t[i][j]=pos;
            pos=pos+1;
        }
    t[3][3]=0;
    int f=0;
    a[z][v]=16;
    if((a[0][1]==16)||(a[0][3]==16)||(a[1][0]==16)||(a[1][2]==16)||(a[2][1]==16)||(a[2][3]==16)||(a[3][0]==16)||(a[3][2]==16))
    {
        f=1;
    }
    int p=0,k=0,q=0,pos1=0,pos2=1;
    l=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            p=a[i][j]-1;
            pos1=pos1+1;
            pos2=1,q=0;
            for(k=0;k<4;k++)
            {
                for(q=0;q<4;q++)
                {
                    if((a[k][q]<=p)&&(pos2>pos1))
                    {
                        l=l+1;
                    }
                    pos2++;
                }
            }
        }
    }
    l=l+f;
    a[z][v]=0;
    printf("\nSummation of less(i)+ x =%d",l);
    if((l%2)==0)
    {
        printf("\nSolution is possible!!\n");
    }
    else
    {
        printf("\nSolution is not possible!!!\n");
        return 0;
    }
    printf("\nTarget Matrix is :\n");
	for(i=0;i < n;i++)
	{
		for(j=0;j < n;j++)
			printf("%d\t",t[i][j]);
		printf("\n");
	}
	printf("\n\nInitial State is :\n");
	for(i=0;i < n;i++)
	{
		for(j=0;j < n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
    l=0;
	while(!(check(a,t)))
	{
		l++;
		d=1000;
		for(i=0;i < n;i++)
			for(j=0;j < n;j++)
			{
				if(a[i][j]==0)
				{
					x=i;
					y=j;
				}
			}

		//To move upwards
		for(i=0;i < n;i++)
			for(j=0;j < n;j++)
				temp[i][j]=a[i][j];

		if(x!=0)
		{
			p=temp[x][y];
			temp[x][y]=temp[x-1][y];
			temp[x-1][y]=p;
		}
		m=cal(temp,t);
		dmin=l+m;
		if(dmin < d)
		{
			d=dmin;
			for(i=0;i < n;i++)
				for(j=0;j < n;j++)
					r[i][j]=temp[i][j];
		}

		//To move downwards
		for(i=0;i < n;i++)
			for(j=0;j < n;j++)
				temp[i][j]=a[i][j];
		if(x!=n-1)
		{
			p=temp[x][y];
			temp[x][y]=temp[x+1][y];
			temp[x+1][y]=p;
		}
		m=cal(temp,t);
		dmin=l+m;
		if(dmin < d)
		{
			d=dmin;
			for(i=0;i < n;i++)
				for(j=0;j < n;j++)
					r[i][j]=temp[i][j];
		}

		//To move right side
		for(i=0;i < n;i++)
			for(j=0;j < n;j++)
				temp[i][j]=a[i][j];
		if(y!=n-1)
		{
			p=temp[x][y];
			temp[x][y]=temp[x][y+1];
			temp[x][y+1]=p;
		}
		m=cal(temp,t);
		dmin=l+m;
		if(dmin < d)
		{
			d=dmin;
			for(i=0;i < n;i++)
				for(j=0;j < n;j++)
					r[i][j]=temp[i][j];
		}

		//To move left
		for(i=0;i < n;i++)
			for(j=0;j < n;j++)
				temp[i][j]=a[i][j];
		if(y!=0)
		{
			p=temp[x][y];
			temp[x][y]=temp[x][y-1];
			temp[x][y-1]=p;
		}
		m=cal(temp,t);
		dmin=l+m;
		if(dmin < d)
		{
			d=dmin;
			for(i=0;i < n;i++)
				for(j=0;j < n;j++)
					r[i][j]=temp[i][j];
		}
        printf("Minimum cost : %d\n",d-1);
		printf("\nCalculated Intermediate Matrix Value :\n");
		for(i=0;i < n;i++)
		{
			for(j=0;j < n;j++)
			  printf("%d\t",r[i][j]);
			printf("\n");
		}
		for(i=0;i < n;i++)
			for(j=0;j < n;j++)
			{
			  a[i][j]=r[i][j];
			  temp[i][j]=0;
			}
	}
	printf("\nTARGET REACHED!!!");
	return 0;
}