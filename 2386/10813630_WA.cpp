#include <iostream>
#include <queue>
using namespace std;

struct point
{
	int x, y;
};

point dic[8] = {{1, 0}, {1,1}, {0,1}, {-1,1}, {-1,0}, {-1,-1}, {-1,0}, {1,-1}};

int main()
{
	int time = 0;
	char map[110][110];
	int n, m;
	int i, j;
	cin>>n>>m;
	for (i=0; i<n; i++)
	{
		cin>>map[i];		
	}

	/* BFS */
	queue<point> que;
	point pt;
	bool flags = true;
	
	while(flags)
	{
		
		if(que.empty())
		{
			flags = false;
			for (i=0; i<n; i++)
				for (j=0; j<m; j++)
				{
					if(map[i][j] == 'W')
					{
						flags = true;
						time++;
						pt.x = i;
						pt.y = j;
						que.push(pt);
						map[i][j] = '.';
						goto L;
						
					}
				}
		}
L:
		while(!que.empty())
		{
			point tmp;
			pt = que.front();
			tmp = pt;
			que.pop();
			
			for(i=0; i<8; i++)
			{
				pt = tmp;
				pt.x += dic[i].x;
				pt.y += dic[i].y;
				if(pt.x >=0 && pt.x < n && pt.y >=0 && pt.y < m && map[pt.x][pt.y] == 'W')
				{
					que.push(pt);
					map[pt.x][pt.y] = '.';
				}
			}
		}
	}

	cout<<time<<endl;
	return 0;
}