#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int x, y, m, n, l ,tx,ty,su;
	while(cin>>x>>y>>m>>n>>l)
	{
		x%=l,y%=l;
		tx = x,ty = y,su = 0;
		while(x!=y)
		{
			
			x+=m,y+=n;	
			if(x>=l)
				x %= l;
			if(y >=l)
				y %= l;
			su++;
			if(x == tx&& y ==ty)
			{
				cout<<"Impossible"<<endl;
				break;
			}
		}
		if(x==y)
			cout<<su<<endl;
	}
	return 0;
}