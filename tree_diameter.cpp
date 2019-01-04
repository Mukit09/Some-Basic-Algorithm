#include<stdio.h>
#include<vector>
using namespace std;

vector<long>ve[1001];
long visit[1001],n,mx,ii,cst[1001];

void dfs(long node)
{
	visit[node]=1;
	long i,u,l;
	l=ve[node].size();
	for(i=0;i<l;i++)
	{
		u=ve[node][i];
		if(visit[u]==0)
		{
			visit[u]=1;
			cst[u]=cst[node]+1;
			if(mx<cst[u])
			{
				mx=cst[u];
				ii=u;
			}
			dfs(u);
		}
	}
}

int main()
{
	long e,i,u,v;
	while(~scanf("%ld%ld",&n,&e))
	{
		memset(visit,0,sizeof(visit));
		memset(cst,0,sizeof(cst));
		for(i=1;i<=e;i++)
		{
			scanf("%ld%ld",&u,&v);
			ve[u].push_back(v);
			ve[v].push_back(u);
		}
		mx=0;
		dfs(1);
		printf("Max distance between 1 & %ld is %ld.\n",ii,cst[ii]);
		i=ii;
		memset(visit,0,sizeof(visit));
		memset(cst,0,sizeof(cst));
		mx=0;
		dfs(i);
		printf("Max distance between %ld & %ld is %ld.\n",i,ii,cst[ii]);
	}
	return 0;
}

/*

6 5
1 2
1 3
2 4
2 5
5 6
*/
