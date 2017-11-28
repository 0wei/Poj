#include<iostream>
#include<algorithm> 
#include<string>
using namespace std;
int main()
{
	string key,c,a[1000],tk,at[1000];
	int av,k[15],i;
	while(cin>>key&&key!="THEEND")
	{
		cin>>c;
		av = c.length()/key.length();
		for( i =0 ; i < c.length(); i++)
			a[i/av]+=c[i];
		tk = key;
		sort(tk.begin(),tk.end());
		for(i = 0; i < key.length(); i++)
		{
			k[i] = key.find(tk[i],0);
			key.replace(k[i],1,1,'0');
		}
		for(i = 0; i < key.length(); i++)
				at[k[i]] = a[i];
		for(int j =0; j <av; j++)
			for(i = 0; i<key.length(); i++)
				cout<<at[i][j];
		cout<<endl;
		for(i = 0; i < key.length(); i++)
			a[i].clear();
	}
	return 0;
}