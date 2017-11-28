#include <iostream>
#include <stack>
//#include <fstream>
#include <string>
using namespace std;

//ofstream out("1.txt");
string str;
stack<int> stk;
bool v[6];
bool tautology;

bool GetSult(/*int p*/)
{
	int a, b;
	for (int i = str.length()-1; i>=0; i--)
	{
		switch(str[i])
		{
		case 'K':
		{
			a = stk.top();
			stk.pop();
			b = stk.top();
			stk.pop();
			stk.push(a && b);
			//GetSult(p+1) && GetSult(p+2);
			break;
		}
		case 'A':
		{
			a = stk.top();
			stk.pop();
			b = stk.top();
			stk.pop();
			stk.push(a || b);
			break;
			//return GetSult(p+1) || GetSult(p+2);
		}
		case 'N':
		{
			a = stk.top();
			stk.pop();
			stk.push(!a);
			break;
			//return !GetSult(p+1);
		}
			//	return !v[str[p+1]-'p'];
		case 'C':
		{
			a = stk.top();
			stk.pop();
			b = stk.top();
			stk.pop();
			stk.push(!a || b);
			break;
			//return (!GetSult(p+1)) || GetSult(p+2);
		}
		case 'E':
		{
			a = stk.top();
			stk.pop();
			b = stk.top();
			stk.pop();
			stk.push(a == b);
			break;
			//return GetSult(p+1) == GetSult(p+2);
		}
		default:
			stk.push( v[str[i]-'p']);
		}
	}
	return stk.top();
}

int main()
{
	int i, j;
	while (cin>>str && str!="0")
	{
		while (!stk.empty())
			stk.pop();
		tautology = true;
		for (i=0; i<=31; i++)
		{
			for (j=0; j<5; j++)
				v[j] = (i>>j) % 2;
			
			if (!GetSult(/*0*/))		
			{
				tautology = false;
				goto L;
			}
		}
L:
		if (tautology)
		{
		//	out<<"tautology"<<endl;
			cout<<"tautology"<<endl;
		}
		else
		{
		//	out<<"not"<<endl;
			cout<<"not"<<endl;
		}
	}

	return 0;
}