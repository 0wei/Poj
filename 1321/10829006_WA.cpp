#include <iostream>
using namespace std;

char map[10][10];
bool used[10][10];   //下标表示行，值表示列

int n,k;
int sum;

bool ok(int k, int l)
{
	for(int i=0; i<n; i++)
		if(used[k][i] || used[i][l])
			return false;
	
	return true;

}

void dfs(int s)
{
	if(s == k)
	{
		sum++;
		return;
	}
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(map[i][j] == '#' && ok(i,j))
			{
				used[i][j] = true;
				dfs(s+1);
			//	used[i][j] = false;
			}


}

int main()
{
	
	while(cin>>n>>k && (n !=-1 || k != -1))
	{
		for(int i=0; i<n; i++)
				cin>>map[i];
		memset(used, false, sizeof(used));
		sum = 0;
		dfs(0);
		cout<<sum<<endl;
	}
	return 0;
}