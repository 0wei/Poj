#include<iostream>
using namespace std;
int main()
{
	int m,w,h,x,y,sx,sy;
	while(cin>>m&&m)
	{
		x=y = sx = sy =0;
		while(cin>>w>>h&&w+h!=-2)
		{
			if(x+w<=m)
			{
				x +=w;
				if(h>y)
					y = h;
			}else
			{
				if(sx < x)
					sx =x;
				sy +=y;
				x = w;
				y = h;
			}
		}
		if(sx < x)
			sx =x;
		sy += y;
		cout<<sx<<" x "<<sy<<endl;
	}
	return 0;
}