#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a, int b)
{
	return  a > b;
}
int main()
{
	int n, a[100000], k;
	int i, j;
	int t;
	while (cin>>n)
	{
		for (i=0; i<n; i++)
			cin>>a[i];
		cin>>k;
		t = 0;
		while(true)
		{
			sort(a, a+n, cmp);
			if (a[0] <= 0)
				break;
			a[0] -= k;
			for (i=1; i<n; i++)
				a[i] -= 1;
			t++;
		}
		cout<<t<<endl;
	}
	return 0;
}