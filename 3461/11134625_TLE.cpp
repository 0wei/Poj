#include <iostream>
#include <string>
using namespace std;
 
int main()
{
	string str1, str2;
	int n;
	int i, j;
	int len1, len2, c;
	cin>>n;
	while (n--)
	{
		cin>>str1>>str2;
		len1 = str1.length();
		len2 = str2.length();
		c = 0;
		for (i=0; i<=len2-len1; i++)
		{
			if (str2[i] == str1[0])
			{
				for (j=0; j<len1; j++)
				{
					if(str2[i+j] != str2[j])
						break;
				}
				if (j == len1)
					c++;
			}
		}
		cout<<c<<endl;
	}
	return 0;
}