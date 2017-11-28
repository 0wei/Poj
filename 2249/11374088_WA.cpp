#include <iostream>
using namespace std;
//C(n, k)
double C(int c,int k)
{
 double a=1;
 int i,j=2;
 for(i=c;i>c-k;i--)
 a=a*i/(c-i+1);
 return a;
}

int main()
{
	int n, k;
	while (cin>>n>>k && (n+k))
	{
		if (k > n/2) k = n - k;
		if (k == 0)
		{
			cout<<"1"<<endl;
			continue;
		}
		cout<<C(n,k)<<endl;
	}
	return 0;
}