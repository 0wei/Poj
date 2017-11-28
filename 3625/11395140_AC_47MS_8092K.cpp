#include <stdio.h>
#include <math.h>

#define MAXN 1010
#define INF 1e9
bool flag[MAXN];
double graph[MAXN][MAXN];  // graph[i][j] 表示节点i到j的距离


double distance(double x1,double y1,double x2,double y2)
{
 return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}


double Prim(int n) // 一共n个节点
{
	int i, j, k;

	double t, lowcase[MAXN], ans = 0;
	for (i = 2; i <= n; i++)
		lowcase[i] = graph[1][i], flag[i] =false;
	flag[1] =true;

	for (i = 1; i < n; i++)
	{
		k = 1;
		t = INF;
		for (j = 2; j <= n; j++)
			if (!flag[j] && lowcase[j] < t)
				k = j, t = lowcase[j];

		ans += t;
		flag[k] =true;

		for (j = 1; j <= n; j++)
			if (!flag[j] && graph[k][j] < lowcase[j])
				lowcase[j] = graph[k][j];
	}

	return ans;
}

int main()
{
	int n, m;
	double x[1010],y[1010];

	int i,j,a,b;
	double temp;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%lf%lf",&x[i],&y[i]);
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
		{
			temp=distance(x[i],y[i],x[j],y[j]);
			graph[i][j]=temp;graph[j][i]=temp;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			graph[a][b]=0;graph[b][a]=0;
		}
		printf("%.2lf\n",Prim(n));

		return 0;
}