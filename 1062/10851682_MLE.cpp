#include <iostream>
#include <math.h>
using namespace std;
const int MAXX = 120;

int M, N;
int map[MAXX][MAXX];
int rk[MAXX];
int cost;
int minrk, maxrk;

void DFS(int k,int c)
{
	int i;
	cost = cost > c ? c : cost;
	for (i=1; i<=N; i++)
	{
		int t = maxrk;
		int tmp = minrk;
		maxrk = maxrk < rk[i] ? rk[i] : maxrk;
		minrk = minrk < rk[i] ? minrk : rk[i];
		if(i != k && map[k][i] != -1 && maxrk - minrk <= M)
		{
			
			DFS(i,c - map[k][k] + map[k][i] + map[i][i]);
			maxrk = t;
			minrk = tmp;
		}
		else
		{
			maxrk = t;
			minrk = tmp;
		}

	}
	return;
}

int main()
{
	int P, L, X;
	int T, V;
	while(cin>>M>>N)
	{
		memset(map, -1, sizeof(map));
		for (int i=1; i<=N; i++)
		{
			cin>>P>>L>>X;
			map[i][i] = P;
			rk[i] = L;
			for (int j=1; j<=X; j++)
			{
				cin>>T>>V;
				map[i][T] = V;
			}
		}
		cost = map[1][1];
		minrk = maxrk = rk[1];
		DFS(1, map[1][1]);

		cout<<cost<<endl;
	}
	return 0;
}