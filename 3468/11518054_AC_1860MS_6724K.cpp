/*
	poj3468
*/
#include <iostream>
using namespace std;
const int N = 100005;

struct node
{
	int left, right;
	long long  num, add;
}tree[4*N];

int L(int n)
{
	return n<<1;
}
int R (int n)
{
	return (n<<1) | 1;
}
void update(int step)	//若当前节点的标志位add有值，则更新其左右节点
{
	tree[L(step)].num += tree[step].add * (tree[L(step)].right - tree[L(step)].left + 1);
	tree[L(step)].add += tree[step].add;	//将标志位传给子节点
	tree[R(step)].num += tree[step].add * (tree[R(step)].right - tree[R(step)].left + 1);
	tree[R(step)].add += tree[step].add;
	tree[step].add = 0;						//父节点清0
}
int a[N];

void build(int l, int r, int step)	
{
	tree[step].left = l;
	tree[step].right = r;
	tree[step].add = 0;
	if (l == r)		//到达叶子节点了
	{
		tree[step].num = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, L(step));
	build(mid+1, r, R(step));
	//其构造是自下而上（先求出其子节点的值），那么其父亲节点很明显就是其左右节点值的和
	tree[step].num = tree[L(step)].num + tree[R(step)].num;
}

void insert(int l, int r, int step, int add)
{
	if (l<= tree[step].left && tree[step].right <= r)
	{
		tree[step].add += add;	
		tree[step].num += add * (tree[step].right - tree[step].left + 1);	//add * len
		return;
	}
	if (tree[step].add != 0)	//
	{
		update(step);
	}
	int mid = (tree[step].left + tree[step].right) >> 1;
	if (mid >= l) 
		insert(l, r, L(step), add);
	if (mid < r)
		insert(l, r, R(step), add);
	//由于可能其子节点有更新，我们需要在重新计算一次step这层的值
	tree[step].num = tree[L(step)].num + tree[R(step)].num;
}

long long  query(int l, int r, int step)
{
	long long ans = 0;
	if (l <= tree[step].left && tree[step].right <= r)
	{
		return tree[step].num;
	}
	if (tree[step].add != 0)
	{
		update(step);
	}
	int mid = (tree[step].left + tree[step].right) >> 1;
	if (mid >= l)	//与左节点有交集
		ans += query(l, r, L(step));
	if (mid < r)	//与右节点有交集
		ans += query(l, r, R(step));
	return ans;
}

int main()
{
	int  n, q, i, k, l, r, add;
	char str;

	scanf("%d%d", &n, &q);
	for (i=1; i<=n; i++)
		scanf("%d", &a[i]);
	build(1, n, 1);
	
	while (q--)
	{
		getchar();
		scanf("%c", &str);
	//	printf("----->%c\n",str);
		if (str == 'Q')
		{
			scanf("%d%d", &l, &r);
			printf("%lld\n", query(l, r, 1));
		}
		else 
		{
			scanf("%d%d%d", &l, &r, &add);
			insert(l, r, 1, add);
		}
		
	}

	return 0;
}