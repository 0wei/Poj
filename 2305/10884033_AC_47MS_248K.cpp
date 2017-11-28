#include <iostream>
#include <string>
using namespace std;

string str;
string mstr;


void dfs(int p, int b)
{
	if(p/b!=0)
		dfs(p / b, b);
	cout<<p%b;
}

int main()
{
	int b, p, m;
	int len;
	int i;
	int tmp;
	while(cin>>b && b)
	{
		cin>>str>>mstr;
		m = tmp = 0;
		for(i=0; i<mstr.length(); i++)
		{
			m *= b;
			m += mstr[i] -'0';
		}
		for (i=0; i<str.length(); i++)
		{
			tmp *= b;
			tmp += str[i] - '0';
			tmp %= m;	
		}
		dfs(tmp, b);
		cout<<endl;

	}
	return 0;
}