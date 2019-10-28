#include <stdio.h>
#include <stdlib.h>
#define N 10
typedef struct
{
	char v;
	int f,in;
}vertex;

typedef struct
{
	vertex *a;
	int tos,size;
}stack;

typedef struct
{
	int cost,u,v;
}edge;

typedef struct
{
	edge *a;
	int r,max;
}queue;

void init(queue *q,int n)
{
	q->r=-1;
	q->max=n;
	q->a=(edge*)malloc(n*sizeof(edge));
}

int isfull(queue *q)
{
	if(q->r==q->max-1)
		return 1;
	else
		return 0;
}

int isempty(queue *q)
{
	if(q->r==-1)
		return 1;
	else
		return 0;
}
void inits(stack  *s,int n)
{
	s->size=n;
	s->tos=-1;
	s->a=(vertex*)malloc(n*sizeof(vertex));
}

int isemptys(stack *s)
{
	if(s->tos==-1)
		return 1;
	else
		return 0;
}
void push(stack *s,vertex ch)
{
	s->tos++;
	s->a[s->tos]=ch;
	//printf("For push%c \n", ch.v);
}

vertex pop(stack *s)
{
	vertex z;
	if(isemptys(s)==1)
		return;
	else
	{
		z=s->a[s->tos];
		//printf("For pop%c %d %d\n", z.v,z.f,z.in);
		s->tos--;
		return z;
	}
}

void enqueue(queue *q,edge z)
{
	int c,p;
	edge t;
	if(isfull(q)==1)
	{
		printf("Overflow\n");
		return;
	}
	else
	{
		q->r++;
		q->a[q->r]=z;
		c=q->r;
		if(q->r!=0)
		{
			do
			{
				p=(c-1)/2;
				if(q->a[p].cost>q->a[c].cost)
				{
					t=q->a[p];
					q->a[p]=q->a[c];
					q->a[c]=t;
				}
				else
					break;
				c=p;
			}while(c!=0);
		}
	}
}

edge deque(queue *q)
{
	edge z,t;
	int c,p;
	if(isempty(q)==1)
	{
		printf("Underflow\n");
		return;
	}
	else
	{
		z=q->a[0];
		q->a[0]=q->a[q->r--];
		if(q->r>0)
		{
			p=0;
			do
			{
				c=2*p+1;
				if(c>q->r && q->a[c].cost>q->a[c+1].cost)
					c++;
				if(c>=q->r && q->a[p].cost>q->a[c].cost)
				{
				t=q->a[p];
				q->a[p]=q->a[c];
				q->a[c]=t;
				}
				else
					break;
				p=c;
			}while(c<=q->r);

		}
		return z;
	}
}

void addvertex(vertex ver[],int i,char ch)
{
	ver[i].f=0;
	ver[i].v=ch;
	ver[i].in=i;
	printf("The vertex details are %c %d %d\n", ver[i].v,ver[i].f,ver[i].in);
}

int check(int a[][N],vertex ver[],int n)
{
	stack s;
	int cn=0,c,i,j;
	vertex b;
	inits(&s,n*n);
	push(&s,ver[0]);
	do
	{
		b=pop(&s);
		//printf("FUck are u here\n");
		if(ver[b.in].f!=1)
		{
			//printf("%c ",ver[b.in].v );
			ver[b.in].f=1;
			for(c=0;c<n;c++)
			{
				//printf("WHynot%d %d\n",a[b.in][c],ver[b.in].f);

				if(a[b.in][c]!=0&&ver[c].f!=1)
				{
					//printf("WHy\n");
					push(&s,ver[c]);
				}
			}
			return 0;
		}
		else if(ver[b.in].f==1)
			return 1;
	}while(isemptys(&s)==0);
}

void kruskal(int w[][N],vertex ver[],int n)
{
	queue q;
	int i,j;
	int m[N][N]={0};
	edge e;
	init(&q,n*n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d	",w[i][j]);
		printf("\n");
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(w[i][j]!=0)
			{
				printf("IKruskal\n");
				e.cost=w[i][j];
				e.u=i;
				e.v=j;
				w[i][j]=w[j][i]=0;
				enqueue(&q,e);
			}
		}
	}
	while(!isempty(&q))
	{
		e=deque(&q);
		m[e.u][e.v]=m[e.v][e.u]=e.cost;
		if(check(m,ver,n)==1)
		m[e.u][e.v]=m[e.v][e.u]=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(m[i][j]!=0)
			{
				printf("%c---%c=%d\n",ver[i].v,ver[j].v,m[i][j]);
				m[j][i]=0;

			}
		}
	}
}

int main()
{
	int n,i,j,c,k,cos;
	vertex ver[10];
	int w[10][10]={0};
	char ch,dum;
	printf("Enter the number of vertex to be added\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the vertex\n");
		dum=getchar();
		ch=getchar();
		addvertex(ver,i,ch);

	}
	printf("Printing all vertices with details\n");
	for(k=0;k<n;k++)
		printf("The vertex details are %c %d %d\n", ver[k].v,ver[k].f,ver[k].in);
	printf("Enter the edges and cost of each vertex keeping the index of vertex in mind\n");
	do
	{
		printf("Press 1 for adding an edge\n.Press 2 to stop\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("Enter the indexes u want to connect and the cost\n");
				scanf("%d%d%d",&i,&j,&cos);
				w[i][j]=w[j][i]=cos;
				break;
			case 2:
				c=100;
				break;
		}
	}while(c!=100);
	kruskal(w,ver,n);
	return 0;
}
