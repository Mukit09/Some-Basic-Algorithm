#include<stdio.h>
#include<math.h>
#define size 50

long a[size],pr[size],count[size];

int main()
{
	long i,j,k=1,re[1000],n;
	a[1]=1;
	for(i=3;i<=size;i+=2)
	{
		if(a[i]==0)
		{
			for(j=i;j<=sqrt(size);j+=2*i)
			{
				a[j]=1;
			}
		}
	}
	j=1;
	pr[j++]=2;
	for(i=3;i<=size;i+=2)
	{
		if(a[i]==0)
			pr[j++]=i;
	}
	while(~scanf("%ld",&n))
	{
		long flag,m=n;
		j=1;
		for(i=1;pr[i]<=sqrt(m);i++)
		{
			flag=0;
			if(n%pr[i]==0)
			{
				if(!flag)
				{
					flag=1;
					re[j]=pr[i];
				}
				while(n%pr[i]==0)
				{
					count[j]++;
					n/=pr[i];
				}
				flag=0;
				j++;
			}
		}
		for(i=1;i<j;i++)
		{
			printf("%ld^%ld ",re[i],count[i]);
		}
		printf("\n");
	}
	return 0;
}
