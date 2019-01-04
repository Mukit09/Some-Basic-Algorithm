#include<stdio.h>
#include<string.h>
#define si 1010

long a[si][si],x;
char ch1[si],ch2[si];
char ch[si];

long max(long a,long b)
{
	if(a>b) return a;
	else return b;
}

void write(long i,long j)
{
	if(i<0||j<0)
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
	long m,n,i,j,t;
	scanf("%ld",&t);
	getchar();
	while(t--)
	{
		gets(ch1);
		m=strlen(ch1);
		gets(ch2);
		n=strlen(ch2);
		for(i=0;i<=m;i++)
		{
			for(j=0;j<=n;j++)
			{
				if(i==0||j==0)
					a[i][j]=0;
				else if(ch1[i-1]==ch2[j-1])
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