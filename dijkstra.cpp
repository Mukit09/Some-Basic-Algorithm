#include<stdio.h>
#include<vector>
#include<queue>
//#include<priority_queue>
using namespace std;

#define si 1010
#define inf 999999
#define fr(i,a,b) for(i=a;i<=b;i++)

vector<int>ve[si],cst[si];

int i,j,n,m,d[si],par[si];

struct dij
{
    int u,w;
    dij(int a,int b)
    {
        u=a;
        w=b;
    }

    bool operator < (const dij& p) const { return w > p.w;}
};

void dijkstra(int s)
{
    priority_queue<dij>q;
    q.push(dij(s,0));
    d[s]=0;
    int nw,v;
    while(!q.empty())
    {
        dij u=q.top();
        nw=u.u;
        q.pop();
        int l=ve[nw].size();
        fr(i,0,l-1)
        {
            v=ve[nw][i];
            if(d[nw]+cst[nw][i]<d[v])
            {
                d[v]=d[nw]+cst[nw][i];
                par[v]=nw;
                q.push(dij(v,d[v]));
            }
        }
    }
}

void path_prnt(int node)
{
    if(par[node]==-1)
    {
        printf("%d",node);
        return;
    }
    path_prnt(par[node]);
    printf(" %d",node);
}

int main()
{
    int u,v,w;
    while(~scanf("%d%d",&n,&m))
    {
        fr(i,1,n)
        {
            d[i]=inf;
            par[i]=-1;
        }
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&w);
            ve[u].push_back(v);
            ve[v].push_back(u);
            cst[u].push_back(w);
            cst[v].push_back(w);
        }
        scanf("%d",&u);
        dijkstra(u);
        path_prnt(v);
        puts("");
        printf("%d\n",d[v]);
    }
    return 0;
}
