#include<iostream>
#include<string>
using namespace std;
int main()
{
	int m,n,jobsalary[2000],salary,i;
	string jobname[2000],tstr,descriptions;
	while(cin>>m>>n)
	{
		i = 0;
		while(i<m)
		{
			cin>>jobname[i]>>jobsalary[i];
			i++;
		}
		while(n>0)
		{
			cin>>tstr;
			if(tstr!=".")
				descriptions+=tstr+" ";
			else
			{
				salary = 0;
				for(i = 0; i <m; i++)
				{
					while(descriptions.find(jobname[i],0)!=string::npos)
					{
						salary+=jobsalary[i];
						descriptions.erase(descriptions.find(jobname[i],0),jobname[i].length());
					}
				}
				cout<<salary<<endl;
				descriptions.clear();
				n--;
			}
		}

	}
	return 0;
}