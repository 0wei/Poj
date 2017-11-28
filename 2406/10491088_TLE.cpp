#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s,ts,str;
	int flags,k,i;
	while(cin>>s&&s!=".")
	{
		k=1,i = 0;
		while(k<=s.length()/2){
		for(; i < k;i++)
			str+=s[i];
			ts = s;
			flags = 1;
			while(flags&&ts.find(str,0)!=string::npos)
			{
				if(ts.find(str,0)!=0)
				{
					k += ts.find(str,0);
					flags = 0;
				}
				else
				{
					k++;
					ts.erase(ts.find(str,0),str.length());
				}
			}
			k--;
			if(ts.empty())
			{
				cout<<s.length()/(i)<<endl;
				str="";
				goto L;
			}
		}
		cout<<"1"<<endl;
		str="";
L:
		continue;
	}
//	system("pause");
	return 0;
}