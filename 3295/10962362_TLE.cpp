#include <iostream>
#include <stack>
#include <fstream>
#include <string>
using namespace std;

ofstream out("1.txt");
string str;
stack<int> stk;
bool v[6];
bool tautology;

bool GetSult(int p)
{
	
	switch(str[p])
	{
	case 'K':
		return GetSult(p+1) && GetSult(p+2);
	case 'A':
		return GetSult(p+1) || GetSult(p+2);
	case 'N':
		return !GetSult(p+1);
		//	return !v[str[p+1]-'p'];
	case 'C':
		 return (!GetSult(p+1)) || GetSult(p+2);
	case 'E':
		return GetSult(p+1) == GetSult(p+2);
	default:
		return v[str[p]-'p'];
	}
}

int main()
{
	int i, j;
	while (cin>>str && str!="0")
	{
		tautology = true;
		for (i=0; i<=31; i++)
		{
			for (j=0; j<5; j++)
				v[j] = (i>>j) % 2;
			
			if (!GetSult(0))		
			{
				tautology = false;
				goto L;
			}
		}
L:
		if (tautology)
		{
			out<<"tautology"<<endl;
			cout<<"tautology"<<endl;
		}
		else
		{
			out<<"not"<<endl;
			cout<<"not"<<endl;
		}
	}

	return 0;
}