#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a[400];
	char s[100];
	int n,m, i, j,c;
	while(cin>>n>>m)
	{
		for(i = 0; i < 200 ; i++)
			a[i]="";
		while(m--)
		{
			cin>>s;
			c = 0;
			for(i = 0; i < n; i++)
				for( j = i+1; j < n; j++)
					if(s[i]>s[j])
						c++;
			while(a[c]!="")
				c++;
			a[c] = s;
		}
		for(i = 0; i < 200; i++)
			if(a[i]!="")
				cout<<a[i]<<endl;
	}
	return 0;
}