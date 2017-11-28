#include<iostream>
#include<string>
using namespace std;
int main()
{
	int m,n,jobsalary[2000],salary=0,i;
	string jobname[2000],tstr;
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
			{
				for(i = 0; i < m; i++)
					if(jobname[i]==tstr)
						salary+=jobsalary[i];
			}
			else
			{
				cout<<salary<<endl;
				salary = 0;
				n--;
			}
		}
	}
	return 0;
}