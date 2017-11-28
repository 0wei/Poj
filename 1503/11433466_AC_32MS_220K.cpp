/*
	poj1503
*/
#include <iostream>
#include <string>
using namespace std;
const int N = 105;
string str[N];
int sum[N];
int main()
{
	int n=-1, i, j;
	while (cin>>str[++n] && str[n].compare("0")!=0);
	memset(sum, 0, sizeof(sum));
	int maxlen = 0;
	for (i=0; i<n; i++)
	{
		int len = str[i].length();
		if (len > maxlen) maxlen = len;
		for (j=len-1; j>=0; j--)
			sum[len-1-j] += str[i][j] - '0';
	}

	for (i=0; i<maxlen-1 ; i++)
	{
		sum[i+1] += sum[i]/10;
		sum[i] %= 10;
	}
	i = maxlen;
	while(sum[i]==0)
		i--;
	while (i>=0)
		cout<<sum[i--];
	cout<<endl;
	return 0;
}