#include<iostream>
#include<string>
using namespace std;
int main()
{
	char cx[99999] ,cy[99999];
	int n,x=0,y=1 ;
	while(cin>>n)
	{
		while(n--)
		{
			cin>>cx>>cy;
			x = atoi((char*)cx);
			y = atoi((char*)cy);
			itoa(x,cx,10);
			itoa(y,cy,10);
			strrev(cx);
			strrev(cy);
			x = atoi((char*)cx);
			y = atoi((char*)cy);
			x+=y;
			itoa(x,cx,10);
			strrev(cx);
			x = atoi((char*)cx);
			cout<<x<<endl;
		}
	}
	return 0;
}