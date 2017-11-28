#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string.h>
using namespace std;

const int N = 1005;
bool visted[N];
int x[N], y[N];
struct Point 
{
	int p1, p2;
	double lens;
	bool operator <(Point p)
	{
		return this->lens < p.lens;
	}
}p[N];

double GetLen(int i, int j)
{
	double lx = x[i] - x[j];
	double ly = y[i] - y[j];
	return sqrt(lx*lx+ly*ly);
}

int main()
{
	int n, m;
	int i, j;
	int cnt;
	int a, b;
	double tlen;
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		for (i=1; i<=n; i++)
			scanf("%d%d",&x[i],&y[i]);
		cnt = 0;
		for (i=1; i<=n ;i++)
			for (j=i+1; j<=n;j++)
			{
				p[cnt].p1 = i;
				p[cnt].p2 = j;
				p[cnt++].lens = GetLen(i, j);
			}
		sort(p, p+cnt);
		memset(visted, false, sizeof(visted));
		tlen = 0;
		for (i=0; i<m; i++)
		{
			scanf("%d%d",&a,&b);
			visted[a] = visted[b] = true;
		}
		for (i=0; i<cnt; i++)
		{
			if (!visted[p[i].p1] || !visted[p[i].p2])
			{
				visted[p[i].p1] = visted[p[i].p2] = true;
				tlen += p[i].lens;
			}
		}
		printf("%.2lf\n", tlen);
	}
	return 0;
}

