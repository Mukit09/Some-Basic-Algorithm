#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int a[10000],i,n,val,beg,end,mid,pos;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&val);
	sort(a,a+n);
	beg=0;
	end=n-1;
	while(1)
	{
		mid=(beg+end)/2;
		if(val==a[mid])
		{
			pos=mid+1;
			break;
		}
		else if(val>a[mid])
			beg=mid+1;
		else if(val<a[mid])
			end=mid-1;
	}
	printf("%d\n",pos);
	return 0;
}