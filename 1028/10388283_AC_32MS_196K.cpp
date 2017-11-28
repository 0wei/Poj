#include<iostream>
#include<list>
#include<string>
using namespace std;
int main()
{
	list <string> s;
	list <string>::iterator it;
	list <string>::reverse_iterator rit;
	s.push_back("http://www.acm.org/");
	string str;
	it = --s.end();
	while(cin>>str)
	{
		if(str=="VISIT")
		{
			cin>>str;	
			s.insert(++it,str);
			if(it!=s.end())
				s.erase(it,s.end());
			cout<<str<<endl;
			it = --s.end();
		}
		if(str =="BACK")
		{
			if(it!=s.begin())
				cout<<*(--it)<<endl;
			else
			{
				cout<<"Ignored\n";
			}
		}
		if(str =="FORWARD")
		{
			it++;
			if(it!=s.end())
				cout<<*it<<endl;
			else
			{
				it--;
				cout<<"Ignored\n";
			}
		}
		if(str =="QUIT")
			break;
	}
	return 0;
}