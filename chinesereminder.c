#include<stdio.h>
int main()
{
	long i,k,l,r[1000],m[1000],n,sum=1,s,w=0;
	scanf("%ld",&n);
	for(i=1;i<=n;i++)
	{
        scanf("%ld%ld",&r[i],&m[i]);
	}
	for(i=1;i<=n;i++)
	{
		sum=sum*m[i];
	}
	for(i=1;i<=n;i++)
	{
		k=sum/m[i];
        s=k%m[i];
		w=w+(r[i]*s*k);
	}
	l=w%sum;
	printf("%ld %ld %ld\n",l,w,sum);
	return 0;
}