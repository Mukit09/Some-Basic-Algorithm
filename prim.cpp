#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;

#define SIZE 30

struct edge {

    int u,v,w;
    edge(int a, int b, int c) {

        u=a;
        v=b;
        w=c;
    }

    bool operator <(const edge& p) const {

        return w>p.w;
    }
};

priority_queue<edge>q;
vector<int>ve[SIZE], weight[SIZE];
int isTaken[SIZE], cost;

void prim() {

    int i, l=ve[1].size();
    int u,v,w,tmp,n;
    for(i=0;i<l;i++) {

        q.push(edge(1, ve[1][i], weight[1][i]));
    }
    isTaken[1] = 1;
    while(!q.empty()) {

        edge e=q.top();
        q.pop();
        u=e.u;
        v=e.v;
        w=e.w;

        if(isTaken[u]&&isTaken[v])
            continue;
        if(!isTaken[v])
            tmp=v;
        if(!isTaken[u])
            tmp=u;

        if(!isTaken[tmp]) {

            cost+=w;
            printf("cost: %c %c %d\n", u+96, v+96, w);
            isTaken[tmp] = 1;
            l=ve[tmp].size();
            for(i=0;i<l;i++) {

                n=ve[tmp][i];
                if(!isTaken[n])
                    q.push(edge(tmp, n, weight[tmp][i]));
            }
        }
    }
}

int main() {

    int testCase, n, e,i,u,v,w;
    char src[5], dst[5];
    scanf("%d", &testCase);
    while(testCase--) {

        scanf("%d%d", &n,&e);
        for(i=1;i<=n;i++) {

            ve[i].clear();
            weight[i].clear();
            isTaken[i]=0;
        }
        for(i=1;i<=e;i++) {

            scanf("%s%s%d",src,dst,&w);
            u=src[0]-96;
            v=dst[0]-96;
            ve[u].push_back(v);
            ve[v].push_back(u);
            weight[u].push_back(w);
            weight[v].push_back(w);
        }
        cost=0;
        prim();
        printf("Cost is: %d\n", cost);
    }
    return 0;
}

/*
8 11
a e 2
a b 4
a d 10
b c 18
b d 8
e d 5
c d 11
d g 11
d h 9
g f 1
h f 2

9 11
a i 8
a b 1
a f 5
f g 6
g e 5
b e 2
b c 2
e c 7
g d 4
c d 3
c j 7
*/
