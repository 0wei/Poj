#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n,a[20],ia,iaa,i,j,c,sl[3],sr[3];;
	string si[10],sii[10],s[10];
	char ca ;
	while(cin>>n)
	{
		while(n--)
		{
			for(i = 0; i < 12; i ++)
				a[i] = 0;
			for(i = 0; i < 3; i++)
			{
				cin>>si[i]>>sii[i]>>s[i];
			}
			ia = 0;
			iaa = 0;
			while(iaa != 24)
			{	
				for(i = 0; i < 12; i ++)
					a[i] = 0;
				if(ia == 12)
					ia = 0;
				if(iaa <12)
					a[ia++] = 1;
				else 
					a[ia++] = -1;
				iaa++;
				for(i = 0; i < 3; i++)
					sl[i] = sr[i] = 0;
				for(i = 0; i < 3; i++)
				{
					for(j = 0; j < si[i].length();j++)
						sl[i] +=a[si[i][j]-'A'];
					for(j = 0; j <sii[i].length(); j++)
						sr[i] += a[sii[i][j] -'A'];
				}
				c = 0;
				for(i = 0; i < 3; i++)
				{
					if(s[i] =="even"&& sl[i]==sr[i]) c++;
					else if(s[i] =="up"&& sl[i] > sr[i]) c++;
					else if(s[i] =="down"&& sl[i] < sr[i]) c++;
				}
				ca = 'A';
				if(c==3)
				{
					ca +=ia-1;
					if(iaa<12)
						cout<<ca<<" is the counterfeit coin and it is heavy."<<endl;
					else
						cout<<ca<<" is the counterfeit coin and it is light."<<endl;
				}
			}
		}	
	}
	return 0;
}