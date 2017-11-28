#include <iostream>
using namespace std;

int maxx;
int map[400][400];
int n;

void dfs(int i, int j, int sum)
{

	if (j< 0)
		return ;
	if (i == n)
	{
		if (maxx <sum)
			maxx = sum;
		return ;
	}
	dfs(i+1, j+1, sum+map[i][j]);
	dfs(i+1, j, sum+map[i][j]);
}

int main()
{

	int i, j;
	while (cin>>n)
	{
		maxx = 0;
		for (i=0; i<n; i++)
		{
			for (j=0; j<=i; j++)
			{
				cin>>map[i][j];

			}
		}
		dfs(0, 0, 0);
		cout<<maxx<<endl;
	}
}