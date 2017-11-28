#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n,a,b,c,aa[20],su,i;
	string s[20],ss[2];
	while(cin>>n&&n!=-1)
	{
		su = 0;
		for(i = 0; i <n ;i++)
		{
			cin>>a>>b>>c>>s[i];
			aa[i] = a*b*c;
			su+=a*b*c;
		}
		su/=n;
		for(i = 0; i < n; i++)
		{
			if(aa[i]>su)
				ss[0] = s[i];
			if(aa[i] <su)
				ss[1] = s[i];
		}
		cout<<ss[0]<<" took clay from "<<ss[1]<<"."<<endl;
	}
	return 0;
}