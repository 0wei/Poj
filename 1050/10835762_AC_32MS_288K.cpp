#include <iostream>
using namespace std;

int num[102];
int n;
int maxx;

void GetMax()    //得到最大的子区间
{
	
	int t = num[1];       
	for(int i=2; i<=n; i++)
	{
		t = t < 0 ? num[i] : (t + num[i]);
		maxx = maxx < t ? t : maxx;
	}
}
int main()
{
	int map[102][102];
	int i, j, k;
	while(cin>>n)
	{
		maxx = -50000;
		for (i=1; i<=n; i++)
			for (j=1; j<=n; j++)
				cin>>map[i][j];
		
		for(i=1; i<=n; i++)  //从第几行开始
		{
			memset(num, 0, sizeof(num));
			for(j=i; j<=n; j++)  //从第几行结束
			{
			
				for(k=1; k<=n; k++)      //每一列的和数
				{
					num[k] += map[j][k];
				}
				GetMax();
			}
		}

		cout<<maxx<<endl;
	}
	return 0;
}