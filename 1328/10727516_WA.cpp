#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
struct point{
	int x,y;
	double l,r;
};
vector<point> pt;

int r,n;

bool cmp(point p1,point p2)
{
	return p1.x<p2.x;
}
int main()
{
	int i,sum,cases=0;
	double loc;
	point tmp;
	bool flags=false;
	while(cin>>n>>r&&n+r)
	{
		sum=0;flags=false;
		for( i=0;i<n;i++)
		{
			cin>>tmp.x>>tmp.y;
			pt.push_back(tmp);
			if(tmp.y>r)flags=true;
		}
		if(flags)
		{
			cout<<"-1"<<endl;
			continue;
		}
		sort(pt.begin(),pt.end(),cmp);
		
		for(i=0;i<pt.size();i++)
		{
			pt[i].l= pt[i].x- sqrt((double)r*r-pt[i].y*pt[i].y);
			pt[i].r= pt[i].x-pt[i].l+ pt[i].x;
		}
		i=0;
		while(i<pt.size())
		{
			loc=pt[i++].r;
			sum++;
			while(i<pt.size()&&pt[i].l-loc<1e-8)
			{
				i++;
			}
		}
		cout<<"Case "<<++cases<<": "<<sum<<endl;
		pt.clear();
	}
	return 0;
}