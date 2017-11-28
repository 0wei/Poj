#include <iostream>
#include <algorithm>
using namespace  std;

struct point
{
	int x,y;
}data[25002];

int cmp(const point &a,const point &b)                          
{
	if(a.x!=b.x)
		return a.x<b.x;
	return a.y>b.y;
}

int main()
{
	int n,t,i;
	cin>>n>>t;
	for (i=0;i<n;i++)
		cin>>data[i].x>>data[i].y;
	sort(data,data+n,cmp);
	if (data[0].x==1)
	{
		if(data[0].y>=t)
		{
			cout<<"1"<<endl;
			return 0;
		}
		int j=0;
		int begin,end;
		int ans=1;
		begin=end=data[0].y;
		bool find=0;
		while (!find)
		{
			for (i=j+1;i<n;i++)
			{
				if (data[i].x<=end+1&&data[i].y>end)
				{
					j=i;
					end=data[i].y;
				}
			}
			if (begin==end)
				break;
			if(end>=t)
				find=1;
			ans++;
			begin=end;
		}
		if(find)
			cout<<ans<<endl;
		else
			cout<<"-1"<<endl;
	} 
	else
		cout<<"-1"<<endl;
	//system("pause");
	return 0;
}