#include <iostream>
using namespace std;

int Min(int a, int b, int c)
{
	int t = a > b ? b : a;
	return t > c ? c : t;
}

int main()
{
	int p1,p2, p3;
	int ar[1501];
	int i, tmp, n;
	ar[1] = 1;
	p1 = 1;
	p2 = 1;
	p3 = 1;
	for (i=2; i<1501; i++)
	{
		tmp = Min(ar[p1]*2, ar[p2]*3, ar[p3]*5);
		ar[i] = tmp;
		if (tmp == ar[p1]*2)
			p1++;
		if (tmp == ar[p2]*3)
			p2++;
		if (tmp == ar[p3]*5)
			p3++;
	}
	while (cin>>n && n)
		cout<<ar[n]<<endl;
	return 0;
}