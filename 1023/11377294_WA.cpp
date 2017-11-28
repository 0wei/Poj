/*
	输入：第一行表示字符串长度， 第二行是字符串（p表示基数是1， n表示是-1），第三行表示最终求得的结果。
	该题最重要的是要知道：2^n + 2^(n-1) == 2^(n+1) - 2^(n-1) 这个可以自己推导一下就明白了。
	如：4
		ppnn
		10
	10的二进制是1010 （由于0 乘以任何数都是0,所以不需要管）
		第二位由于是负数，那么在高位需要在加个1，最终结果是1110
			
		
*/
#include <iostream>
using namespace std;

__int64 k, n;
char s[100], res[100];
int main()
{
	int t, i;
	scanf("%d", &t);
	int maxx, minn;
	while (t--)
	{
		scanf("%I64d", &k);
		scanf("%s", &s);
		scanf("%I64d", &n);
		maxx = minn = 0;
		for (i=0; i<k; i++)
		{
			maxx<<=1;
			minn<<=1;
			if (s[i] == 'p')
				maxx += 1;		//64位二进制全为1 的时候溢出maxx = -1
			else
				minn -= 1;		
		}
		if ((n < minn && minn <=0) || (n > maxx && maxx >=0))
		{
			puts("Impossible");
			continue;
		}
		memset(res, '\0', sizeof(res));
		for (i=k-1; i>=0; i--)
		{
			int flag = 0;
			if (n & 1)
			{
				res[i] = '1';
				if (s[i] == 'n')
					flag = 1;
			}
			else res[i] = '0';
			n >>= 1;
			if (flag)
				n++;
		}
		printf("%s\n", res);

	}
	return 0;
}