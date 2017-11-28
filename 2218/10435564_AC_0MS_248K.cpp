#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s[200],ci;
	int a,b,w[200], i ,j,n,t,ti;
	while(cin>>ci)
	{
		i =0;
		while(cin>>s[i]&&s[i]!="END")
		{
			cin>>a>>b;
			w[i++] = b-a;
		}
		j= n = i ; 
		while(j--)
		{
			t = 0;
			for(i =0; i < n; i++)
			{
				if(w[i]>t)
				{
					t = w[i];
					ti = i;
				}
			}
			w[ti] = 0;
			cout<<s[ti]<<endl;
		}
		cout<<endl;
	}
	return 0;
}