#include <stdio.h>
#include <algorithm>

const int N = 10005;
int n, k;
double w[N];
bool cut(int m)
{
	int sum = 0;
	for (int i=0; i<n; i++)
		sum += (int)w[i]*100/m;
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
		if (t <w[i]) t = w[i];
	}
	
	l =0, r = t*100;
	while (l < r)
	{
		mid = (l + r) >>1;
		if (cut(mid))

			l = mid+1;
		else 
			r = mid-1;
	}
	double len = (double)mid/100 - 0.005;
	printf("%.2lf",len);
	return 0;
}