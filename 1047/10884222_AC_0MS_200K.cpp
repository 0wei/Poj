#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	int num[70];
	int next[70];
	int ok[10];
	int tmp[10];
	int i, j;
	while(cin>>str)
	{
		memset(ok, 0, sizeof(ok));	
		for(i=0; i<str.length(); i++)
		{
			next[i] = num[i] = str[str.length()-1 - i] - '0';
			ok[str[i]-'0']++;
		}
		int t = str.length()-1;
		while(t--)
		{
			memset(tmp, 0, sizeof(tmp));
			for (i=0; i<str.length(); i++)
			{
				next[i] += num[i];
				next[i+1] += next[i] / 10;
				next[i] %= 10;
				tmp[next[i]]++;
			}
			for(j=0; j<10; j++)
				if(tmp[j] != ok[j])
				{
					cout<<str<<" is not cyclic"<<endl;
					goto L;
				}
		}
		cout<<str<<" is cyclic"<<endl;
L:
		continue;
	}
	return 0;
}