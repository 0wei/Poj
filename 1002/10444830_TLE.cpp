#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main()
{
	int a[200],c ,n,ni, i,j,nn,its;
	vector<int> s;
	string ts;
	char cc[20];
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
		i = 0,bl = false,nn = n,s.clear();
		while(nn--)
		{
			cin>>ts;
			while(ts.find('-',0)!=ts.npos)
				ts.erase(ts.find('-',0),1);
			for(i = 0; i <  7; i++)
				ts[i] = a[ts[i]]+'0';
			sscanf(ts.c_str(),"%d",&its);
			s.push_back(its);
		}
		sort(s.begin(),s.end());
		for(i = 0; i < n; i++)
		{	
			if(s[i]==-1)continue;
			its= s[i];
			c=1;
			for(j = i+1; j < n; j++)
				if(its == s[j])
				{
					c++;
					s.erase(s.begin()+j);   //减少循环次数
					j--,n--;
				}
			if(c>1)
			{
				bl = true;
				sprintf(cc,"%d",its);
				ts = cc,nn = 0;
				if(ts.length()<7)
					for(; nn < 7- ts.length();nn++)
					{
						cout<<"0";
						if(nn ==2)
							cout<<"-";	
					}
				for(ni = 0; ni < ts.length(); ni++)
				{
					cout<<ts[ni];
					if(ni+nn ==2)
						cout<<"-";
				}
				cout<<" "<<c<<endl;
			}
		}	
		if(bl ==false)
				cout<<"No duplicates."<<endl;
	}
	return 0;
}