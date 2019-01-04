#include<stdio.h>
long neg_infinite=-1047483648;

long a[1001000];

void binary_search(long beg,long end,long key)
{
	long mid;
	while(beg<=end)
	{
		mid=(beg+end)/2;
		if(a[mid]==key)
			return;
		else if(a[mid]>key)
			end=mid-1;
		else
			beg=mid+1;
	}
	a[beg]=key;	
}

int main()
{
	long i,n,cur,input[100100],x=1;
	while(~scanf("%ld",&n)&&n)
	{
		cur=0;
		a[0]=neg_infinite;
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&input[i]);
			if(input[i]>a[cur])
			{
				cur++;
				a[cur]=input[i];
			}
			else if(input[i]<a[cur])
				binary_search(1,cur,input[i]);
		}
		printf("Set %ld: %ld\n",x++,cur);
		for(i=1;i<=cur;i++)
			printf(" %d",a[i]);
		printf("\n");
	}
	return 0;
}
