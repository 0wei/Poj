#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s[100];
	int n,ni,i,m,a[200],b[200],a1,b1,t,it;
	while(cin>>n)
	{
		for(i = 0; i<n; i++)
		{	a[i] = 0, b[i] = 0;}
		i =  0,t = 0,ni = n;
		while(ni--)
		{	
			cin>>s[i];
			m = 4; 
			while(m--)
			{
				cin>>a1>>b1;
				if(b1!=0) { a[i]++,b[i] += b1+(a1-1)*20; }
			}
			i++;
		}
		for(i = 0; i < n; i++)
		{	if(a[i]>t) { t = a[i],it = i;}}
		for(i = 0; i < n; i++)
		{	if(a[i] ==a[it])
			{
				if(b[i]<b[it])
					it = i;
			}
		}
			cout<<s[it]<<" "<<a[it]<<" "<<b[it]<<endl;
		
	}
	return 0;
}