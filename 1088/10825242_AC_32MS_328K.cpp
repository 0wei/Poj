#include <iostream>
#include <queue>
using namespace std;
struct point 
{
	int x,y;
};

int n, m;
int b[101][101];
int c[101][101];


int dp(int i,int j)
{
	int sum=0;
	int l;
	if(c[i][j]!=0)
		return c[i][j];
	if(i-1>=0&&b[i-1][j]<b[i][j])
	{
		sum=dp(i-1,j);
	}
	if(i+1<n&&b[i+1][j]<b[i][j])
	{
		l=dp(i+1,j);
		if(sum<l)
			sum=l;
	}
	if(j-1>=0&&b[i][j-1]<b[i][j])
	{
		l=dp(i,j-1);
		if(sum<l)
			sum=l;
	}
	if(j+1<m&&b[i][j+1]<b[i][j])
	{
		l=dp(i,j+1);
		if(sum<l)
			sum=l;
	}
	return c[i][j]=sum+1;
}


int main()
{
	int k, l;
	while(cin>>n>>m)
	{
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		int maxx = 0;
		int i, j;
		for (i=0; i<n; i++)
			for (j=0; j<m; j++)
				cin>>b[i][j];					
	for(k=0; k<n; k++)
		for(l=0; l<m; l++)
		{
			int tmp = dp(k,l);
			if(tmp > maxx) maxx = tmp;
		}
			
		/* Output */
		cout<<maxx<<endl;
	}
			return 0;
}