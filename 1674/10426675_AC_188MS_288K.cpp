#include<iostream>
using namespace std;
int main()
{
	int t,n,a[10001],i,c;
	while(cin>>t)
	{
		while(t--)
		{
			c=0;
			cin>>n;
			for(i = 1; i <= n; i++)
				cin>>a[i];
			for(i = 1; i<=n ;i ++)
				while(a[i] !=i)
				{
					swap(a[a[i]],a[i]);
					c++;
				}
			cout<<c<<endl;
		}
	}
	return 0;
}