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
	int sum = 0;
	for (int i=0; i<n; i++)
		sum += w[i]*100/m;
	return (sum < k ? false : true);
}

int main()
{
	int i;
	int l, r, mid;
	double t=0;
	scanf("%d%d", &n, &k);
	for (i=0; i<n; i++)
	{
		scanf("%lf", &w[i]);
		t += w[i];
	}
	
	l =0, r = t*100;
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
	return 0;
}