#include <iostream>
using namespace std;


int main()
{
	__int64 n, tmp;
	__int64 i, j, t;
	__int64 sum;
	__int64 num[100000];
	__int64 p;
	
	while(scanf("%I64d",&n) !=EOF && n != 0)
	{
		sum = n-1;
		tmp = n;
		p = 0;
		for(i=2; i<=n; i++)
		{
			if(n % i ==0)
			{
				sum -= tmp / i -1;
				num[p++] = i;
				
				n /= i;
				while(n % i == 0)
					n /= i;
			}
		}
		
		for(i=0; i<p; i++)
		{
			for(j=i+1; j<p; j++)
			{
				t = num[i] * num[j];
				if(t < tmp)
					sum += tmp / t - 1;
			}
		}
		
		printf("%I64d\n", sum);
	}
	return 0;
}