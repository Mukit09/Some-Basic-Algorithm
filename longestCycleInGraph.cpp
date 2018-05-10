#include<stdio.h>
#include<vector>
using namespace std;

#define SIZE 30
#define inf -99999
#define max(a,b) (a>b?a:b)

vector<int>ve[SIZE];
char store[SIZE][SIZE];
int vis[SIZE],recStack[SIZE],mx;

bool cycleLength(int v, int cnt)
{
    bool ret=false;
    if(vis[v] == false)
    {
        int l=ve[v].size();
        int u,i;
        vis[v] = true;
        recStack[v] = true;

        for(i = 0; i<l; i++)
        {
            u=ve[v][i];
            if ( !vis[u] && cycleLength(u, cnt+1)) {

                mx=max(mx,cnt+1);
                ret=true;
            }
            else if (recStack[u]){

                mx=max(mx,cnt);
                ret=true;
            }
        }
    }
    recStack[v] = false;  // remove the vertex from recursion stack
    return ret;
}

int main() {

    char src[10], dst[10];
    int testCase,i,j,n,e,u,v;
    scanf("%d",&testCase);
    while(testCase--) {

        scanf("%d%d",&n,&e);
        for(i=1;i<=n;i++) {

            vis[i]=0;
            recStack[i]=0;
            ve[i].clear();
        }

        while(e--) {

            scanf("%s%s",src,dst);
            u=src[0]-96;
            v=dst[0]-96;
            ve[u].push_back(v);
        }
        mx=-1;
        bool isFound=false;
        for(i=1;i<=n;i++) {

            isFound|=cycleLength(i,0);
            for(j=1;j<=n;j++)
                vis[j]=0;
        }
        printf("%d\n", mx);
    }
    return 0;
}
