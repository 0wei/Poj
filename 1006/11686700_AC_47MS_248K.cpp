#include <iostream>
using namespace std;

int lcm(int a, int b)
{
	int s = a * b;
	int t;
	while (b)
	{
		t = a % b;
		a = b; 
		b = t;
	}
	return s / a;
}

int China(int a, int b, int r)
{
	int t = lcm(a, b);
	int sum = t;
	while (sum % r!= 1)
	{
		sum += t;
	}
	return sum;
}

int main()
{
	
	int p, e, i, d;
	//cout<<lcm(lcm(23, 28), 33)<<endl;
	int lcm = 21252;
	//cout<<China(23, 28, 33)<<endl;
	int i33 = 1288;
	//cout<<China(28, 33, 23)<<endl;
	int p23 = 5544;
	//cout<<China(33,23,28)<<endl;
	int e28 = 14421;
	int t;
	int cnt = 0;
	while (cin>>p>>e>>i>>d)
	{
		if (p == -1 && e == -1 && i == -1 && d == -1)
			break;
		t = (p*p23 + e * e28 + i * i33 - d + lcm) % lcm;
		t = t == 0 ? lcm : t;
		cout<<"Case "<<++cnt<<": the next triple peak occurs in "<<t<<" days."<<endl;

	}
	return 0;
}