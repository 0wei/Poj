#include <iostream>
using namespace std;

int n, m, k, t;
int a[30001], b[30001];

void Init()
{
	for (int i=0; i<n; i++)
		a[i] = -1;
}

void SetMerga(int x)
{
	for (int i=0; i<k; i++)
	{
		a[b[i]] = x;
	}
}

void Merga(int x)
{
	bool flags = false;
	for (int i=0; i<k; i++)
		if(a[b[i]] != -1)
		{
			flags = true;
			SetMerga(a[b[i]]);
		}
	if(!flags)
		SetMerga(x);
}

int GetSum()
{
	if(a[0] == -1)
		return 1;
	int tmp = a[0];
	int sum = 0;
	for (int i=0; i<n; i++)
	{
		if(a[i] ==tmp)
			sum ++;
	}
	return sum;
}

int main()
{
	int tmp;
	while(scanf("%d %d", &n, &m) && n + m != 0)
	{
		Init();
		for (int i=0; i<m; i++)
		{
			scanf("%d", &k);
			t = 0;
			for (int j=0; j<k; j++)
			{
				scanf("%d", &b[j]);
			}
			Merga(i);
		}
		printf("%d\n", GetSum());
	}
	return 0;
}