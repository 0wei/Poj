#include <iostream>
#include <string.h>
using namespace std;
const int N = 305;
char str1[N], str2[N];
int dp[N][N];

int maxx(int a, int b, int c)
{
	int t = a > b ? a : b;
	return t > c ? t : c;
}

int same(int a, int b)
{
	return a == b ? 1 : 0;
}

int main()
{
	while (scanf("%s%s", str1, str2) == 2)
	{
		memset(dp, 0, sizeof(dp));
		int len1 = strlen(str1), len2 = strlen(str2);
		for (int i=1; i<=len1; i++)
			for (int j=1; j<=len2; j++)
				dp[i][j] = maxx(dp[i-1][j-1] + same(str1[i-1], str2[j-1]), dp[i-1][j], dp[i][j-1]);
		printf("%d\n", dp[len1][len2]);
	}
	return 0;
}