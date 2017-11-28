#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(double a, double b)
{
	return a <b;
}

int main()
{
	int n;
	int i;
	int x, y;
	double ar[800];
	double a;
	int m, maxx;
	while (cin>>n && n != 0)
	{
		for (i=0; i<n; i++)
		{
			cin>>x>>y;
			if (y != 0)
				ar[i] = 1.0* x/y;
			else
				ar[i] = 0;
		}
		sort(ar, ar+n, cmp);
		a = ar[0];
		m = 1;
		maxx = 0;
		for (i=1; i<n; i++)
		{
			if (a == ar[i])
				m++;
			else
			{
				maxx = maxx < m ? m : maxx;
				m = 1;
				a = ar[i];
			}
		}
		maxx = maxx < m ? m : maxx;
		cout<<maxx<<endl;

	}
	return 0;
}