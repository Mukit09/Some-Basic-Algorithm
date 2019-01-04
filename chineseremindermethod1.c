#include<stdio.h>
int main()
{
	long i,k,r[1000],m[1000],n,sum=1,q,w=0,j=1;
	scanf("%ld",&n);
	for(i=1;i<=n;i++)
	{
        scanf("%ld%ld",&r[i],&m[i]);
	}
	for(i=1;i<=2;i++)
	{
		sum*=m[i];
	}
	q=sum;
	for(i=1;i<=sum;i++)
	{
		if((i%m[2]==r[2])&&(i%m[1]==r[1]))
		{
			k=i;
		}
	}
    for(i=3;i<=n;i++)
	{
		 sum*=m[i];
	}
	for(i=1;i<=sum;i++)
	{
		if((i%q==k)&&(i%m[3]==r[3]))
		{
			j=i;
		}
	}
	printf("%ld\n",j);
	return 0;
}