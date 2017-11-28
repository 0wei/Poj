#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXX = 1025;

int f[MAXX];
int main()
{
    int t, n, k;
	int i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n, &k);
		for (i=0; i<n; i++)
			scanf("%d", &f[i]);
		while(k--)
		   next_permutation(f, f+n);
		for (i=0; i<n; i++)
			printf("%d ", f[i]);
		printf("\n");
	}
    return 0;
}