#include <iostream>
#include <queue>
using namespace std;

struct point
{
	int x,y;
};

int r, c;
int map[101][101];
point dir[4] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
queue<point> que;
int step[101][101];
bool visted[101][101];


void BFS(int x, int y)
{
	int i;
	point pt;
	pt.x = x;
	pt.y = y;
	que.push(pt);
	visted[x][y] = true;
	step[x][y] = 1;
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
}

int main()
{

	int k,l;
	while(cin>>r>>c)
	{
		int maxx = 0;
		int i, j;
		for (i=0; i<r; i++)
			for (j=0; j<c; j++)
				cin>>map[i][j];					

		/* BFS */
		for (i=0; i<r; i++)
			for (j=0; j<c; j++)
			{
				memset(visted, false, sizeof(visted));
				memset(step, 0, sizeof(step));
				while(!que.empty()) que.pop();
				BFS(i,j);
		
				for(k=0; k<r; k++)
					for (l=0; l<c; l++)
					{
						if(maxx < step[k][l])
							maxx = step[k][l];
					}						
			}
			
		/* Output */
		cout<<maxx<<endl;
	}
			return 0;
}