#include<iostream>
using namespace std;
int main()
{
	int a[2000],i=0,n,m ,j,k;
	bool bll = true,bl[2000];
	while(cin>>n)
	{
		while(cin>>m&&m)
		{
			k = n;
			while(k--)
				bl[k] = true;
			bll = true;
			a[i++] = m;
			if(i == n)
			{
				bl[a[0]] = false;
				for(i = 1;i < n-1; i++)
				{
					if(a[i-1]< a[i])
						bl[a[i]] = false;
					else
						for(j = a[i-1]-1; j >0;j--)
						{
							if(bl[j] == true)
								if( a[i] == j)
								{
									bl[a[i]]=false;
									break;
								}
								else 
								{
									cout<<"N0"<<endl;
									i = n;
									bll = false;
									break;
								}
						}
				}
				if(bll)
					cout<<"Yes"<<endl;	
				i = 0;
				
			}
		}
		cout<<endl;
	}
	
	return 0;
}