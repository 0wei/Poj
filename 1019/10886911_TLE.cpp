/*
poj1019


*/
#include <iostream>
using namespace std;

int main()
{
	int t, n, i;
	int sum;
	cin>>t;
	while(t--)
	{
		sum = 0;
		cin>>n;
		for (i=1; sum + i < n; i++)
			sum += i;
		if(sum == n)
			cout<<i<<endl;
		else
		{
			for(i=1; sum + i != n; i++);
			cout<<i<<endl;
		}
	}
	return 0;
}