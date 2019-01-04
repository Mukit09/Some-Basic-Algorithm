#include<stdio.h>

int main()
{
	long a[1000];

	a[0]=-9999;
	long n,i,temp,ptr;

	while(scanf("%ld",&n)==1)
	{
		scanf("%ld",&a[1]);
		for(i=2;i<=n;i++)
		{
			scanf("%ld",&a[i]);
			temp=a[i];
			ptr=i-1;
			while(temp<a[ptr])
			{
				a[ptr+1]=a[ptr];
				ptr=ptr-1;
			}
			a[ptr+1]=temp;
		}
		for(i=1;i<=n;i++)
			printf("%ld ",a[i]);
		printf("\n");
	}
	return 0;
}