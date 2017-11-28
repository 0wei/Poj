#include <iostream>
using namespace std;

int main()
{
	int m, n, k, i;
	double arr[10005], pm, pn;
	bool buy;
	scanf("%d%d%d", &m, &n, &k);
	buy = false;
	for (i=0; i<k; i++)
		scanf("%lf", arr+i);
	pm = pn = 0;
	for (i=0; i<k; i++)
	{
		pm += arr[i], pn += arr[i];
		if (i>=m)
			pm -= arr[i-m];
		if (i>=n)
			pn -= arr[i-n];
		if (i>=m-1 && i>=n-1)
		{
			if (pm/m > pn/n && !buy)
				printf("BUY ON DAY %d\n", i+1), buy = true;
			if (pm/m < pn/n && buy)
			{
				printf("SELL ON DAY %d\n", i+1);
				break;
			}
		}

	}
	return 0;
}