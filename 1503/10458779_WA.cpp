#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a;
	int i,maxlen = 0,sum[200]={0};
	while(cin>>a&& a!="0")
	{
		if(a.length()>maxlen)
			maxlen = a.length();
		for(i = a.length()-1; i >=0; i--)
			sum[a.length()-1-i]+= a[i]-'0';
	}
	for(i = 0; i < maxlen; i++)
	{
		sum[i+1] += sum[i]/10;
		sum[i]%=10;
	}
	for(i = maxlen-1; i >=0; i--)
		cout<<sum[i];
	cout<<endl;
	return 0;
}