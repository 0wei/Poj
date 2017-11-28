#include<iostream>
using namespace std;
int main()
{
	int a[200],n,i,m,t;
	while(cin>>n)
	{
		while(n--)
		{
			cin>>m;
			t = 1;
			for(i = 1; i <= m; i++)
				a[i] = 1;
			while(t <= m)
			{
				for(i = t; i <= m; i+=t)
					a[i]*=-1;
				t++;
			}
			t = 0;
			for(i = 1; i <= m; i++)
				if(a[i] == -1)
					t++;
			cout<<t<<endl;
		}
	}
	return 0;
}