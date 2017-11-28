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
	while (cin>>str[++n] && str[n][0] != '0');
	memset(sum, 0, sizeof(sum));
	int maxlen = 0;
	for (i=0; i<n; i++)
	{
		int len = str[i].length();
		if (len > maxlen) maxlen = len;
		for (j=len-1; j>=0; j--)
			sum[len-1-j] += str[i][j] - '0';
	}

	for (i=0; i<maxlen ; i++)
	{
		sum[i+1] += sum[i]/10;
		sum[i] %= 10;
	}
	for (i=maxlen-1; i>=0; i--)
		cout<<sum[i];
	cout<<endl;
	return 0;
}