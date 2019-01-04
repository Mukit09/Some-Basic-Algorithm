#include<stdio.h>  

long w[1000],m,x[1000],i,sum=0,n;
void subset(long s,long k,long r)
{
	x[k]=1;
	if(s+w[k]==m)
    {
		for(i=0;i<=n;i++)
		{
			if(x[i]==1)
			printf("%ld ",w[i]);
		}
		printf("\n");
	}
	else if(s+w[k]+w[k+1]<=m)
		subset(s+w[k],k+1,r-w[k]);
    if((s+r-w[k]>=m)&&(s+w[k+1])<=m)
    {               
		x[k]=0;
		subset(s,k+1,r-w[k]);
    }
}
int main()
{
    while(scanf("%ld%ld",&n,&m)==2)
	{
		for(i=1; i<=n; i++)
			scanf("%d",&w[i]);
			sum +=w[i];
		printf("The solution is\n");
		subset(0,1,sum);
	}
    return 0;
}
