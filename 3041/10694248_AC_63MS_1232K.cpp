#include<iostream>
#include<memory.h>
using namespace std;
int d;
int map[501][501];
bool v[501];
int lk[501];
bool f(int i)
{
	int j;
	for(j=1;j<=d;j++)
	{
		if(map[i][j]==1&&v[j]==0)     //v记录当前的位置,在递归中,若lk[j]!=0,那么f(lk[j])要找一个位置,这个位置是出j以外的
		{ 
			v[j]=1;                     //所以加个标志位
			if(lk[j]==0||f(lk[j]))
			{
				lk[j]=i;
				return true;
			}
				
		}
	}
	return false;
}

int main()
{
	int p,i,x,y,r;
	while(cin>>d>>p)
	{
		memset(map,0,sizeof(map));      //map记录路径,x到y
		memset(lk,0,sizeof(lk));      //lk记录改点是从哪里连过来的
		r=0;
		for(i=0;i<p;i++)
		{
			cin>>x>>y;
			map[x][y]=1;
		}
		for(i=1;i<=d;i++)
		{
			memset(v,false,sizeof(v));     
			if(f(i))r++;
		}
		cout<<r<<endl;
	}
	return 0;
}