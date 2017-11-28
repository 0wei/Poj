#include<iostream>
using namespace std;
const int MAX = 5000000;
bool r[MAX];
int a[MAX];
int main()
{
	int k,t=0,i;
	a[0] = 0;
	r[0] = true;
	while(cin>>k&&k!=-1)
	{
		if(k>t)
		{
			for( i = t; i <k; i++)
			{
				a[i+1] = a[i] -i-1;
				if(a[i+1]<0||r[a[i+1]])
					a[i+1] = a[i] + i+1;			
				//cout<<a1<<" ";
				r[a[i+1]] = true;
			}
			t = k;
		}
			cout<<a[k]<<endl;
	}
	return 0;
}