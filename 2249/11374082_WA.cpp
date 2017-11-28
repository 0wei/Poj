#include <iostream>
using namespace std;
//C(n, k)
double C(int n, int k)
{
	double s = 1;
	while (k)
	{
		s *= 1.0 * n/k;
		n--, k--;
	}
	return s;
}

int main()
{
	int n, k;
	while (cin>>n>>k && (n!=0 || k!=0))
	{
		if (k > n/2) k = n - k;
		if (k == 0)
		{
			cout<<"1"<<endl;
			continue;
		}
		cout<<C(n,k)<<endl;
	}
	return 0;
}