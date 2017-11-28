#include <iostream>
using namespace std;

int main()
{
	int n;
	int i, j, k;
	int t_max, maxx;
	int x[800], y[800];
	while (cin>>n && n!=0)
	{
		for (i=0; i<n; i++)
			cin>>x[i]>>y[i];
		maxx = 0;
		for (i=0; i<n; i++)
			for (j=i+1; j<n; j++)
			{
				t_max = 0;
				for (k=j+1; k<n; k++)
					if ((x[j] - x[i]) * (y[k] - y[i]) - (y[j] - y[i]) * (x[k] - x[i]) == 0)   //叉积等于0 共线
						t_max++;
					maxx = maxx < t_max ? t_max : maxx;
			}
		cout<<maxx+2<<endl;
	}
	return 0;
}