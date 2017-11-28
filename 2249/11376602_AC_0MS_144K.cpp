#include <iostream>
using namespace std;
//C(n, k)
double C(int c,int k)
{
	double a=1;
	int i,j=2;
	for (i=0;i<k; i++)
		a = a*(c-i)/(k-i);
	return a;
}

int main()
{
	int n, k;
	while (scanf("%d%d",&n,&k)!=EOF && (n+k))
	{
		if (k > n/2) k = n - k;
		printf("%.0lf\n", C(n,k));
	}
	return 0;
}