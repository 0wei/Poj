#include<iostream>
using namespace std;
int main()
{
	int n, a[99999],b[99999],i = 0,c=0;
	bool bl;
	while(cin>>n&&n)
	{
		bl = true,c = 0;
		for(i = 0 ;i <n ;i++)
		{
			cin>>a[i];
			b[i] = a[i];
		}
		while(bl)
		{
			a[0] = b[n-1]/2+ b[0]/2;
			for(i = 1; i < n; i++)
				a[i] = b[i-1]/2+b[i]/2;
			for(i =0; i< n; i++)
			{
				if(a[i] %2 !=0)
					a[i]++;
			}
			c++;
			for(i = 0 ; i < n-1; i++)
				if(a[i] !=a[i+1])
					break;
			if(i ==n-1)
			{
				bl = false;
				cout<<c<<" "<<a[0]<<endl;
			}
			else
				for(i =0 ;i < n; i++)
					b[i] = a[i];
		}
	}
	return 0;
}