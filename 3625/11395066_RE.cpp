#include <stdio.h>
#include <cmath>
#define MAXN 1005
#define INF 1e12  
bool flag[MAXN];
double graph[MAXN][MAXN];  // graph[i][j] 表示节点i到j的距离
int n;
double Prim(int n) // 一共n个节点
{
    int i, j, k;
    double t, lowcase[105], ans = 0;
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

int main(){
	int i,j,m,a,b;
	double point[1005][2];

	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%lf %lf",&point[i][0],&point[i][1]);
	}
	for(i=1;i<n;i++){
		for(j=i+1;j<=n;j++){
			graph[j][i] = graph[i][j] = INF;
			graph[i][j] = sqrt((double)(point[i][0]-point[j][0])*(point[i][0]-point[j][0])+(point[i][1]-point[j][1])*(point[i][1]-point[j][1]));
			graph[j][i] = graph[i][j]; 
		}
	}
	for(i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		graph[a][b] = graph[b][a] = 0; 
	}
	printf("%.2f\n",Prim(n));

	return 0;
}