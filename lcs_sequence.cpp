#include<stdio.h>
#include<string.h>
#define si 10

long a[si][si],x=0;
char ch1[si],ch2[si];
char ch[si];

long max(long a,long b)
{
	if(a>b) return a;
	else return b;
}

void write(long i,long j)
{
	if(i==0||j==0)
		return ;
	else if(ch1[i]==ch2[j])
	{
		ch[x++]=ch1[i];
		write(i-1,j-1);
	}
	else
	{
		if(a[i-1][j]>a[i][j-1]) write(i-1,j);
		else write(i,j-1);
	}
}

int main()
{
	char c;
	long m,n,i,j,t;
	scanf("%ld",&t);
	getchar();
	while(t--)
	{
		m=1;
		while((c=getchar())!='\n')
		{
			ch1[m++]=c;
		}
		m--;
		n=1;
		while((c=getchar())!='\n')
		{
			ch2[n++]=c;
		}
		n--;
		for(i=0;i<=m;i++)
			a[i][0]=0;
		for(i=0;i<=n;i++)
			a[0][i]=0;
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(ch1[i]==ch2[j])
					a[i][j]=a[i-1][j-1]+1;
				else
					a[i][j]=max(a[i-1][j],a[i][j-1]);
			}
		}
		printf("%ld\n",a[m][n]);

		x=0;
		write(m,n);
		for(i=x-1;i>=0;i--)
			printf("%c",ch[i]);
		printf("\n");
	}
	return 0;
}