
#include <iostream>
#include <string>
using namespace std;


int main()
{
	string str[100];
	int ar[10000];
	memset(ar, -1, sizeof(ar));
	int l, n;
	int i, j, k;
	int js;
	cin>>l>>n;
	for (i=0; i<n; i++)
	{
		cin>>str[i];
	}
	for (i=0; i<l; i++)
	{
		js = 0;
		for (j=0; j<l; j++)
		{
			for (k=j+1; k<l; k++)
			{
				if (str[i][j] > str[i][k])
				{
					js++;
				}
			}
		}
		ar[js] = i;
	}
	for (i=0; i<10000; i++)
		if (ar[i] != -1)
			cout<<str[ar[i]]<<endl;
	return 0;
}