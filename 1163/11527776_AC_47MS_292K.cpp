#include <iostream>
using namespace std;

const int N = 105;
int triangle[N][N];


int Maxx(int a, int b)
{
	return a < b ? b : a;
}

int main()
{
	int n, i, j, k;
	cin>>n;
	for ( i=0; i<n; i++)
		for ( j=0; j<=i; j++)
			cin>>triangle[i][j];
	for (k=n-2; k>=0; k--)
		for (i=0; i<=k; i++)
			triangle[k][i] += Maxx(triangle[k+1][i], triangle[k+1][i+1]);
	cout<<triangle[0][0]<<endl;

	return 0;
}