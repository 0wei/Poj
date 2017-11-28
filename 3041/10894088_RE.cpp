/*
poj3041
*/
#include<iostream>
using namespace std;
int map[301][301];
int point[301];
bool vis[301];
int n, k;
bool f(int x)
{
	int y;
	for(y=1;y<=n;y++)
	{
		if(map[x][y]==1&&vis[y]==false)
		{
			vis[y]=true;
			if(point[y]==0||f(point[y]))
			{
				point[y]=x;
				return true;
			}
		}
		
	}
	return false;
}

int main()
{
	int x,y,i,j,r;
	while(cin>>n>>k)
	{
		memset(map,0,sizeof(map));
		memset(point,0,sizeof(point));
		r=0;
		for(i=1;i<=k;i++)
		{
			cin>>x>>y;
			map[x][y]=1;	
		}
		for(i=1;i<=n;i++)
		{
			memset(vis,false,sizeof(vis));
			if(f(i))           ///匹配
				r++;
		}
		cout<<r<<endl;
	}
	return 0;
}
