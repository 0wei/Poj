#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s,cc;
	double am, amp=0;
	while(cin>>s&&s!="#")
	{
		if(s=="0")
		{
			printf("%0.0f\n",amp);
			amp = 0;
		}
		else 
		{
			cin>>s>>am>>cc;
			if(cc=="F")
				amp+=am+am;
			else if(cc=="B")
				amp+=am+am/2;
			else
			{
				if(am< 500) amp+=500;
				else amp+=am;
			}
		}
	}
	return 0;
}