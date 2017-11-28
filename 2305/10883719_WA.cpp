#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int arr[1005];
string str;
string mstr;
int tmp;

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
	int mov;
	while(cin>>b && b)
	{
		cin>>str>>mstr;
		m = 0;
		len = mstr.length()-1;
		for(i=0; i<mstr.length(); i++)
			m += pow(1.0 * b, len-i) * (mstr[i] - '0');
		len = str.length()-1;
		for (i=0; i<str.length(); i++)
			arr[i] = pow(1.0 * b, len-i) * (str[i] - '0');
		for(i=0; i<len; i++)
		{
			arr[i+1] += arr[i] % m ;
		}
		dfs(arr[i] % m, b);
		cout<<endl;

	}
	return 0;
}