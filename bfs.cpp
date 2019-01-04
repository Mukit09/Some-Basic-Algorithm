#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

vector<long>ve[510];
queue<long>q;

long visit[510],cst[510],n,e,u,v,p[510],dest;

void bfs(long node)
{
	long u,i,v,l;
	q.push(node);
	l=q.size();
	while(!q.empty())
	{
		v=q.front();
		visit[v]=1;
		for(i=0;i<ve[v].size();i++)
		{
			u=ve[v][i];
			if(!visit[u])
			{
				q.push(u);
				cst[u]=cst[v]+1;
				visit[u]=1;
				p[u]=v;
			}	
		}
		q.pop();
	}
}

int main()
{
	long source,i;
	while(~scanf("%ld%ld",&n,&e))
	{
		for(i=1;i<=n;i++)
		{
			visit[i]=0;
			cst[i]=0;
		}
		for(i=1;i<=e;i++)
		{
			scanf("%ld%ld",&u,&v);
			ve[u].push_back(v);
			ve[v].push_back(u);
		}
		scanf("%ld",&source);
		cst[source]=0;
		bfs(source);
		for(i=1;i<=n;i++)
			printf("%ld\n",cst[i]);
		scanf("%ld%ld",&source,&dest);
		while(1)
		{
			printf("%ld %ld\n",dest,p[dest]);
			dest=p[dest];
			if(p[dest]==source)
			{
				printf("%ld %ld\n",dest,p[dest]);
				break;
			}
		}

	}
	return 0;
}