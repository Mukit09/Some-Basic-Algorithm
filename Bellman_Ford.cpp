#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

#define si 110
#define inf 999999

vector<int>ve[si];

struct ss
{
    int u,v,w;
}stru[si];

int d[si];

int main()
{
    int n,m,i,j,u,v,w,fg;
    while(~scanf("%d%d",&n,&m))
    {
        fg=1;
        for(i=1;i<=n;i++)
        d[i]=inf;

        int s;

        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d",&stru[i].u,&stru[i].v,&stru[i].w);
        }
        scanf("%d",&s);
        d[s]=0;

        for(i=1;i<n;i++)
        {
            for(j=1;j<=m;j++)
            {
                u=stru[j].u;
                v=stru[j].v;
                w=stru[j].w;

                if(d[u]+w<d[v])
                d[v]=d[u]+w;
            }
        }

        for(i=1;i<=m;i++)
        {
            u=stru[j].u;
            v=stru[j].v;
            w=stru[j].w;

            if(d[u]+w<d[v])
            {
                fg=0;
                break;
            }
        }
        if(!fg)
        puts("Negative Cycle exists....");

        for(i=1;i<=n;i++)
        printf("%d\n",d[i]);
    }
    return 0;
}
