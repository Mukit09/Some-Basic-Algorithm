#include<stdio.h>
#define mod 100000007

long n,i,j,k,x,nway[10010],coin[110],t,y=1;

int main()
{
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&k);
		for(i=1;i<=k;i++)
			nway[i]=0;
		nway[0]=1;
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&coin[i]);
			for(j=coin[i];j<=k;j++)
			{
				x=j-coin[i];
				nway[j]=(nway[x]%mod+nway[j]%mod)%mod;
			}
		}
		printf("Case %ld: %ld\n",y++,nway[k]%mod);
	}
	return 0;
}
		