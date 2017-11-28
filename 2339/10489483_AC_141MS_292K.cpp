#include<iostream>
#include<string>
using namespace std;
int main()
{
	char now[200][200],last[200][200];
	char a[200];
	a[162] = 'P',a[165]='R',a[163]='S';
	a[160] = 'P',a[164]='R',a[166]='S';
	int r,c;
	int t,n,i,j;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>r>>c>>n;
			for(i = 1; i <= r; i++)
				for(j = 1;j<=c;j++)
					cin>>now[i][j];

			while(n--)
			{
				for(i = 1; i <=r; i++)
				{
					now[i][0] = now[i][1];
					now[i][c+1] = now[i][c];
				}
				for(i = 1; i<=c; i++)
				{
					now[0][i] = now[1][i];
					now[r+1][i] = now[r][i];
				}
				for(i =1; i<= r; i++)	   //内圈
					for(j = 1; j <=c; j++) /*((左            比            右)				比			(下     比                  上))*/
						last[i][j] = a[a[a[now[i][j]+now[i][j-1]]   +a[now[i][j] + now[i][j+1]]]  + a[a[now[i][j]+now[i+1][j]]+a[now[i][j]+now[i-1][j]]]];                       
				for(i = 1; i <= r; i++)
					for(j = 1; j<= c; j++)
						now[i][j]=last[i][j];						
			}
			for(i = 1; i <= r; i++)
			{
				for(j = 1; j<= c; j++)
					cout<<now[i][j];
				cout<<endl;
			}
			cout<<endl;
		}
	}
	return 0;
}