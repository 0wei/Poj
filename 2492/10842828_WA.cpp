#include <iostream>
using namespace std;

int n,m;
int fa[2001], rank[2001];

void Init()
{
	for (int i=0; i<=n; i++)
	{
		fa[i] = i;
		rank[i] = 0;
	}
}

int Find(int x)
{
	int temp;
	
	if(fa[x]!=x)
	{
    temp=fa[x];
    fa[x]=Find(fa[x]);
	rank[x]=(rank[x]+rank[temp])%2;
	return fa[x];
	
	}
	else
		return x;
}
void Union(int x,int y)
{
	int rx,ry;
	rx=Find(x);
	ry=Find(y);
	fa[rx]=ry;
	rank[rx]=(rank[y]-rank[x]+1)%2;
}
int main()
{
	bool flags;
	int x,  y;
	int t = 0;
	int T;
	scanf("%d", &T);
	while (T--)
	{
		Init();
		flags = true;
		scanf("%d %d", &n, &m);
		for (int i=0; i<m; i++)
		{
			scanf("%d %d", &x, &y);
			int f_x = Find(x);
			int f_y = Find(y);
			if(f_x == f_y)     
			{
				if (rank[x] == rank[y])
					flags = false;
			}
			else
				Union(x, y);
		}
		printf("Scenario #%d:\n", ++t);
		
		if(!flags)
			printf("Suspicious bugs found!\n\n");
		else
			printf("No suspicious bugs found!\n\n");
	}
	return 0;
}
