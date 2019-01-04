#include<stdio.h>
long fact(long j)
{
	if(j==1||j==0)
		return 1;
	else
		return j*fact(j-1);
}
long comb(long a,long t)
{
	long j;
	for(j=t-a;j>=0;j--)
	{
		printf(" ");
	}
	for(long i=0;i<=a;i++)
	{
		j=fact(a)/(fact(a-i)*fact(i));
		printf(" %ld ",j);
	}
	printf("\n");
	return 0;
}
int main()
{
	long i,n;
	while(scanf("%ld",&n)==1)
	{
		for(i=0;i<n;i++)
		{
			comb(i,n);
		}
	}
return 0;
}