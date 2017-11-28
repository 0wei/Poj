#include <stdio.h>
#include <string.h>
#include <cmath>
#define maxn 1005
#define maxm 1e12
bool visit[maxn];
int n;
double x[maxn],y[maxn],lowcost[maxn],weight[maxn][maxn];  

double dist(double x1,double y1,double x2,double y2)  
{  
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));  
} 

double Prim(int n) // 一共n个节点
{
	int i, j, k;
	double t, lowcase[105], ans = 0;
	for (i = 2; i <= n; i++)
		lowcase[i] = weight[1][i], visit[i] =false;
	visit[1] =true;
	for (i = 1; i < n; i++)
	{
		k = 1;
		t = maxm;
		for (j = 2; j <= n; j++)
			if (!visit[j] && lowcase[j] < t)
				k = j, t = lowcase[j];

		ans += t;
		visit[k] =true;

		for (j = 1; j <= n; j++)
			if (!visit[j] && weight[k][j] < lowcase[j])
				lowcase[j] = weight[k][j];
	}
	return ans;
}

int main(){
	
	int i,j,m,a,b;  
    while(scanf("%d%d",&n,&m)!=EOF)  
    {  
        for(i=1;i<=n;i++)      //农场从1开始标号  
        scanf("%lf%lf",&x[i],&y[i]);  
        for(i=1;i<=n;i++)  
        for(j=1;j<=n;j++)  
        weight[i][j]=maxm;  
        for(i=1;i<n;i++)  
        for(j=i+1;j<=n;j++)  
        {  
            weight[i][j]=dist(x[i],y[i],x[j],y[j]);  
            weight[j][i]=weight[i][j];  
        }  
        memset(visit,0,sizeof(visit));  
        for(i=1;i<=m;i++)  
        {  
            scanf("%d%d",&a,&b);  
            weight[a][b]=0;  
            weight[b][a]=0;  
        }  

        Prim(n);       //以第一个结点为起点生成最小生成树  
        printf("%.2lf\n",Prim(n));  
    }  
}