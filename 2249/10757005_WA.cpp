#include<iostream>
using namespace std;
int main()
{
	int k,n,i,j,u,v;
	double s;
	while(scanf("%d%d",&n,&k)!=EOF&&n&&k)
	{
		s=1.0;
		j=k,u=v=1;
		for(i=n;i>n-k;i--)
		{
			u*=i,v*=j;
			if(u%v==0)
			{
				s*=1.0*u/v;
				u=v=1;
			}
			if(j>1)	
				j--;
		}
		s*=1.0*u/v;
		printf("%0.0lf\n",s);
	}
}