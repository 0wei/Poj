#include <iostream>
using namespace std;

int extended_gcd(int a, int b, int &x, int &y)
{
	int ret , tmp;
	if (b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	ret = extended_gcd(b, a%b, x, y);
	tmp = x;
	x = y;
	y = tmp - a /b *y;
	return ret;
}

int main()
{
	int x, y, d, X, Y, n, m, L;
	/*
	x + m*t = y + n*t + w*L;
	(n - m)*t + w*L = x - y; 
	扩展欧几里得:a*x + b*t = b
	*/
	while (cin>>x>>y>>m>>n>>L)
	{
		d = extended_gcd(n-m, L, X, Y);
		if ((x - y) % d != 0)
			cout<<"Impossible"<<endl;
		else
			cout<<((x - y) / d * X + L) % L<<endl;
	}

	
}