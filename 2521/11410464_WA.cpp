#include <iostream>
using namespace std;
int main()
{
	int n, m, p, c;
	while (cin>>n>>m>>p>>c && n+m+p+c)
	{
		if (p <= m)
			cout<<n-m+p<<endl;
		else
			cout<<n+c<<endl;
	}
	return 0;
}