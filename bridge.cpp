#include<stdio.h>
#include<vector>
#define si 110
#define min(a,b) (a<b ?a:b)
using namespace std;
vector<long>ve[si];
long df[si],visit[si],num,cnt;

long dfs(long node,long p)
{
	visit[node]=1;
	df[node]=num++;
	long l=num,i,ll=ve[node].size(),u,rec;
	for(i=0;i<ll;i++)
	{
		u=ve[node][i];
		if(visit[u]==0&&u!=p)
		{
			visit[u]=1;
			rec=dfs(u,node);
			if(rec>=df[node])
				printf("Bridge : %ld %ld\n",node,u);
			l=min(l,rec);
		}
		else if(u!=p)
			l=min(l,df[u]);
	}
	visit[node]=2;
	return l;
}

int main()
{
	long n,e,u,v,i,c;
	while(~scanf("%ld%ld",&n,&e))
	{
		while(e--)
		{
			scanf("%ld%ld",&u,&v);
			ve[u].push_back(v);
			ve[v].push_back(u);
		}
		num=1;
		for(i=1;i<=n;i++)
		{
			if(visit[i]==0)
				dfs(i,-1);
		}
		for(i=1;i<=n;i++)
		{
			ve[i].clear();
			visit[i]=0;
		}
	}
	return 0;
}