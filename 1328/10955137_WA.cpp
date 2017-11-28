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
	int i;
	int sum;
	island rang;
	bool solution;
	while (cin>>n>>d && (n!=0 || d!=0))
	{
		sum = 0;
		solution = true;
		for (i=0; i<n; i++)
		{
			cin>>pt[i].x>>pt[i].y;
			
			tmp = sqrt((double)d*d - pt[i].y * pt[i].y);
			pt[i].right = pt[i].x + tmp;
			pt[i].left = pt[i].x - tmp;
			if (pt[i].y > d)
				solution = false;
		}
		if (!solution )
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