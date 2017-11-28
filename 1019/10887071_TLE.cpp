/*
poj1019


*/
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int t,  i;
	int sum, x;
	int n;
	cin>>t;
	while(t--)
	{

		cin>>n;
		x = sqrt(2.0 *n);
		if(x * (x + 1) == n*2)
			cout<<x<<endl;
		if(x * (x + 1) > n*2)
		{
			n -= x-1 + (x - 1) * (x - 2)/2;
			sum = 0;
			for (i=x-2; sum + i < n; i++)
				sum += i;
			if(sum == n)
				cout<<i<<endl;
			else
			{
				for(i=1; sum + i != n; i++);
				cout<<i<<endl;
			}
		}
	}
	return 0;
}