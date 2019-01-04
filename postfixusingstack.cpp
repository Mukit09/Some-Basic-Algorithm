#include<stdio.h>
#include<stack>
#include<string.h>

using namespace std;

stack<char>stk;

int main()
{
	long i,j,l;
	char ch[10000],re[10000];
	while(gets(ch))
	{
		l=strlen(ch);
		j=0;
		for(i=0;i<l;i++)
		{
			if(ch[i]=='+')
			{
				if(stk.size()==0||stk.top()!='*')
					stk.push(ch[i]);
				else
				{
					while(stk.top()!='(')
					{
						re[j++]=stk.top();
						stk.pop();
						if(stk.size()==0)
							break;
					}
					stk.push(ch[i]);
				}
			}
			else if(ch[i]=='*'||ch[i]=='(')
			{
				stk.push(ch[i]);
			}
			else if(ch[i]==')')
			{
				while(1)
				{
					if(stk.top()=='(')
					{
						stk.pop();
						break;
					}
					else
					{
						re[j++]=stk.top();
						stk.pop();
					}
				}
			}
			else
				re[j++]=ch[i];
			if(i==l-1)
			{
				while(1)
				{
					re[j++]=stk.top();
					stk.pop();
					if(stk.size()==0)
						break;
				}
			}
		}
		re[j]=0;
		puts(re);
	}
	return 0;
}

// a + b * c + ( d * e + f ) * g