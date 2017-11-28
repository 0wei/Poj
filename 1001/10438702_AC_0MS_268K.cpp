#include<iostream>
#include<math.h>
#include<string>
using namespace std;
int main()
{
	string s;
	int a[1000],b[1000];
	int n,l,i,j,p,lb;
	while(cin>>s>>n)
	{
		
		l = s.length();
		for( i = l-1; i >=0; i--)
		{
			if(s[i]=='0') 
				l--;
			else break;	
		}
		if(l==0){cout<<"0"<<endl; continue;}
		if(s.find('.',0)!=string::npos)
		{
			p = l -1 - s.find('.',0);  //小数点位数
			s.erase(s.begin()+s.find('.',0));  //移除小数点
			p*=n,l--;
		}
		else p= 0;
		for(i = l-1; i >=0; i--)
			a[l-1-i] = b[l-1-i] = s[i] - '0';
		n--,lb = l;
		while(n--)
		{
			int r[1000] = {0};
			for(i = 0; i < l ; i++)
				for(j = 0; j < lb;j++)
					r[i+j] += a[i] * b[j];
				for(i = 0; i < l+lb; i++)
				{
					r[i+1] +=r[i]/10;
					b[i] = r[i]%=10;
				}
				lb+=l;
		}
		while(b[lb-1]==0)
			lb--;
		if(lb>0)
		{
			if(lb-1<p)
			{
				cout<<".";
				for(i = 0; i < p-lb;i++)
					cout<<"0";
			}
			for(i =lb-1; i >=0; i--)
			{
				cout<<b[i];
				if(p&&i == p)
					cout<<".";
			}
		}
		else cout<<"0"<<endl;
		cout<<endl;	
	}	
	return 0;
}