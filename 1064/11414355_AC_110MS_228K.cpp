/*
poj1064
WA / 高精度
*/

#include <stdio.h>
#include <algorithm>

const int N = 10005;
int n, k;
double w[N];

bool cut(int m)
{
	if (m == 0) return true;
	int sum = 0;
	for (int i=0; i<n; i++)
		sum += w[i]/m;
	return (sum < k ? false : true);
}

int main()
{
	int i;
	int l, r, mid;
	double t, tmp;
	while (scanf("%d%d", &n, &k)!=EOF)
	{
		t= tmp = 0;
		for (i=0; i<n; i++)
		{
			scanf("%lf", &tmp);

			w[i] = (int)(tmp*100);
			t = t < w[i] ? w[i] : t;
		}

		l =0, r = t;
		t = -1;
		while (l <= r)
		{
			mid = (l + r) >>1;
			if (cut(mid))
			{
				t = mid;
				l = mid+1;
			}
			else 
				r = mid-1;
		}
		if (t != -1)
			printf("%.2lf\n",t*0.01);
		else
			puts("0.00");
	}
	return 0;
}