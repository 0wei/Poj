#include <iostream>
#include <algorithm>
using namespace std;
const int M = 100005;
int toLeft[20][M], tree[20][M], sorted[M];

void build(int level, int left, int right)
{
	if (left == right) return;
	int i, mid = (left + right) >>1;
	int suppose = mid - left + 1;
	for (i=left; i<=right; i++)
		if (tree[level][i] < sorted[mid])
			suppose--;
	int lpos = left, rpos = mid+1;
	for (i=left; i<=right; i++)
	{
		if (i == left)
			toLeft[level][i] = 0;
		else
			toLeft[level][i] = toLeft[level][i-1];
		if (tree[level][i] < sorted[mid])
		{
			toLeft[level][i]++;
			tree[level+1][lpos++] = tree[level][i];
		}
		else if (tree[level][i] > sorted[mid])
		{
			tree[level+1][rpos++] = tree[level][i];
		}
		else 
		{
			if (suppose != 0)
			{
				suppose--;
				toLeft[level][i]++;
				tree[level+1][lpos++] = tree[level][i];
			}
			else
				tree[level+1][rpos++] = tree[level][i];
		}
	}
	build(level+1, left, mid);
	build(level+1, mid+1, right);
}

int query(int level, int left, int right, int qleft, int qright, int k)
{
	if (qleft == qright)
		return tree[level][qright];
	int s, ss, mid = (left + right)>>1;
	if (left == qleft)
	{
		s = 0;
		ss = toLeft[level][qright];
	}
	else
	{
		s = toLeft[level][qleft-1];
		ss = toLeft[level][qright] - s;
	}
	int newl, newr;
	if (k <= ss)
	{
		newl = left + s;
		newr = left + s + ss -1;
		return query(level+1, left, mid, newl, newr, k);
	}
	else
	{
		newl = mid-left+1+qleft-s;
		newr = mid-left+1+qright-s-ss;
		return query(level+1, mid+1, right, newl, newr, k-ss);
	}
}

int main()
{
	int n, m;
	int i;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=1; i<=n; i++)
		{
			scanf("%d", &tree[0][i]);
			sorted[i] = tree[0][i];
		}
		sort(sorted+1, sorted+n+1);
		build(0,1,n);
		int ql, qr, k;
		for (i=0; i<m; i++)
		{
			scanf("%d%d%d", &ql, &qr, &k);
			printf("%d\n", query(0, 1, n, ql, qr, k));
		}
	}
	return 0;
}