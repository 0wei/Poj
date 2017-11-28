/*
	poj 2506
*/

#include <iostream>
using namespace std;

const int N = 300;
int ans[N][N];

int main()
{
	int n;
	int i, j;
	int maxx=2;
	int beyond, count;
	ans[0][0] = 2, ans[0][1] = 1;
	ans[1][0] = 2, ans[1][1] = 1;
	ans[2][0] = 2, ans[2][1] = 3;
	while (cin>>n)
	{
		if (n <= maxx)
		{
			for (i=ans[n][0]-1; i>0; i--)
				cout<<ans[n][i];
			cout<<endl;
			continue;
		}
		
	
		for (i=maxx; i<n; i++)
		{
			beyond = 0;
			for (j=1; j<ans[i][0]; j++)
			{
				int p = ans[i][j] + ans[i-1][j]*2 + beyond;
				ans[i+1][j] = p % 10;
				beyond = p / 10;
			}
			ans[i+1][0] = j;
			if (beyond)
			{
				ans[i+1][j] = beyond;
				ans[i+1][0]++;
			}
		}
		maxx = n;
		for (i=ans[n][0]-1; i>0; i--)
				cout<<ans[n][i];
		cout<<endl;
	}
	return 0;
}