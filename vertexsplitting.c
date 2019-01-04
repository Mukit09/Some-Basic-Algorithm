#include<stdio.h>
int tree [100],delay[100],weight[100];
int range,node,i,flag=0;
int max(int a,int b)
{
    if(a>b)
        return a;
    else 
		return b;
}
void split(int i,int range)
{
    if(tree[i]!=0)
    {
        if(2*i>node)
            delay[i]=0;
        else
        {
            split(2*i,range);
            delay[i]=max(delay[i],delay[2*i]+weight[2*i]);
            if((2*i+1)<=node)
            {
                split(2*i+1,range);
                delay[i]=max(delay[i],delay[2*i+1]+weight[2*i+1]);

            }
        }
        if((tree[i]!=0)&&(delay[i]+weight[i])>range)
        {
            printf("%d ",tree[i]);
            delay[i]=0;
			flag=1;
        }
    }
}
int main()
{
    int j;
    printf("input the total no. of nodes\n");
    scanf("%d",&node);
    printf("input the tree values\n");
    for(j=1; j<=node; j++)
        scanf("%d",&tree[j]);
    printf("input the weights\n");
    for(j=1; j<=node; j++)
    {
        scanf("%d",&weight[j]);
        delay[j]=0;
    }
    printf("input the maximum range\n");
    scanf("%d",&range);
    split(1,range);
	if(flag==0)
	{
		printf("NO BOOSTER NEED");
	}
		printf("\n");
	
    return 0;
}
//1 2 3 0 4 5 6 0 0 7 8 0 0 9 10
//0 4 2 0 2 1 3 0 0 1 4 0 0 2 3