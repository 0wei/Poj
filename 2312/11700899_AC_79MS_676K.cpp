#include <iostream>
#include <queue>
using namespace std;

struct postion
{
	int i, j;
	postion operator+(postion p)
	{
		postion t;
		t.i = this->i+ p.i;
		t.j = this->j+ p.j;
		return t;
	}
};

postion dir[] = {1,0, -1,0, 0,1, 0,-1};

int step[305][305];
//bool used[305][305];
queue<postion>que;
char map[305][305];
postion start, target;
int M, N;

int main()
{
	int  i, j;
	while (cin>>M>>N && M+N)
	{
		for (i=0; i<M; i++)
			for (j=0; j<N; j++)
			{
				cin>>map[i][j];
				step[i][j] = INT_MAX;
				if (map[i][j] == 'Y')
					start.i = i, start.j = j;
				else if (map[i][j] == 'T')
					target.i = i, target.j = j;
			}
			//memset(used, false, sizeof(used));
			//memset(step, 0, sizeof(step));
			//used[start.i][start.j] = true;
			step[start.i][start.j] = 0;
			while (!que.empty())que.pop();
			que.push(start);
			postion tmp, t;
			int sp;
			while (!que.empty())
			{
				tmp = que.front();
				que.pop();
				for (i=0; i<4; i++)
				{
					t = tmp + dir[i];
					if (t.i<0 || t.i>=M || t.j<0 || t.j>=N || map[t.i][t.j] == 'R' || map[t.i][t.j] == 'S')
						continue;
					if (map[t.i][t.j] == 'E')
						sp = 1;
					if (map[t.i][t.j] == 'B')
						sp = 2;
					if (step[t.i][t.j] > step[tmp.i][tmp.j] + sp)
					{
						step[t.i][t.j] = step[tmp.i][tmp.j] + sp;
						que.push(t);
					}
				}
			}
			if (step[target.i][target.j] == INT_MAX)
				step[target.i][target.j] = -1;
			cout<<step[target.i][target.j]<<endl;
	}
	return 0;
}