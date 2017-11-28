//编译错误

#include <iostream>
#include <math.h>
#include <string.h>
#include <iomanip>
using namespace std;

const double MaxInt = 10000.0;
const int N =  120;

struct point
{
	double x, y, z;
	double r;
};



//创建map二维数组储存图表，low数组记录每2个点间最小权值，visited数组标记某点是否已访问
double map[N][N],low[N];
int visited[N];
int n;
point pt[N];


double GetLen(int i, int j)
{
	double t = (pt[i].x-pt[j].x) * (pt[i].x-pt[j].x) + (pt[i].y-pt[j].y) * (pt[i].y-pt[j].y) + (pt[i].z-pt[j].z) * (pt[i].z-pt[j].z);
	t = sqrt(t) - pt[i].r - pt[j].r;
	return (t > 0 ? t : 0.0);
}

double prim()
{
    int i,j,pos;
	double result = 0.0, min;
    memset(visited,0,sizeof(visited));
	//从某点开始，分别标记和记录该点
    visited[1]=1;pos=1;
	//第一次给low数组赋值
    for(i=1;i<=n;i++)
        if(i!=pos) low[i]=map[pos][i];
		//再运行n-1次
		for(i=1;i<n;i++)
		{
			//找出最小权值并记录位置
			min=MaxInt;
			for(j=1;j<=n;j++)
				if(visited[j]==0&&min>low[j])
				{
					min=low[j];pos=j;
				}
				//最小权值累加
				result+=min;
				//标记该点
				visited[pos]=1;
				//更新权值
				for(j=1;j<=n;j++)
					if(visited[j]==0&&low[j]>map[pos][j])
						low[j]=map[pos][j];
		}
		return result;
}


int main()
{
	
	int i, j;
	while(cin>>n && n!=0)
	{		
		for (i=1; i<=n; i++)
			cin>>pt[i].x>>pt[i].y>>pt[i].z>>pt[i].r;
			//scanf("%lf %lf %lf %lf",&pt[i].x,&pt[i].y,&pt[i].z,&pt[i].r);	
		for (i=1; i<=n; i++)
		{
			for (j=1; j<=n; j++)
			{
				map[i][j] = 1;
				//map[i][j] = GetLen(i, j);	
			}
		}
		cout<<fixed<<setprecision(3)<<prim()<<endl;  
		//printf("%.3lf\n",prim());				
	}
	return 0;
}

