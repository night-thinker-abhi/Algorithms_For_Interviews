#include<stdio.h>

typedef struct{
	int c[2][2];
}mat;

mat mul(int a[2][2],int b[2][2]){
	int p=(a[0][0]+a[1][1])*(b[0][0]+b[1][1]);
	int q=b[0][0]*(a[1][0]+a[1][1]);
	int r=a[0][0]*(b[0][1]-b[1][1]);
	int s=a[1][1]*(b[1][0]-b[0][0]);
	int t=b[1][1]*(a[0][0]+a[0][1]);
	int u=(a[1][0]-a[0][0])*(b[0][0]+b[0][1]);
	int v=(a[0][1]-a[1][1])*(b[1][1]+b[1][0]);
	mat x;
	x.c[0][0]=p+s-t+v;
	x.c[0][1]=r+t;
	x.c[1][0]=q+s;
	x.c[1][1]=p+r-q+u;
	return x;

}

mat add(int a[2][2],int b[2][2]){
	int i,j;
	mat x;
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
			x.c[i][j]=a[i][j]+b[i][j];
	return x;
}

void main(){
	int i,j,a[4][4],b[4][4],c[4][4];
	printf("\nEnter the 1st matrix\n");
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			scanf("%d",&a[i][j]);
printf("\nEnter the 2nd matrix\n");
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			scanf("%d",&b[i][j]);

printf("\nFirst Matrix:\n");
for(i=0;i<4;i++){
		for(j=0;j<4;j++)
		    printf("%d  ",a[i][j]);
		printf("\n");}

printf("\nSecond Matrix:\n");
for(i=0;i<4;i++){
		for(j=0;j<4;j++)
		    printf("%d  ",b[i][j]);
		printf("\n");}

int d[2][2],e[2][2],f[2][2],g[2][2],h[2][2],k[2][2],l[2][2],m[2][2];
for(i=0;i<2;i++)
	for(j=0;j<2;j++)
		d[i][j]=a[i][j];
for(i=0;i<2;i++)
	for(j=0;j<2;j++)
		e[i][j]=a[i][j+2];
for(i=0;i<2;i++)
	for(j=0;j<2;j++)
		f[i][j]=a[i+2][j];
for(i=0;i<2;i++)
	for(j=0;j<2;j++)
		g[i][j]=a[i+2][j+2];
for(i=0;i<2;i++)
	for(j=0;j<2;j++)
		h[i][j]=b[i][j];
for(i=0;i<2;i++)
	for(j=0;j<2;j++)
		k[i][j]=b[i][j+2];
for(i=0;i<2;i++)
	for(j=0;j<2;j++)
		l[i][j]=b[i+2][j];
for(i=0;i<2;i++)
	for(j=0;j<2;j++)
		m[i][j]=b[i+2][j+2];
mat x,y,c1,c2,c3,c4;
x=mul(d,h);
y=mul(e,l);
c1=add(x.c,y.c);
x=mul(d,k);
y=mul(e,m);
c2=add(x.c,y.c);
x=mul(f,h);
y=mul(g,l);
c3=add(x.c,y.c);
x=mul(f,k);
y=mul(g,m);
c4=add(x.c,y.c);
printf("\nThe output is:\n");
for(i=0;i<2;i++){
	for(j=0;j<2;j++)
		printf("%d  ",c1.c[i][j]);
	for(j=0;j<2;j++)
	printf("%d  ",c2.c[i][j]);
	printf("\n");
}
for(i=0;i<2;i++){
	for(j=0;j<2;j++)
		printf("%d  ",c3.c[i][j]);
	for(j=0;j<2;j++)
	printf("%d  ",c4.c[i][j]);
	printf("\n");
}

}