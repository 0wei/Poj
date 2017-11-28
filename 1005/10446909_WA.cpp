#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	float x, y, n, s,r;
	int a,i;
	while(cin>>n)
	{
		while(n--)
		{
			i = 0;
			cin>>x>>y;
			r = x*x + y*y;
			s = 3.14 * r /2;
			s /=50;
			a = s;
			if(a!=s)
				a+=1;
			cout<<"Property "<<++i<<": This property will begin eroding in year "<<a<<".\n";
		}
		cout<<"END OF OUTPUT.\n";
	}
	return 0;
}