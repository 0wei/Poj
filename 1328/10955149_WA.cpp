#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

struct island
{
	int x, y;
	double left, right;
};

bool cmp(island a, island b)
{
	return a.right < b.right;
}

island pt[1001];

int main()
{
	int T = 1;
	int n, d;
	double tmp;
	int i, j;
	int sum;
	island rang;
	bool solution;
	while (cin>>n>>d && (n!=0 || d!=0))
	{
		sum = 0;
		solution = true;
		for (i=0, j=0; i<n; i++)
		{
			cin>>rang.x>>rang.y;
			if (rang.y > d)
				solution = false;
			if (rang.y > 0)
			{
				pt[j].x = rang.x;
				pt[j].y = rang.y;
				tmp = sqrt((double)d*d - pt[j].y * pt[j].y);
				pt[j].right = pt[j].x + tmp;
				pt[j].left = pt[j].x - tmp;
				j++;
			}
			
		}
		if (!solution || d<0)
		{
			cout<<"Case "<<T++<<"-1"<<endl;
			continue;
		}
		sort(pt, pt+n, cmp);

		rang.right = pt[0].right;
		rang.left = pt[0].left;
		sum += 1;
		for (i=1; i<n; i++)
		{
			if (pt[i].left <= rang.right)
				rang.left = pt[i].left;
			else
			{
				sum++;
				rang.left = pt[i].left;
				rang.right = pt[i].right;
			}
		}
		cout<<"Case "<<T++<<": "<<sum<<endl;
	}
	return 0;
}