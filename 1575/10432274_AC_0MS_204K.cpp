#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	int a[27],i;
	bool bl;
	for(i = 0; i < 27; i++)  
		a[i] = 1;
	a[0] = a[4] = a[8] = a[14] = a[20] =  0;
	while(cin>>s&&s!="end")
	{
		bl = true;
		if(s.find('a',0) ==string::npos &&s.find('e',0) ==string::npos &&s.find('i',0) == string::npos&&s.find('o',0) ==string::npos&&s.find('u',0)==string::npos)
		{	
			cout<<"<"<<s<<"> is not acceptable."<<endl;	
			continue;
		}
		if(s.length()>2)
		{
			for(i = 0 ; i < s.length()-2; i++)
			{	
				if(a[s[i]-'a']==a[s[i+1]-'a']&&a[s[i]-'a']==a[s[i+2]-'a']&&a[s[i+1]-'a']==a[s[i+2]-'a'])
				{
					bl = false;
					cout<<"<"<<s<<"> is not acceptable."<<endl;
					break;
				}
			}
		}
		if(bl&&s.length()>1)
		{
			for(i = 0; i < s.length()-1; i++)
				if(s[i]==s[i+1]&&s[i]!='e'&&s[i]!='o')
				{
					bl = false;
					cout<<"<"<<s<<"> is not acceptable."<<endl;
					break;
				}
		}
		if(bl)
			cout<<"<"<<s<<"> is acceptable.\n";
	}
	return 0;
}