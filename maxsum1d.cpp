#include<stdio.h>

int main()
{
	long i,n,a[10],p,q;
	while(scanf("%ld",&n)==1)
	{
		p=q=0;
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&a[i]);
			if(a[i]<0)
			{
				q+=a[i];
				p++;
			}
		}
		if(p==n)
		{
			printf("Maximum Sum : %ld\n",q);
			continue;
		}
		q=p=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]<0&&p+a[i]>a[i])
			{
				if(p>q)
					q=p;
				p+=a[i];
			}
			else if(a[i]>0)
			{
				p+=a[i];
			}
		}
		if(p>q)
			q=p;
		printf("Maximum Sum : %ld\n",q);
	}
	return 0;
}