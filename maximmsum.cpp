#include<stdio.h>

long n,i,mx,start,end,mx_sm,cur_start,a[1100];
int main()
{
	while(~scanf("%ld",&n))
	{
		for(i=1;i<=n;i++)
			scanf("%ld",&a[i]);
		mx=mx_sm=0;
		start=cur_start=1;

		for(i=1;i<=n;i++)
		{
			mx_sm+=a[i];
			if(mx<mx_sm)
			{
				mx=mx_sm;
				end=i;
				start=cur_start;
			}
			if(mx_sm<0)
			{
				mx_sm=0;
				cur_start=i+1;
			}
		}
		printf("Max sum is %ld,which is from %ld to %ld\n",mx,start,end);
	}
	return 0;
}