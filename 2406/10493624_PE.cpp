#include<stdio.h>
#include<string>
using namespace std;
int main()
{	
	char s[1000010];
	string ts,str;
	while(scanf("%s",s)!=EOF&&s[0]!='.')
	{
		ts = s;
		for(int i = 1; i <= ts.size();i++)
		{
			
			if(ts.size()%i!=0)	continue;
			str = ts.substr(0,i);
			while(str.size()<ts.size())
			{
				if(ts.length()%str.length()==0)
					str+=str;
				else str+=ts.substr(0,i);
			}
			if(str==ts)
			{
				printf("%d",strlen(s)/i);
				break;
			}
		}
	}
	//	system("pause");
	return 0;
}