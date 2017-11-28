#include<stdio.h>
int father[2001],rank[2001];
int Find(int x)
{
	int temp;
	
	if(father[x]==x)
		return x;
    temp=father[x];
    father[x]=Find(father[x]);
	rank[x]=(rank[x]+rank[temp])%2;
	return father[x];
}
void Union(int x,int y)
{
	int rx,ry;
	rx=Find(x);
	ry=Find(y);
	father[rx]=ry;
	rank[rx]=(rank[y]-rank[x]+1)%2;
}
void main()
{
	int Case=0,n,m,N;
	int i,flag;
	int x,y,rx,ry;
	scanf("%d",&N);
	while(N--)
	{
		Case++;
		flag=0;
		scanf("%d%d",&n,&m);
		for(i=0;i<=n;i++)
		{
			father[i]=i;
			rank[i]=0;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&x,&y);
			rx=Find(x);
			ry=Find(y);
			if(rx==ry)
			{
				if(rank[x]==rank[y])
				{
					flag=1;
				}
			}
			else
				Union(x,y);
		}
		if(flag==1)
		{
			printf("Scenario #%d:\n",Case);
			printf("Suspicious bugs found!\n\n");
		}
		else
		{
			printf("Scenario #%d:\n",Case);
			printf("No suspicious bugs found!\n\n");
		}

	}
}