#include<iostream>
#include<algorithm>
#include <functional> 
#include<string>
using namespace std;
int main()
{
	int a[500], n, i,j,mi;
	string s[500],ss[500],ts;
	bool bl;
	a['0'] = 0, a['1'] = 1;
	a['2'] = a['A'] = a['B'] = a['C'] = 2;
	a['3'] = a['D'] = a['E'] = a['F'] = 3;
	a['4'] = a['G'] = a['H'] = a['I'] = 4;
	a['5'] = a['J'] = a['K'] = a['L'] = 5;
	a['6'] = a['M'] = a['N'] = a['O'] = 6;
	a['7'] = a['P'] = a['R'] = a['S'] = 7;
	a['8'] = a['T'] = a['U'] = a['V'] = 8;
	a['9'] = a['W'] = a['X'] = a['Y'] = 9;
	while(cin>>n)
	{
		int c[500] = {0};
		i = 0,bl = false;
		while(n--)
		{
			cin>>s[i++];
		}
		mi = i;
		for(i = 0; i < mi;i++)
			while(s[i].find('-',0)!=s[i].npos)
				s[i].erase(s[i].find('-',0),1);
		for(i = 0; i < mi; i++)
		{
			for(j = 0; j < s[i].length();j++)
				s[i][j] = a[s[i][j]]+'0';
		}
		n = mi;
		while(n--)
		{
			for(i = 0; i < mi-1; i++)
			{
				j = 1;
				if(s[i][0]>s[i+1][0])
					swap(s[i],s[i+1]);
				else if(s[i][0] ==s[i+1][0])
				{	while(j<6&&s[i][j]==s[i+1][j])
							j++;
				if(j<6&&s[i][j]>s[i+1][j])
					swap(s[i],s[i+1]);
				}
			}
		}
		for(i = 0; i < mi; i++)
		{	
			if(s[i]=="")continue;
			ts= s[i];
			for(j = i+1; j < mi; j++)
				if(ts == s[j])
				{
					c[i]++;
					s[j] = "";
				}
		}	
		for(i = 0; i < mi; i++)
			if(c[i]> 0&&s[i]!="")
			{
				for(j = 0; j <s[i].length(); j++)
				{
					bl = true;
					cout<<s[i][j];
					if(j ==2)
						cout<<"-";
				}
				cout<<" "<<c[i]+1<<endl;
			}
			if(bl ==false)
				cout<<"No duplicates."<<endl;
	}
	return 0;
}