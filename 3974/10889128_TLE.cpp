/*
poj3972
*/

#include<iostream>
#include <string>
using namespace std;

string str;

int FindPalindrome(int f, int b)
{
	int i;
	i = 0;
	while(f >=0 && b  < str.length())
	{
		if(str[f] != str[b])
			break;
		f--;
		b++;
		i += 2;
	}
	return i;
}

int main()
{
	int i, t;
	int maxx;
	int cc = 0;
	while(cin>>str && str !="END")
	{
		maxx = 0;
		for (i=0; i<str.length()-2; i++)
		{
			if((str.length() - i) * 2 < maxx )
				break;
			if(str[i] == str[i + 1])
			{
				t = FindPalindrome(i, i+1);
				maxx = maxx > t ? maxx : t;
			}
			else if(str[i] == str[i + 2])
			{
				t = FindPalindrome(i, i+2) + 1;
				maxx = maxx > t ? maxx : t;
			}
		}
		cout<<"Case "<<++cc<<": "; 
		cout<<maxx<<endl;

	}
	return 0;
}