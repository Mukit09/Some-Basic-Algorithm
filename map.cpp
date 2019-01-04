#include<iostream>
#include<string>
#include<string.h>
#include<map>

using namespace std;

map<string,string>mp;

int main()
{
	char ch1[100],ch2[100],ch3[100];
	while(scanf("%s%s",ch1,ch2)==2)
	{
		mp[ch1]=ch2;
		scanf("%s",ch3);
		if(mp[ch1]==ch3)
		{
			cout<<mp[ch1]<<endl;
			printf("yes\n");
			mp[ch1]=48;
		}
		else 
		{
			printf("no\n");
			mp[ch1]=48;
		}
	}
	return 0;
}