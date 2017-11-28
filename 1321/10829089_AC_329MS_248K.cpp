#include <iostream>
using namespace std;

char map[10][10];
bool used[10][10];   //下标表示行，值表示列

int n,m;
int sum;

bool ok(int k, int l)
{
	for(int i=0; i<n; i++)
		if(used[k][i] || used[i][l])
			return false;
	
	return true;

}

void dfs(int k,int l,int s)
{
	if(s == m)
	{
		sum++;
		return;
	}
	for(int i=k; i<n; i++)
		for(int j=0; j<n; j++)
			if(map[i][j] == '#' && ok(i,j))
			{
				used[i][j] = true;
				dfs(i, j, s+1);
				used[i][j] = false;
			}


}

int main()
{
	
	while(cin>>n>>m && (n !=-1 || m != -1))
	{
		for(int i=0; i<n; i++)
				cin>>map[i];
		memset(used, false, sizeof(used));
		sum = 0;
		dfs(0,0,0);
		cout<<sum<<endl;
	}
	return 0;
}