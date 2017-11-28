/*
	poj2251
	三维立体迷宫
*/

#include <iostream>
#include <queue>
using namespace std;

const int N = 40;

struct Node
{
    int level, row, colunm;
};

Node dir[]={0,0,1, 0,1,0, 1,0,0, 0,0,-1, 0,-1,0, -1,0,0};   //方向

char map[N][N][N];  //地图
int step[N][N][N];  //步数
bool used[N][N][N]; //是否走过
queue<Node> que;    //

Node _start, _end;
int l, r, c;

bool operator == (Node a, Node b)
{
    if (a.level == b.level && a.row == b.row && a.colunm == b.colunm)
        return true;
    return false;
}

void input()
{
    int i, j, k;
    for (i=0; i<l; i++)
        for (j=0; j<r; j++)
            for (k=0; k<c; k++)
            {
                cin>>map[i][j][k];
                if (map[i][j][k] == 'S')
                {
                    _start.level = i;
                    _start.row = j;
                    _start.colunm= k;
                }
                else if (map[i][j][k] == 'E')
                {
                    _end.level = i;
                    _end.row = j;
                    _end.colunm= k;
                }
            }
}

int main()
{
  
    //Node a, b;
    //a.level = 1;
    //a.row = 2;
    //a.colunm = 3;
    //b.level = 1;
    //b.row = 2;
    //b.colunm = 3;
    //if (a == b) cout<<"ok"<<endl;
    //else cout<<"NO"<<endl;
    //int aa=1, bb = 2;

    while (cin>>l>>r>>c && (l+r+c))
    {
        input();	
        memset(used, false, sizeof(used));
        while (!que.empty()) que.pop();
        que.push(_start);
        used[_start.level][_start.row][_start.colunm] = true;
        step[_start.level][_start.row][_start.colunm] = 0;
        bool trapped = false;
        while (!que.empty())
        {
            Node node = que.front();
            que.pop();
            if (node == _end)
            {
                cout<<"Escaped in ";
                cout<<step[_end.level][_end.row][_end.colunm];
                cout<<" minute(s)."<<endl;
                trapped = true;
                break;
            }
            Node tmp;
            for (int i=0; i<6; i++)
            {
                tmp = node;
                tmp.level += dir[i].level;
                tmp.row += dir[i].row;
                tmp.colunm += dir[i].colunm;
                if (tmp.level < 0 || tmp.level >= l || tmp.row < 0 || tmp.row >= r || tmp.colunm < 0 || tmp.colunm >= c)
                    continue;
                if (map[tmp.level][tmp.row][tmp.colunm] != '#' && !used[tmp.level][tmp.row][tmp.colunm])
                {
                    que.push(tmp);
                    used[tmp.level][tmp.row][tmp.colunm] = true;
                    step[tmp.level][tmp.row][tmp.colunm] = step[node.level][node.row][node.colunm] + 1;
                }
            }
        }
        if (!trapped)
            cout<<"Trapped!"<<endl;
    }
    return 0;
}
