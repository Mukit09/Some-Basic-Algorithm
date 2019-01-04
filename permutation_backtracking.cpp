/*#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<char>ve;

char ch[1010];
long l,take[1010],cnt;

void rec()
{
	long i;
	if(ve.size()==l)
	{
		cnt++;
		for(i=0;i<l;i++)
			printf("%c",ve[i]);
		printf("\n");
	}
	else
	{
		for(i=0;i<l;i++)
		{
		//	if(take[i]==0)        //if any character can be taken many times,then this condition will not be needed
			{
				take[i]=1;
				ve.push_back(ch[i]);
				rec();
				take[i]=0;
				ve.pop_back();
			}
		}
	}
}

int main()
{
	while(gets(ch))
	{
		l=strlen(ch);
		sort(ch,ch+l);
		cnt=0;
		rec();
		printf("\n%ld\n",cnt);
	}
	return 0;
}
*/

#include<stdio.h>
#include<algorithm>
using namespace std;

char ch[1010];
long l,take[1010],cnt,j,res[1010];

void rec()
{
	long i;
	if(j==l)
	{
		cnt++;
		for(i=0;i<l;i++)
			printf("%c",res[i]);
		printf("\n");
	}
	else
	{
		for(i=0;i<l;i++)
		{
			if(take[i]==0)        //if any character can be taken many times,then this condition will not be needed
			{
				take[i]=1;
				res[j++]=ch[i];
				rec();
				take[i]=0;
				j--;
			}
		}
	}
}

int main()
{
	while(gets(ch))
	{
		l=strlen(ch);
		sort(ch,ch+l);
		cnt=0;
		j=0;
		rec();
		printf("\n%ld\n",cnt);
	}
	return 0;
}