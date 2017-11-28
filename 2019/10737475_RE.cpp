#include<iostream>
using namespace std;
int main()
{
	int a[300][300];
	int n,b,k,x,y,i,j;
	int mmin,mmax;
	while(scanf("%d%d%d",&n,&b,&k))
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		while(k--)
		{
			scanf("%d%d",&x,&y);
			x--;y--;
			mmin=mmax=a[x][y];
			for(i=x;i<x+b;i++)
				for(j=y;j<y+b;j++)
				{
					if(a[i][j]<mmin) mmin=a[i][j];
					if(a[i][j]>mmax)mmax=a[i][j];

				}
			printf("%d\n",mmax-mmin);
		}


	}
	return 0;
}