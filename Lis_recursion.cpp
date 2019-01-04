#include<stdio.h>

long val[110],n,dp[110],dir[110],i;

long longest(long u)
{
	if(dp[u]!=-1)
		return dp[u];
	long max=0,v,p;
	for(v=u+1;v<=n;v++)
	{
		if(val[v]>val[u])
		{
			p=longest(v);
			if(p>max)
			{
				max=p;
				dir[u]=v;
			}
		}
	}
	dp[u]=1+max;
	return dp[u];
}

void path_print(long start)
{
	while(1)
	{
		printf(" %ld",val[start]);
		if(dir[start]==-1)
			break;
		start=dir[start];
	}
}

int main()
{
	long start,lis,p;
	while(~scanf("%ld",&n))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&val[i]);
			dp[i]=dir[i]=-1;
		}
		lis=0;
		for(i=1;i<=n;i++)
		{
			p=longest(i);
			printf("From %ld longest path is %ld\n",i,p);
			if(p>lis)
			{
				lis=p;
				start=i;
			}
		}
		printf("LIS = %ld strting point %ld\n",lis,start);
		printf("The sequence is ");
		path_print(start);
		printf("\n");
	}
	return 0;
}
