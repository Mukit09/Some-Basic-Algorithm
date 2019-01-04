#include<stdio.h>

int main()
{
	long q[1000][100],i,j,k,node,edge,u,v,weight;

	printf("How many nodes & edge ???\n");

	scanf("%ld%ld",&node,&edge);
	for(i=1;i<=node;i++)
	{
		for(j=1;j<=node;j++)
		{
			q[i][j]=999999;
			q[j][i]=999999;
		}
	}

	printf("Give input of the nodes & their weight: \n");

	for(i=1;i<=edge;i++)
	{
		scanf("%ld%ld%ld",&u,&v,&weight);
		q[u][v]=weight;
		q[v][u]=weight;
	}

	for(k=1;k<=node;k++)
	{
		for(i=1;i<=node;i++)
		{
			for(j=1;j<=node;j++)
			{
				if(q[i][j]>(q[i][k]+q[k][j]))
				{
					q[i][j]=q[i][k]+q[k][j];
				}
			}
		}
	}

	printf("Give the nodes:\n");
	while(scanf("%ld%ld",&u,&v)==2)
	{
		printf("The minimum cost from node %ld to %ld is: %ld\n",u,v,q[u][v]);
	}
	return 0;
}




