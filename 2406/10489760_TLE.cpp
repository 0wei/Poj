#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s,finds;
	int k,max ;
	while(cin>>s&&s!=".")
	{
		finds = s,max = k = 0;
		for(int i = 0; i < finds.length(); i++)
		{
			while(s.find(finds[i],0)!=string::npos)
			{
				k++;
				s.erase(s.find(finds[i],0),1);
			}
			if(k>max)
				max = k;
			k=0;
		}
		cout<<max<<endl;
	}
//	system("pause");
	return 0;
}