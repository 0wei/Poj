#include <iostream>
using namespace std;

int n, m;
int arr[50002];

void Init()
{
	for (int i=0; i<n; i++)
		arr[i] = i;
}

int Find(int x)
{
	if(arr[x] != x)
		 return arr [x] = Find(arr[x]);
	else
		return x;
}

bool Uinte(int x, int y)
{
	int f_x = Find(x);
	int f_y = Find(y);
	arr[f_x] = f_y;
	if(f_x != f_y)
		return true;
	else
		return false;
	

}

int main()
{
	int tmp, t;
	int T = 1;
	while (scanf("%d %d", &n, &m) && (n != 0 || m != 0))
	{
		Init();
		
		for (int i=0; i<m; i++)
		{
			scanf("%d %d",&tmp, &t);
			if(Uinte(tmp, t))
				n--;
		}
		printf("Case %d: %d\n", T++, n);
	}
	return 0;
}



