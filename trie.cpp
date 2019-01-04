#include<stdio.h>
#include<algorithm>
#include<string.h>

struct node
{
    bool ok;
    node *nxt[30];

    node()
    {
        int i;
        ok=false;
        for(i=0;i<26;i++)
        nxt[i]=0;
    }
}*root;

char ch[50];
int n,l;

void insert()
{
    int i,j;
    node *nw=root;
    for(i=0;i<l;i++)
    {
        j=ch[i]-97;
        if(!nw->nxt[j])
        nw->nxt[j]=new node();
        nw=nw->nxt[j];
    }
    nw->ok=true;
}

int check()
{
    int i,j;
    node *nw=root;
    for(i=0;i<l;i++)
    {
        j=ch[i]-97;
        if(!nw->nxt[j])
        return false;
        nw=nw->nxt[j];
    }
    return nw->ok;
}

void del(node *cur)
{
    int i;
    for(i=0;i<26;i++)
    {
        if(cur->nxt[i])
        del(cur->nxt[i]);
    }
    delete(cur);
}

int main()
{
    int i;
    while(scanf("%d",&n)==1)
    {
        root= new node();
        for(i=1;i<=n;i++)
        {
            scanf("%s",ch);
            l=strlen(ch);
            insert();
        }
        int q;
        scanf("%d",&q);
        while(q--)
        {
            scanf("%s",ch);
            l=strlen(ch);
            bool ans=check();
            if(ans)
            puts("YES");
            else
            puts("NO");
        }
        del(root);
    }
    return 0;
}
