#include<iostream>
using namespace std;
int main()
{
	int k,n,i;
	double s;
	while(scanf("%d%d",&n,&k)!=EOF&&(n+k))
	{
		s=1.0;
		if(k<n/2)k=n-k;
		for(i=n;i>n-k;i--)
		{
			s*=1.0*i/(n-i+1);
		}
		printf("%0.0f\n",s);
	}
}
