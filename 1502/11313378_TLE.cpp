#include <iostream>
#include <vector>
using namespace std;

#define MAX(a,b) ((a)>(b)?(a):(b))

int matrix[105][105];
bool visted[105];
vector<int> dist;
int maxx;

void Dijkstra(int n)
{
	int i, w;
	maxx = -1;
	dist.assign(n+1, INT_MAX);
	dist[1] = 0;

	memset(visted, false, sizeof(visted));

	while (true)
	{
		int minn = INT_MAX, v = 1;
		for (i=1; i<=n; i++)     //得到一个最短的权值
			if (!visted[i] && minn > dist[i])
				minn = dist[i], v = i;
		visted[v] = true;
		if (minn == INT_MAX) 
			break;

		for (w=1; w <=n; w++)
		{
			if (!visted[w] && matrix[v][w] < INT_MAX && dist[w] > dist[v] + matrix[v][w])	//逐一修改所有的路径使之趋近最短
				dist[w] = dist[v] + matrix[v][w];
		} 
		maxx=MAX(maxx,dist[v]);
	}
}

int main()
{
	int i, j, k;
	int n;
	char str[100];
	while (scanf("%d",&n))
	{
		memset(matrix, 0, sizeof(matrix));
		for (i=2; i<=n; i++)
		{
			for (j=1; j<i; j++)
			{
				scanf("%s", &str);	
				if (str[0] == 'x')
					matrix[i][j] = INT_MAX;	
				else
				{
					int len = strlen(str);
					for (k=0; k<len; k++)
					{
						matrix[i][j] *= 10;
						matrix[i][j] += str[k] - '0';
					}
				}
				matrix[j][i] = matrix[i][j];
			}
		}
		Dijkstra(n);
		cout<<maxx<<endl;
	}
	return 0;
}