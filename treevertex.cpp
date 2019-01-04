#include<stdio.h>

long tree [100],delay[100],weight[100];
long range,node,i,flag=0;

int max(int a,int b)
{
    if(a>b)
        return a;
    else 
		return b;
}
void split(long i)
{
    if(tree[i]!=0)
    {
        if(2*i>node)
            delay[i]=0;
        else
        {
            split(2*i);
            delay[i]=max(delay[i],delay[2*i]+weight[2*i]);
            if((2*i+1)<=node)
            {
                split(2*i+1);
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
    long j;
    printf("Total no. of nodes\n");
    scanf("%ld",&node);

    printf("Tree values\n");
    for(j=1; j<=node; j++)
        scanf("%ld",&tree[j]);

    printf("Weights\n");
    for(j=1; j<=node; j++)
    {
        scanf("%ld",&weight[j]);
        delay[j]=0;
    }
    printf("Maximum range\n");
    scanf("%ld",&range);

    split(1);
	if(flag==0)
	{
		printf("NO BOOSTER NEED");
	}
	printf("\n");
	
    return 0;
}
//1 2 3 0 4 5 6 0 0 7 8 0 0 9 10
//0 4 2 0 2 1 3 0 0 1 4 0 0 2 3