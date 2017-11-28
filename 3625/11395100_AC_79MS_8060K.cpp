#include<iostream>
#include<cmath>
#define MAX 999999999
using namespace std;
double map[1005][1005],x[1005],y[1005];
int n,m;
double distance(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double prim()
{
	int i,j,k,used[1005];
	double min,dis[1005];
	for(i=1;i<=n;i++)
	{
		dis[i]=map[1][i];
		used[i]=0;
	}
	for(i=1;i<n;i++)
	{
		min=MAX;
		for(j=2;j<=n;j++)
			if(!used[j]&&dis[j]<min)
			{
				min=dis[j];
				k=j;
			}
			used[k]=1;
			for(j=2;j<=n;j++)
				if(!used[j]&&dis[j]>map[k][j])
					dis[j]=map[k][j];
	}
	min=0;
	for(i=2;i<=n;i++)
		min+=dis[i];
	return min;
}
int main()
{
	int i,j,a,b;
	double temp;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%lf%lf",&x[i],&y[i]);
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
		{
			temp=distance(x[i],y[i],x[j],y[j]);
			map[i][j]=temp;map[j][i]=temp;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			map[a][b]=0;map[b][a]=0;
		}
		printf("%.2lf\n",prim());
		return 0;
}