#include<stdio.h>
#include<math.h>
#define si 100000010
#define pr_si 100010

int ara[si/32],pr[pr_si],ll=1;

int check(int m,int pos)
{
	return (m&(1<<pos));
}

int set(int m,int pos)
{
	return (m|(1<<pos));
}

void sieve()
{
	int i,j,num=si-5,root=sqrt(num);
	pr[ll++]=2;
	ara[0/32]=ara[1/32]=1;
	for(i=3;i<=num;i+=2)
	{
		if(check(ara[i/32],i%32)==0)
		{
			pr[ll++]=i;
			if(i<=root)
			{
				for(j=i*i;j<=num;j+=2*i)
					ara[j/32]=set(ara[j/32],j%32);
			}
			printf("%d\n",i);
		}
	}
}

int main()
{
	sieve();
	return 0;
}