//代码

// BFS
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

/* 把1..n的排列映射为数字 0..(n!-1) */
int fac[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };//...
int order(const char *s, int n) {
    int i, j, temp, num;

    num = 0;

    for (i = 0; i < n-1; i++) {
        temp = 0;
        for (j = i + 1; j < n; j++) {
            if (s[j] < s[i])
                temp++;
        }
        num += fac[s[i] -1] * temp;
    }
    return num;
}

bool is_equal(const char *b1, const char *b2){
    for(int i=0; i<9; i++)
        if(b1[i] != b2[i])
            return false;
    return true;
}


//_hash
struct node{
    char board[9];
    char space;//空格所在位置
};

const int TABLE_SIZE = 362880;

int _hash(const char *cur){
    return order(cur, 9);
}

/* 整数映射成排列 */
void get_node(int num, node &tmp) {
    int n=9;
    int a[9]; //求逆序数
    for (int i = 2; i <= n; ++i) {
        a[i - 1] = num % i;
        num = num / i;
        tmp.board[i - 1] = 0;//初始化
    }
    tmp.board[0] = 0;
    int rn, i;
    for (int k = n; k >= 2; k--) {
        rn = 0;
        for (i = n - 1; i >= 0; --i) {
            if (tmp.board[i] != 0)
                continue;
            if (rn == a[k - 1])
                break;
            ++rn;
        }
        tmp.board[i] = k;
    }
    for (i = 0; i < n; ++i)
        if (tmp.board[i] == 0) {
            tmp.board[i] = 1;
            break;
        }
    tmp.space = n - a[n-1] -1;
}

char visited[TABLE_SIZE];
int parent[TABLE_SIZE];
char _move[TABLE_SIZE];
int step[4][2] = {{-1, 0},{1, 0}, {0, -1}, {0, 1}};//u, d, l, r

void BFS(const node & start){
    int x, y, k, a, b;
    int u, v;

    for(k=0; k<TABLE_SIZE; ++k)
        visited[k] = 0;
    u = _hash(start.board);
    parent[u] = -1;
    visited[u] = 1;

    queue<int> que;
    que.push(u);

    node tmp, cur;
    while(!que.empty()){
        u = que.front();
        que.pop();

        get_node(u, cur);

        k = cur.space;
        x = k / 3;
        y = k % 3;
        for(int i=0; i<4; ++i){
            a = x + step[i][0];
            b = y + step[i][1];
            if(0<=a && a<=2 && 0<=b && b<=2){
                tmp = cur;
                tmp.space = a*3 + b;
                swap(tmp.board[k], tmp.board[tmp.space]);
                v = _hash(tmp.board);
                if(visited[v] != 1){
                    _move[v] = i;
                    visited[v] = 1;
                    parent[v] = u;
                    if(v == 0) //目标结点_hash值为0
                        return;

                    que.push(v);
                }
            }
        }
    }
}

void print_path(){
    int n, u;
    char path[1000];
    n = 1;
    path[0] = _move[0];
    u = parent[0];
    while(parent[u] != -1){
        path[n] = _move[u];
        ++n;
        u = parent[u];
    }
    for(int i=n-1; i>=0; --i){
        if(path[i] == 0)
            printf("u");
        else if(path[i] == 1)
            printf("d");
        else if(path[i] == 2)
            printf("l");
        else
            printf("r");
    }
}

int main(){
   // freopen("in", "r", stdin);

    node start;
    char c;
    for(int i=0; i<9; ++i){
        cin>>c;
        if(c == 'x'){
            start.board[i] = 9;
            start.space = i;
        }
        else
            start.board[i] = c - '0';
    }
    BFS(start);

    if(visited[0] == 1)
        print_path();
    else
        printf("unsolvable");
    return 0;
}