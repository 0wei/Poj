#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a;
	int i,aa[30];
	while(cin>>a)
	{
		for(i = 0 ; i <a.length(); i++)
			aa[i] =0;	
		for(i = 0 ; i < a.length(); i++)
		{
			if(a[i] =='B'||a[i] =='F'||a[i] =='P'||a[i] =='V') aa[i] = 1;
			else if(a[i] =='C'||a[i] =='G'||a[i] =='J'||a[i] =='K'||a[i] =='Q'||a[i] =='S'||a[i] =='X'||a[i] =='Z') aa[i] = 2;
			else if(a[i] =='D'||a[i] =='T') aa[i] = 3;
			else if(a[i] =='L') aa[i] = 4;
			else if(a[i] =='M'||a[i] =='N') aa[i] = 5;
			else if(a[i] =='R') aa[i] = 6;
			else a[i] = 0;
		}
		for(i = 0 ; i < a.length()-1; i++)
			if(aa[i] == aa[i+1])
				aa[i] = 0;
		for(i = 0 ; i < a.length(); i++)
			if(aa[i]!=0)cout<<aa[i];
		cout<<endl;
	}
	return 0;
}