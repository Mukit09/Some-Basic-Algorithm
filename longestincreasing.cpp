#include<stdio.h>

long i,j,n,a[10],l[10],max,re[10],id;
int main()
{
	while(~scanf("%ld",&n))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&a[i]);
			l[i]=1;
		}
		max=0;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if(a[i]<a[j]&&l[i]==l[j])
				{
					l[j]=l[i]+1;
					if(max<l[j])
					{
						re[0]=a[j];
						max=l[j];
						id=j;
					}
				}
			}
		}
		printf("The max increasing sequence is %ld\n",max);
		j=1;
		for(i=id;i>=1;i--)
		{
			if(a[i]<re[j-1]&&l[i]==max-1)
			{
				max--;
				re[j++]=a[i];
			}
		}
		printf("The increasing sequence is:");
		for(i=j-1;i>=0;i--)
			printf(" %ld",re[i]);
		printf("\n");
	}
	return 0;
}