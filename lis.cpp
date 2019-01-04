#include<stdio.h>
int main()
{
	long m[1000],x[1000],src[1000],seq[1000],n,k,max,i,j;
	while(scanf("%ld",&n)!=EOF)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&x[i]);
			m[i]=1;
		}
		max=1;
		k=1;
		for(i=2;i<=n;i++)
		{
			for(j=1;j<i;j++)
			{
				if(x[j]<x[i])
				{
					if(m[j]+1>m[i])
					{
						m[i]=m[j]+1;
						src[i]=j;
					}
					if(m[i]>max)
					{
						max=m[i];
						k=i;
					}
				}
			}
		}
		i=k;
		j=0;
		while(1)
		{
			seq[j]=i;
			j++;
			if(m[i]==1) break;
			else i=src[i];
		}
		printf("%ld\n",max);
		for(i=j-1;i>=0;i--)
			printf("%ld ",x[seq[i]]);
		printf("\n");
	}
	return 0;
}