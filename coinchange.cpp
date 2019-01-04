#include<stdio.h>

long coin[]={1,5,10,25,50},make,n=5;
long dp[6][110];

long rec(long i,long taken)
{
	long p1,p2;
	if(i==n)
	{
		if(taken==make)
			return 1;
		else
			return 0;
	}
	if(dp[i][taken]!=-1)
		return dp[i][taken];
	if(taken+coin[i]<=make)
		p1=rec(i,taken+coin[i]);
	else 
		p1=0;
	p2=rec(i+1,taken);
	dp[i][taken]=p1+p2;
	return dp[i][taken];
}

int main()
{
	long i,j,fg;
	while(~scanf("%ld",&make))
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<=make;j++)
				dp[i][j]=-1;
		}
		fg=rec(0,0);
		printf("%ld\n",fg);
	}
	return 0;
}