#include<stdio.h>
#include<queue>
#include<vector>
#include<string.h>
#define inf 9999999
#define si 15
using namespace std;

queue<long>q;
long ii,jj,iii,jjj,visit[si][si],cst[si][si],n,start,fg,mx;
char ch[si][si];

void bfs(long xx,long yy)
{
	long x,y,l;
	q.push(xx);
	q.push(yy);
	l=q.size();
	visit[xx][yy]=1;
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		y=q.front();
		q.pop();

		if(visit[x+1][y]<=1&&ch[x+1][y]!='#'&&x+1<n&&(ch[x+1][y]==(start+1)||ch[x+1][y]=='.')&&fg)
		{
			visit[x+1][y]++;
			ch[x+1][y]='.';
			q.push(x+1);
			q.push(y);
			cst[x+1][y]=cst[x][y]+1;
		}
		if(visit[x][y+1]<=1&&ch[x][y+1]!='#'&&y+1<n&&(ch[x][y+1]==(start+1)||ch[x][y+1]=='.')&&fg)
		{
			visit[x][y+1]++;
			ch[x][y+1]='.';
			q.push(x);
			q.push(y+1);
			cst[x][y+1]=cst[x][y]+1;
		}
		if(visit[x][y-1]<=1&&ch[x][y-1]!='#'&&y-1>=0&&(ch[x][y-1]==(start+1)||ch[x][y-1]=='.')&&fg)
		{
			visit[x][y-1]++;
			ch[x][y-1]='.';
			q.push(x);
			q.push(y-1);
			cst[x][y-1]=cst[x][y]+1;
		}
		if(visit[x-1][y]<=1&&ch[x-1][y]!='#'&&x-1>=0&&(ch[x-1][y]==(start+1)||ch[x-1][y]=='.')&&fg)
		{
			visit[x-1][y]++;
			ch[x-1][y]='.';
			q.push(x-1);
			q.push(y);
			cst[x-1][y]=cst[x][y]+1;
		}
		if(ch[x+1][y]==start+1||ch[x][y+1]==start+1||ch[x-1][y]==start+1||ch[x][y-1]==start+1)
				start++;
		if(start>mx)
			fg=0;
	}
}

int main()
{
	long i,j,t,x=1;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		start=mx=65;
		for(i=0;i<n;i++)
		{
			scanf("%s",ch[i]);
			for(j=0;ch[i][j];j++)
			{
				if(ch[i][j]=='A')
					ii=iii=i,jj=jjj=j;
				else if(ch[i][j]>mx)
					mx=ch[i][j],iii=i,jjj=j;
				cst[i][j]=inf;
				visit[i][j]=0;
			}
		}
		cst[ii][jj]=0;
		fg=1;
		bfs(ii,jj);
		if(cst[iii][jjj]==inf)
			printf("Case %ld: Impossible\n",x++);
		else
			printf("Case %ld: %ld\n",x++,cst[iii][jjj]);
	}
	return 0;
}
