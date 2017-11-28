#include <iostream>
using namespace std;
const int MAXX = 9999999;
const int N = 101;
int main()
{
	int b[N][N], p[N][N];
	int n, m[N];
	int i, j, k;
	int t;
	scanf("%d", &t);

	while(t--)
	{
		int max_b = 0, min_b = MAXX;
		int min_p;
		int total;
		double result;

		scanf("%d", &n);
		

		for(i=0; i<n; i++)
		{
			scanf("%d", &m[i]);
			for(j=0; j<m[i]; j++)
			{
				scanf("%d %d", &b[i][j], &p[i][j]);
				max_b = max_b < b[i][j] ? b[i][j] : max_b;
				min_b = min_b > b[i][j] ? b[i][j] : min_b;
			}
		}
		
		result = 0.0;
		for(k=min_b; k<=max_b; k++)
		{
			total = 0;
			for(i=0; i<n; i++)
			{
				min_p = MAXX;
				for(j=0; j<m[i]; j++)
				{
					if(b[i][j] >= k && p[i][j] < min_p)
					{
						min_p = p[i][j];
					}
				}
				total += min_p;
			}
			
			if(1.0*k/total - result > 1e-8)
			{
				 result = 1.0*k/total; 
			}
		}
		
		printf("%.3f\n", result);
		

	}

	return 0;
}
