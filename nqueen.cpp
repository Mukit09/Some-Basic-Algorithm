#include<stdio.h>
#include<math.h>

long x[1010],fg;

long place(long k,long i)
{
	long j,a,b;
	for(j=1;j<k;j++)
	{
		a=abs(x[j]-i);
		b=abs(j-k);
		if(x[j]==i||a==b)
			return 0;
	}	 
	return 1;
}

void nqueen(long k,long n)
{
	long i,a;
	if(fg)
		return ;
	for(i=1;i<=n;i++)
	{
		if(fg)
			break;
		if(place(k,i))
		{
			x[k]=i;
			if(k==n)
			{
				 for(a=1;a<=n;a++)
					 printf("%ld ",x[a]);
				 printf("\n");
				 fg=1;
			}
			else
				nqueen(k+1,n);
		}
	}
}

int main()
{
	long k,n;
	while(~scanf("%ld%ld",&n,&k))
	{
		fg=0;
		nqueen(1,n);	
	}
	return 0;
}