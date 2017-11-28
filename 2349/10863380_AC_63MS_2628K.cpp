#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;

struct my
{
	double x, y;
}pt[600];

double map[600][600];

int main()
{
	int n, s, p;
	int i, j, k;
	cin>>n;
	while(n--)
	{
		cin>>s>>p;
		for (i=0; i<p; i++)
			cin>>pt[i].x>>pt[i].y;

		for (i=0; i<p; i++)
		{
			for (j=i; j<p; j++)
			{
				map[i][j] = sqrt((pt[i].x - pt[j].x) * (pt[i].x - pt[j].x) + (pt[i].y - pt[j].y) * (pt[i].y - pt[j].y));
				map[j][i] = map[i][j];
			}
		}

		bool vis[600];
		double ans[600];
		double hi[600];

		memset(vis, false, sizeof(vis));
		for (i=0; i<p; i++)
			hi[i] = map[0][i];
		vis[0] = true;
		k = 0;
		int t = p-1;
		while(t--)
		{
			double big = INT_MAX;
			for (i=0; i<p; i++)
				if(!vis[i] && hi[i] < big)  //找一个权值最小的
				{
					j = i; 
					big = hi[i];
				}
			vis[j] = true;
			ans[k++] = big;

			for (i=0; i<p; i++)
				if(!vis[i] && hi[i] > map[j][i])  //更新到i的距离
					hi[i] = map[i][j];				
		}

		sort(ans,ans+k);  
       cout<<fixed<<setprecision(2)<<ans[p - s -1]<<endl;  


		

	}
	return 0;
}