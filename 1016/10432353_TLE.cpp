#include<iostream>
using namespace std;
int main()
{
		__int64 x, y, m, n, l ,tx,ty,su;
		while(scanf("%I64d%I64d%I64d%I64d%I64d",&x,&y,&m,&n,&l)!=EOF)
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
				printf("%I64d\n",su);
	}
	return 0;
}