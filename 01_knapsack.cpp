#include<stdio.h>

long dp[110][1100],mx,n,w[110],cost[110],dir[111][11111];

long rec(long i,long taken)
{
	if(i>n)
		return 0;
	if(taken>mx)
		return 0;
	if(dp[i][taken]!=-1)
		return dp[i][taken];
	long p1=0,p2;
	if(taken+w[i]<=mx)
		p1=cost[i]+rec(i+1,w[i]+taken);
	p2=rec(i+1,taken);
	if(p1>p2)
	{
		dp[i][taken]=p1;
		dir[i][taken]=1;
	}
	else
	{
		dp[i][taken]=p2;
		dir[i][taken]=2;
	}
	return dp[i][taken];
}

void path_print(long i,long taken)
{
	if(i>n)
		return ;
	if(dir[i][taken]==-1)
		return ;
	if(dir[i][taken]==1)
	{
		printf("%ld ",cost[i]);
		path_print(i+1,taken+w[i]);
	}
	else
		path_print(i+1,taken);
}

int main()
{
	long i,re,j;
	while(~scanf("%ld",&n))
	{
		scanf("%ld",&mx);
		for(i=1;i<=n;i++)
		{
			scanf("%ld%ld",&w[i],&cost[i]);
			for(j=0;j<=mx;j++)
			{
				dir[i][j]=-1;
				dp[i][j]=-1;
			}
		}	
		re=rec(1,0);
		printf("%ld\n",re);
		path_print(1,0);
	}
	return 0;
}