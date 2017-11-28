#include <iostream>
#include <queue>
using namespace std;

struct point
{
	int x,y;
};
int map[101][101];
point dir[4] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
queue<point> que;
int step[101][101];
bool visted[101][101];
int main()
{

	int c, r;

	cin>>c>>r;
	int i, j;
	for (i=0; i<r; i++)
		for (j=0; j<c; j++)
			cin>>map[i][j];

	memset(visted, false, sizeof(visted));
	memset(step, 0, sizeof(step));
	/* BFS */
	point pt;
	pt.x = 0;
	pt.y = 0;
	que.push(pt);
	visted[0][0] = true;
	step[0][0] = 1;
	while(!que.empty())
	{
		pt = que.front();
		point tmp = pt;
		que.pop();

		for(i=0; i<4; i++)
		{
			pt = tmp;

			pt.x += dir[i].x;
			pt.y += dir[i].y;

			if(pt.x >= 0 && pt.x < r && pt.y >= 0 && pt.y < c && map[pt.x][pt.y] > map[tmp.x][tmp.y])
			{
				if(visted[pt.x][pt.y] && step[pt.x][pt.y] < step[tmp.x][tmp.y] + 1)
				{
					step[pt.x][pt.y] = step[tmp.x][tmp.y] + 1;
				}
				if(!visted[pt.x][pt.y])
				{
					que.push(pt);
					step[pt.x][pt.y] = step[tmp.x][tmp.y] + 1;
				}
			}
		}
	}

	/* Output */
	int maxx = 0;
	for(i=0; i<r; i++)
	{
		for (j=0; j<c; j++)
		{
		//	printf("%3d ",step[i][j]);
			if(maxx < step[i][j])
				maxx = step[i][j];
		}
	//	cout<<endl;
	}

	cout<<maxx<<endl;
	return 0;
}