#include<stdio.h>
#include<string.h>
#define si 1010
#define max(a,b) (a>b ?a:b)
char ch1[si],ch2[si];
long l1,l2,dp[si][si];

long rec(long i1,long i2)
{
	if(i1==l1||i2==l2)
		return 0;
	if(dp[i1][i2]!=-1)
		return dp[i1][i2];
	long p1;
	if(ch1[i1]==ch2[i2])
		p1=rec(i1+1,i2+1)+1;
	else
		p1=max(rec(i1+1,i2),rec(i1,i2+1));
	return dp[i1][i2]=p1;
}

void path_print(long i1,long i2)
{
	if(i1==l1||i2==l2)
		return ;
	if(ch1[i1]==ch2[i2])
	{
		printf("%c",ch1[i1]);
		path_print(i1+1,i2+1);
	}
	else
	{
		if(rec(i1,i2)==rec(i1+1,i2))
			path_print(i1+1,i2);
		else
			path_print(i1,i2+1);
	}
}

int main()
{
	long res,i,j;
	while(gets(ch1))
	{
		gets(ch2);
		l1=strlen(ch1);
		l2=strlen(ch2);
		for(i=0;i<l1;i++)
		{
			for(j=0;j<l2;j++)
				dp[i][j]=-1;
		}
		res=rec(0,0);
		printf("%ld\n",res);
		path_print(0,0);
		puts("");
	}
	return 0;
}