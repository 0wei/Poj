#include<iostream>
using namespace std;
const int p1 = 23, e1 = 28, i1 = 33;
int main()
{
	int p, e, i, d, day,c=0; 
	while(cin>>p>>e>>i>>d&&p+e+i!=-3)
	{
		p%=p1,e%=e1,i%=i1;
		day = p;
		while((day % p1 != p|| day % e1 != e|| day % i1 != i)||day<=d)
		{
			day+=p1;
		}
		printf("Case %d: the next triple peak occurs in %d days.\n",++c,day-d);
	}
	return 0;
}