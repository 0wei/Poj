#include<iostream>
using namespace std;
int main()
{
	char c[100][100];
	int i,j,x,y,p,a[100][100],n;
	while(cin>>x>>y>>p&&x+y+p)
	{
		for(i = 0; i < x; i++)
			for(j = 0; j < y; j++)
			{
				cin>>c[i][j];
				a[i][j] = 0;
			}
		i = 0, j = p-1,n = 0;
		while(i>=0&&i<x&&j>=0&&j<y)
		{
			if(c[i][j] == 'S')
			{
				a[i][j] = ++n;
				c[i++][j] = '0';
			}else if(c[i][j] == 'N')
			{
				a[i][j] = ++n;
				c[i--][j] = '0';
			}else if(c[i][j] == 'W')
			{
				a[i][j] = ++n;
				c[i][j--] = '0';
			}else if(c[i][j] == 'E')
			{
				a[i][j] = ++n;
				c[i][j++] = '0';
			}else
			{
				cout<<a[i][j]-1<<" step(s) before a loop of "<<n-a[i][j]+1<<" step(s)"<<endl;
				goto L;
			}
		}
		cout<<n<<" step(s) to exit"<<endl;
	L : 
		continue;

	}
	return 0;
}