#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct interval
{
	int start, end;
	bool operator <(interval p)
	{
		if (this->start!= p.start)
			return this->start < p.start;
		return this->end > p.end;
	}
}p[25005];

int main()
{
	int n, l, i, max, k;
	scanf("%d%d", &n, &l);
	for (i=0; i<n; i++)
		scanf("%d%d", &p[i].start, &p[i].end);
	sort(p, p+n);
	max=0, i=0, k=0;
	while (max < l)
	{
		int maxi = -1;
		for (; i<n && p[i].start <= max+1; i++)
			if (p[i].end > maxi)
				maxi = p[i].end;
		if (maxi == -1)
			break;
		max = maxi;
		k++;
	}
	if (max < l)
		puts("-1");
	else
		printf("%d\n", k);
	return 0;
}