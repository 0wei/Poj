/*
poj3903
*/
#include <iostream>
using namespace std;

int main()
{
	int t;
	int x, y;
	int maxx, tmp ;
	while(cin>>t)
	{
		maxx = tmp = 1;
		cin>>y;
		t--;
		while(t-- != 0)
		{
			cin>>x;
			if(x > y)
			{
				tmp++;
			}
			else
			{
				maxx = maxx < tmp ? tmp : maxx;
				tmp = 1;
			}
			y = x;
		}
		cout<<maxx<<endl;

	}

	return 0;
}