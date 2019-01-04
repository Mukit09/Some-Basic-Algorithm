#include<stdio.h>
#include<vector>
#define si 100010
#define min(a,b) (a<b?a:b)
using namespace std;

vector<long>ve[si];
long dp[si][5],par[si],n;

long rec(long node,long fg)         //fg=1 means,node e paharadar ache,fg=0 hole nai 
{
	if(ve[node].size()==0)
		return 0;
	if(dp[node][fg]!=-1)
		return dp[node][fg];
	long sm=0,i,u,p1,p2;
	for(i=0;i<ve[node].size();i++)
	{
		u=ve[node][i];
		if(u!=par[node])
		{
			par[u]=node;
			if(fg==0)
				sm+=rec(u,1);
			else
			{
				p1=rec(u,1);
				p2=rec(u,0);
				sm+=min(p1,p2);
			}
		}
	}
	dp[node][fg]=sm+fg;
	return dp[node][fg];
}


int main()
{
	long u,v,i,sm,p1,p2;
	while(~scanf("%ld",&n))
	{
		for(i=1;i<n;i++)
		{
			scanf("%ld%ld",&u,&v);
			ve[u].push_back(v);
			ve[v].push_back(u);
			dp[i][1]=dp[i][0]=-1;
			par[i]=-1;
		}
		dp[n][1]=dp[n][0]=-1;
		par[n]=-1;
		sm=0;
		p1=rec(1,1);
		p2=rec(1,0);
		sm+=min(p1,p2);
		
		printf("%ld\n",sm);
		for(i=1;i<=n;i++)
			ve[i].clear();
	}
	return 0;
}
