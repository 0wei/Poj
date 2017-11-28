#include <iostream>
#include <math.h>
using namespace std;
const int MAXX = 120;

int M, N;
int map[MAXX][MAXX];
int rk[MAXX];
int cost;

void DFS(int k,int c)
{
	int i;
	if (cost >= c)
		cost = c;
	else return;
	for (i=1; i<=N; i++)
		if(i != k && map[k][i] != -1 && abs(rk[1] - rk[i]) <= M)
			DFS(i,c - map[k][k] + map[k][i] + map[i][i]);
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
		DFS(1, map[1][1]);

		cout<<cost<<endl;
	}
	return 0;
}