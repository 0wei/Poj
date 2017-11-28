#include <iostream>
using namespace std;

int main()
{
	char str[300];
	int sum;
	while(gets(str) && str[0] != '#')
	{
		sum = 0;
		for (int i=0; i<strlen(str); i++)
		{
			if(str[i] >='A' && str[i] <='Z')
				sum += (i + 1) * (str[i] - 'A' + 1);
		}
		cout<<sum<<endl;
	}

	return 0;
}