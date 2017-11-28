#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	float x, y, n, s,r;
	int a,i;
	while(cin>>n)
	{	
		i = 0;
		while(n--)
		{
			cin>>x>>y;
			r = x*x + y*y;
			s = 3.14 * r /2;
			a = s /=50;
			if(a!= s)
				a++;
			cout<<"Property "<<++i<<": This property will begin eroding in year "<<a<<".\n";
		}
		cout<<"END OF OUTPUT.\n";
	}
	return 0;
}