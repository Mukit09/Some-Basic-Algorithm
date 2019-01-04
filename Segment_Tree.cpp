#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<string>
#include<stdlib.h>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;

// Define Some Variables
#define eps 1e-14
#define si 1000010
#define pi acos(-1.0)
#define inf (1<<30)-1
#define mod 1000000000 //10^9

//Define Some Functions
#define even(a) ((a)%2==0)
#define odd(a) ((a)%2==1)
#define max(a,b) (a>b ?a:b)
#define min(a,b) (a<b ?a:b)
#define sqr(a)((a)*(a))
#define area(x1,y1,x2,y2,x3,y3) (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)) //Area of a triangle
#define dist(x1,y1,x2,y2) (sqr(x1-x2)+sqr(y1-y2)) //Distance between two points
#define mem(a,v) memset(a,v,sizeof(a))
inline bool compare( double a, double b ) { return fabs( a-b ) < 1e-9 ; }
#define fr(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)

typedef long long i64;

i64 dx[]={0,0,1,-1};
i64 dy[]={1,-1,0,0};
i64 i,j,l,n,cs=1,a[si],tree[si*3],ans,u,v;

i64 bmod(i64 a,i64 b)
{
    if(b==0)
        return 1;
    i64 x=bmod(a,b/2);
    x=(x*x)%mod;
    if(b%2==1)
        x=(x*a)%mod;
    return x;
}

i64 gcd(i64 a,i64 b)
{
    while(b>0)
    {
        a%=b;
        a^=b;
        b^=a;
        a^=b;
    }
    return a;
}


i64 lcm(i64 a,i64 b)
{
	return ((a*b)/gcd(a,b));
}

void init(i64 node,i64 l,i64 r)
{
    if(l==r)
    {
        tree[node]=a[l];
        return;
    }
    i64 mid=(l+r)/2;
    i64 lft=node*2;
    i64 rht=node*2+1;
    init(lft,l,mid);
    init(rht,mid+1,r);
    tree[node]=tree[lft]+tree[rht];
}

i64 query(i64 node,i64 l,i64 r)
{
    if(l>v||r<u)
    return 0;
    else if(l>=u&&r<=v)
    return tree[node];
    i64 lft,rht,mid;
    lft=node*2;
    rht=node*2+1;
    mid=(l+r)/2;
    return query(lft,l,mid)+query(rht,mid+1,r);
}

void update_add(i64 node,i64 l,i64 r)
{
    if(l>u||r<u)
    return;
    else if(l==u&&r==u)
    {
        tree[node]+=v;
        return;
    }
    i64 lft,rht,mid;
    mid=(l+r)/2;
    lft=node*2;
    rht=node*2+1;
    update_add(lft,l,mid);
    update_add(rht,mid+1,r);
    tree[node]+=v;
}

void update_del(i64 node,i64 l,i64 r)
{
    if(l>u||r<u)
    return;
    else if(l==u&&r==u)
    {
        tree[node]-=v;
        return;
    }
    i64 lft,rht,mid;
    mid=(l+r)/2;
    lft=node*2;
    rht=node*2+1;
    update_del(lft,l,mid);
    update_del(rht,mid+1,r);
    tree[node]-=v;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
    i64 q;
    char ch;
   	while(~scanf("%lld%lld",&n,&q))
   	{
		fr(i,1,n)
        scanf("%lld",&a[i]);
        init(1,1,n);
        while(q--)
        {
            cin>>ch;
            if(ch=='S') //query
            {
                scanf("%lld%lld",&u,&v);
                u++,v++;
                ans=query(1,1,n);
                printf("%lld\n",ans);
            }
            else if(ch=='G') //addition
            {
                scanf("%lld%lld",&u,&v);
                u++;
                update_add(1,1,n);
            }
            else
            {
                scanf("%lld%lld",&u,&v);
                u++;
                update_del(1,1,n);
            }
        }
    }
   	return 0;
}
