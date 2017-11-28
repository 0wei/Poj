/*
poj1979
*/
#include <iostream>
#include <queue>
using namespace std;
struct point
{
	int x, y;
};
point dir[4] = {{1,0},{-1,0},{0,1},{0,-1}};

char map[30][30];
bool used[30][30];
queue<point> que;
int w, h;

int main()
{
	int i, j;


	point p;
	while(cin>>w>>h && w + h != 0)
	{
		for (i=0; i<h; i++)
		{
			cin>>map[i];
			for (j=0; j<w; j++)
				if(map[i][j] == '@')
				{
					p.x = j;
					p.y = i;
				}
		}
		int t = 1;
		while(!que.empty())que.pop();
		memset(used, false, sizeof(used));
		que.push(p);
		used[p.y][p.x] = true;
		while(!que.empty())
		{
			point pt;
			p = que.front();
			pt = p;
			que.pop();

			for (i=0; i<4; i++)
			{
				p = pt;
				p.x += dir[i].x;
				p.y += dir[i].y;
				if(p.x >=0 && p.x<w && p.y >=0 && p.y < h && map[p.y][p.x] =='.' && !used[p.y][p.x])
				{
					used[p.y][p.x] = true;
					que.push(p);
					t++;
				}
			}
		}
		cout<<t<<endl;
	}
	return 0;
}