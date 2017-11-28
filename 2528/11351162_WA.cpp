#include <iostream>
#include <algorithm>
using namespace std;

#define W 50//10000005
#define N 10005

#define L(u) (u<<1)
#define R(u) (u<<1 | 1)

struct LineTree
{
	int l, r, c;
}tree[W];

int l[N], r[N], arr[2*N];
bool mark[W];
int ans;

void build(int u, int l, int r)
{
	tree[u].l = l;
	tree[u].r = r;
	tree[u].c = 0;
	if (l == r) return ;
	int mid = (l + r)>>1;
	build ( L(u), l, mid);
	build (R(u), mid+1, r);
}

void update(int u, int l, int r, int c)
{
	if (tree[u].l > r || tree[u].r < l)	return; 	//不相交
	if (l == tree[u].l && tree[u].r == r)			//完全覆盖tree[u]的区间
	{	
		tree[u].c = c;
		return ;
	}
	if (tree[u].c >= 0)
	{
		tree[L(u)].c = tree[R(u)].c = tree[u].c;
		tree[u].c = -1;
	}
	

	update (L(u), l, r, c);
	update (R(u), l, r, c);
}

void query(int u)
{
	if (tree[u].c == 0) return;
	if (tree[u].c > 0)
	{
		if (!mark[tree[u].c])
		{
			mark[tree[u].c] = true;
			ans ++;
		}
	}
	if (tree[u].c == -1)		//-1 表示该区间有多个颜色
	{
		query (L(u));
		query (R(u));
	}
}

int fid(int l, int r, int num)
{
	while (l <= r)
	{
		int mid = (l + r)>>1;
		if (arr[mid] == num) return mid;
		if (arr[mid] < num)
			l = mid +1;
		else r = mid -1;
	}
	return -1;
}

int main()
{
	int c, n;
	int i, j;
	cin>>c;
	while (c--)
	{
		cin>>n;
		memset(mark, false, sizeof(mark));
		ans = 0;
		for (i = 1; i <= n; i++)
		{
			cin>>l[i]>>r[i];
			arr[i] = l[i];
			arr[i+n] = r[i];
		}

		sort(arr+1, arr+1+2*n);
		j = 1;
		for (i=2; i<=2*n; i++)
		{
			if (arr[i] != arr[i-1])
				arr[++j] = arr[i];
		}
		build(1, 1, j);
		for (i=1; i<=n; i++)
		{
			int a = fid(1, j, l[i]);
			int b = fid(1, j, r[i]);
			update(1, a, b, i);
		}
		query(1);
		cout<<ans<<endl;
	}
	return 0;
}