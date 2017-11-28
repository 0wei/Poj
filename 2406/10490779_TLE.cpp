#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s,ts,str;
	int flags;
	while(cin>>s&&s!=".")
	{
		
		for(int i = 0 ; i < s.length();i++)
		{
			str+=s[i];
			ts = s;
			flags = 1;
			while(flags&&ts.find(str,0)!=string::npos)
			{
				if(ts.find(str,0)!=0)
					flags = 0;
				else
					ts.erase(ts.find(str,0),str.length());
			}
			if(ts.empty())
			{
				cout<<s.length()/(i+1)<<endl;
				str="";
				break;
			}
		}	
	}
//	system("pause");
	return 0;
}