#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	string s,ss,vs,vc,v = "aeiou",c = "bcdfghjklmnpqrstvwxyz";
	int a[27],i,p;
	bool bl;
	for(i = 0; i < 27; i++)  
		a[i] = 1;
	a[0] = a[4] = a[8] = a[14] = a[20] =  0;
	while(cin>>s&&s!="end")
	{
		bl = true,ss= s,vc = vs = "";
		if(s.find('a',0) ==string::npos &&s.find('e',0) ==string::npos &&s.find('i',0) == string::npos&&s.find('o',0) ==string::npos&&s.find('u',0)==string::npos)
		{	
			cout<<"<"<<s<<"> is not acceptable."<<endl;	
			continue;
		}
		if(ss.length()>2)
		{
			sort(ss.begin(),ss.end());
			for(i = 0 ; i < ss.length(); i++)
			{	
				if(ss[i] == 'a'||ss[i] == 'e'||ss[i] == 'i'||ss[i] == 'o'||ss[i] == 'u') 
				{	vs+=ss[i];}
				else
				{	vc+=ss[i];}
			}
			if(vs.length()>2)
			{
				for(i = 0; i < vs.length()-2; i++)
				{
					p = v.find(vs[i],0);
					if(vs[i+1]==v[p+1]&&vs[i+2]==v[p+2])
					{
						bl = false;
						cout<<"<"<<s<<"> is not acceptable."<<endl;
						break;
					}
				}
			}
			if(bl&&vc.length()>2)
			{
				for(i = 0; i < vc.length()-2; i++)
				{
					p = c.find(vc[i],0);
					if(vc[i+1]==c[p+1]&&vc[i+2]==c[p+2])
					{
						bl = false;
						cout<<"<"<<s<<"> is not acceptable."<<endl;
						break;
					}
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