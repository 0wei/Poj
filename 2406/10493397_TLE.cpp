#include<iostream>
#include<string>
using namespace std;
int main()
{	
	char s[1000010];
	string str,copystr;
	int lens;
	while(scanf("%s",s)!=EOF&&s[0]!='.')
	{
		lens = strlen(s);
		for(int i = 0; i <= strlen(s);i++)
		{
			str+=s[i];
			copystr = str;
			if(lens%str.length()!=0)	continue;
			while(copystr.length()!=lens)
			{
				if(lens%copystr.length()==0)
					copystr+=copystr;
				else copystr+=str;
			}
			if(copystr==s)
			{
				cout<<lens/(i+1)<<endl;
				str="";
				goto L;
			}
		}
		cout<<"1"<<endl;
		str="";
L:
		continue;
	}
	//	system("pause");
	return 0;
}