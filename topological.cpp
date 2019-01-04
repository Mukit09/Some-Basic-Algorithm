#include<stdio.h>
#include<queue>

using namespace std;

queue<long>q;

long a[1000][1000],in[1000];

int main()
{
	long i,j,n,e,u,v,flag,x;
	printf("How many nodes & edga :\n");
	while(scanf("%ld%ld",&n,&e)==2)
	{
		flag=0;
		for(i=1;i<=n;i++)
			in[i]=0;

		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i==j)
				{
					a[i][j]=0;
				}
				else
				{
					a[i][j]=999999999;
				}
			}
		}

		printf("Take the edges :\n");
		for(i=1;i<=e;i++)
		{
			scanf("%ld%ld",&u,&v);
			a[u][v]=1;
			in[v]++;
		}
		for(i=1;i<=n;i++)
		{
			if(in[i]==0)
			{
				q.push(i);
				flag=1;
				break;
			}
		}
	
		j=q.size();
		printf("The sequence :\n");
		while(flag&&q.empty()==0)
		{
			x=q.front();
			printf("%ld ",x);
			q.pop();
			for(i=1;i<=n;i++)
			{
				if(a[x][i]==1)
				{
					in[i]--;
					if(in[i]==0)
					{
						q.push(i);
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}