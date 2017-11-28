#include<iostream>
#include<string>
using namespace std;
int main()
{
	string ss[200],s,ts[200];
	int n,m, i, j,c,si,a[200],t;
	while(cin>>n>>m)
	{
		si = 0;
		for(i = 0; i < 200 ; i++)
			ss[i]="";
		while(m--)
		{
			cin>>s;
			c = 0;
			for(i = 0; i < n; i++)
				for( j = i+1; j < n; j++)
					if(s[i]>s[j])
						c++;
					ss[si] = s;
					a[si++] = c;
		}
		m = si,j = 0;
		while(si--)
		{
			n = -1;
			for(i = 0; i <m; i++)
			{	if(a[i] > n)
				{
					t = i;
					n = a[i];
				}
			}
			ts[j++] = ss[t];
			a[t] = -1;
		}
		for(i = m-1; i >=0 ; i--)
			cout<<ts[i]<<endl;
	}
	return 0;
}