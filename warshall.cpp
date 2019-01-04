//This code determines if I can go one node to anather !!!!

#include<stdio.h>

int main()
{
	long i,j,k,a[1000][100],u,v,p[1000][100],edge,node;
	scanf("%ld%ld",&node,&edge);
	for(i=1;i<=node;i++)
	{
		for(j=1;j<=node;j++)
		{
			a[i][j]=0;
		}
	}

	for(i=1;i<=edge;i++)
	{
		scanf("%ld%ld",&u,&v);
		a[u][v]=1;
	}
	for(i=1;i<=node;i++)
	{
		for(j=1;j<=node;j++)
		{
			if(a[i][j]==0)
				p[i][j]=0;
			else
				p[i][j]=1;
		}
	}
	for(k=1;k<=node;k++)
	{
		for(i=1;i<=node;i++)
		{
			for(j=1;j<=node;j++)
			{
				if(p[i][j]==0)
				{
					if(p[i][k]==1&&p[k][j]==1)
					{
						p[i][j]=1;
					}
				}
			}
		}
	}
	printf("Give the inputs:\n");
	while(scanf("%ld%ld",&u,&v)==2)
	{
		printf("%ld\n",p[u][v]);
		if(p[u][v])
			printf("Possible !!!\n");
		else
			printf("Impossible !!!\n");
		
	}
	return 0;
}
