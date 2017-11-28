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
	return p1.l<p2.l;
}
int main()
{
	int i,sum,cases=0;
	//double loc;
	point tmp;
	bool flags=false;
	while(cin>>n>>r&&n||r)
	{
		sum=0;flags=false;pt.clear();
		for( i=0;i<n;i++)
		{
			cin>>tmp.x>>tmp.y;
			if(tmp.y>0)
				pt.push_back(tmp);
			if(tmp.y>r)flags=true;
		}
		if(flags||r<0)
		{
			cout<<"Case "<<++cases<<": -1"<<endl;
			continue;
		}
	
		for(i=0;i<pt.size();i++)
		{
			pt[i].l= pt[i].x- sqrt((double)r*r-pt[i].y*pt[i].y);
			pt[i].r= pt[i].x-pt[i].l+ pt[i].x;
		}
		sort(pt.begin(),pt.end(),cmp);
		i=0;
		while(i<pt.size())
		{
			tmp=pt[i++];
			sum++;
			while(i<pt.size()&&pt[i].l<=tmp.r&&tmp.l<=pt[i].l)   //注意范围是不断的缩小的左右判断
			{													//tmp.l <=pt[i].l <= tmp.r
				tmp.l=pt[i].l;
				if(pt[i].r-tmp.r<1e-8)
					tmp.r=pt[i].r;
				i++;
			}
		}
		cout<<"Case "<<++cases<<": "<<sum<<endl;
		
	}
	return 0;
}