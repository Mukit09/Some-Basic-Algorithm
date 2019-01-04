#include<stdio.h>

int main()
{
	long i,j,k,a[100][100],n,x,y;
	while(scanf("%ld",&n))
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				a[i][j]=0;
			}
		}

		i=1;
		j=n/2+1;
		a[i][j]=1;

		for(k=2;k<=n*n;k++)
		{
			if(i==1)
				x=n;
			else
				x=i-1;

			if(j==1)
				y=n;
			else
				y=j-1;

			if(a[x][y]>=1)
				i++;
			else
			{
				i=x;
				j=y;
			}
			a[i][j]=k;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				printf("%5ld",a[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}