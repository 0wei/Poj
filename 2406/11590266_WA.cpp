#include <iostream>
using namespace std;
char str[100000005];
int main()
{
	int i, k, p, len;
	while (scanf("%s", str) != EOF && str[0] != '.')
	{
		len = strlen(str);
		p = k = 1;
		for (i=0; i<len; i++)
		{
			if (str[i] != str[i % p ])
				p = k;
			else
				k++;
		}
		cout<<len/p<<endl;
	}
	return 0;
}