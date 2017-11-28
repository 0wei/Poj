#include <iostream>
using namespace std;
//C(n, k)
int C(int n, int k)
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
	while (cin>>n>>k && (n+k))
	{
		if (k > n/2) k = n - k;
		if (k == 0)
		{
			cout<<n<<endl;
			continue;
		}
		cout<<C(n,k)<<endl;
	}
	return 0;
}