#include<stdio.h>
#include<algorithm>
#define si 10
using namespace std;

long n,e,i,u,v,a[si],re[si],p[si],r[si],cost;

struct ss
{
	long cst,beg,end;
}T[si];

bool cmp(ss aa,ss bb)
{
	if(aa.cst<bb.cst) return true;
	return false;
}

long find(long x)
{
	if(p[x]==x)
		return x;
	else return p[x]=find(p[x]);
}

void link(long x,long y)
{
	if(r[x]>=r[y])
		p[y]=x,r[x]++;
	else
		p[x]=y,r[y]++;
}

int main()
{
	while(~scanf("%ld%ld",&n,&e))
	{
		for(i=1;i<=n;i++)
		{
			p[i]=i;
			r[i]=1;
			a[i]=0;
		}
		for(i=0;i<e;i++)
			scanf("%ld%ld%ld",&T[i].beg,&T[i].end,&T[i].cst);
		sort(T,T+e,cmp);
		cost=0;
		for(i=0;i<e;i++)
		{
			u=find(T[i].beg);
			v=find(T[i].end);
			if(u!=v)
			{
				cost+=T[i].cst;
				link(u,v);
			}
		}
		printf("%ld\n",cost);
	}
	return 0;
}
			
