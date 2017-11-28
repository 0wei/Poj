#include<iostream>
using namespace std;

int dp[21][15001];   //dp[i][j]  放入i个砝码后，达到状态j是的组合dp[i][j]个数

int main()
{
	int n, g;
	int i,j, k;
	cin>>n>>g;
	int *c = new int[n+1];   //挂钩位置
	int *w = new int[g+1];   //钩码重量
	for(i=1; i<=n; i++)
		cin>>c[i];
	for (i=1; i<=g; i++)
		cin>>w[i];

	memset(dp, 0, sizeof(dp));
	dp[0][7500] = 1;    //放入0个砝码时的平衡（初值）

	for(i=1; i<=g; i++)
		for (j=0; j<=15000; j++)
			if (dp[i - 1][j] > 0)
			{
				for(k=1; k<=n; k++)
				{
					dp[i][j + w[i] * c[k]] += dp[i-1][j];   //dp公式
				}
			}
	
	cout<<dp[g][7500]<<endl;

	delete c;
	delete w;
	return 0;
}