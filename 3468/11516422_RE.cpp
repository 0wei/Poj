/*
	poj3468
*/
#include <iostream>
using namespace std;
const int N = 50005;

struct node
{
	int left, right;
	int  num, add;
}tree[4*N];

int L(int n)
{
	return n<<1;
}
int R (int n)
{
	return (n<<1) | 1;
}
void update(int step)	//鑻ュ綋鍓嶈妭鐐圭殑鏍囧織浣峚dd鏈夊€硷紝鍒欐洿鏂板叾宸﹀彸鑺傜偣
{
	tree[L(step)].num += tree[step].add * (tree[L(step)].left - tree[L(step)].right + 1);
	tree[L(step)].add += tree[step].add;	//灏嗘爣蹇椾綅浼犵粰瀛愯妭鐐?
	tree[R(step)].num += tree[step].add * (tree[R(step)].left - tree[R(step)].right + 1);
	tree[R(step)].add += tree[step].add;
	tree[step].add = 0;						//鐖惰妭鐐规竻0
}
int a[N];

void build(int l, int r, int step)	
{
	tree[step].left = l;
	tree[step].right = r;
	tree[step].add = 0;
	if (l == r)		//鍒拌揪鍙跺瓙鑺傜偣浜?
	{
		tree[step].num = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, L(step));
	build(mid+1, r, R(step));
	//鍏舵瀯閫犳槸鑷笅鑰屼笂锛堝厛姹傚嚭鍏跺瓙鑺傜偣鐨勫€硷級锛岄偅涔堝叾鐖朵翰鑺傜偣寰堟槑鏄惧氨鏄叾宸﹀彸鑺傜偣鍊肩殑鍜?
	tree[step].num = tree[L(step)].num + tree[R(step)].num;
}

void insert(int l, int r, int step, int add)
{
	if (l<= tree[step].left && tree[step].right <= r)
	{
		tree[step].add += add;	
		tree[step].num += add * (tree[step].left - tree[step].right + 1);	//add * len
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
	//鐢变簬鍙兘鍏跺瓙鑺傜偣鏈夋洿鏂帮紝鎴戜滑闇€瑕佸湪閲嶆柊璁＄畻涓€娆tep杩欏眰鐨勫€?
	tree[step].num = tree[L(step)].num + tree[R(step)].num;
}

int query(int l, int r, int step)
{
	int ans = 0;
	if (l <= tree[step].left && tree[step].right <= r)
	{
		return tree[step].num;
	}
	if (tree[step].add != 0)
	{
		update(step);
	}
	int mid = (tree[step].left + tree[step].right) >> 1;
	if (mid >= l)	//涓庡乏鑺傜偣鏈変氦闆?
		ans += query(l, r, L(step));
	if (mid < r)	//涓庡彸鑺傜偣鏈変氦闆?
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
		getchar();  //
		scanf("%c", &str);
	//	printf("----->%c\n",str);
		if (str == 'Q')
		{
			scanf("%d%d", &l, &r);
			printf("%d\n", query(l, r, 1));
		}
		else 
		{
			scanf("%d%d%d", &l, &r, &add);
			insert(l, r, 1, add);
		}	
	}
	cin>>n;
	return 0;
}