#include<stdio.h>
#include<vector>
using namespace std;
#define SIZE 30

int vis[SIZE];
int color[SIZE];
vector<int>ve[SIZE];

int dfs(int node, int currentNodeColor) {

    int i, l, u, ret;
    l=ve[node].size();
    color[node]=currentNodeColor;
    for(i=0;i<l;i++) {

        u=ve[node][i];
        if(vis[u]==0) {

            vis[u]=1;
            ret=dfs(u, 1-currentNodeColor);
            if(!ret)
                return ret;
        }
        else if(color[u] == currentNodeColor)
            return 0;
    }
    return 1;
}

int main() {

    int testCase, node, edge, i, u, v;
    scanf("%d", &testCase);
    while(testCase--) {

        scanf("%d%d", &node, &edge);

        for(i = 1;i <=node;i++) {

            vis[i]=0;
            color[i]=-1;
            ve[i].clear();
        }

        for(i = 0; i < edge; i++) {

            scanf("%d%d", &u, &v);
            ve[u].push_back(v);
            ve[v].push_back(u);
        }
        int check=dfs(1, 0);
        if(check) {

            printf("Bipartite\n");
        }
        else {

            printf("Not Bipartite\n");
        }
    }
}

/*
7 9
1 2
1 4
1 6
2 3
3 4
2 7
4 5
6 7
5 6
*/
