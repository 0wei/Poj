#include<iostream>
#include<string>
using namespace std;
int main()
{
	
	char s[1000010];
	string ts,str;
	int flags,k,i,c=0;
	while(scanf("%s",s)!=EOF&&s[0]!='.')
	{
		k=1,i = 0;
		while(k<=strlen(s)/2)
		{
			for(; i < k;i++)
				str+=s[i];
		
			if(strlen(s)%str.length()!=0)
			{
				k++;
				continue;
			}
			ts = s;
			flags = 1;
			while(flags&&ts.find(str,0)!=string::npos)
			{
				if(ts.find(str,0)!=0)
				{
					k += ts.find(str,0)-1;
					flags = 0;
				}
				else
				{
					k++;
					ts.erase(ts.find(str,0),str.length());
				}
			}
			
			if(ts.empty())
			{
				cout<<strlen(s)/(i)<<endl;
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