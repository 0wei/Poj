#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
   
#define MAXN 30
int a[MAXN][MAXN], b[MAXN];
   
int Gauss ( int n, int a[][MAXN], int b[] )
{
    int i, j, k, row;
    for ( k = 0; k < n; k++ )
    {
        for ( i = k; i < n; i++ )
            if ( a[i][k] == 1 ) { row = i; break; }
        if ( i == n ) return 0; //由于控制矩阵可逆，所以x[]是有唯一解的，此处也可省略
   
        if ( row != k )
        {
            for ( j = k; j < n; j++ )
                swap ( a[k][j], a[row][j] );
            swap ( b[k], b[row] );
        }
   
        for ( i = k + 1; i < n; i++ )
        {
            if ( a[i][k] == 0 ) continue; //按行处理
            for ( j = k + 1; j < n; j++ )
                a[i][j] ^= a[k][j];
            b[i] ^= b[k];
        }
    }
   
    b[n-1] = b[n-1] / a[n-1][n-1];
    for ( i = n - 2; i >= 0; i-- )
    {
        for ( j = i + 1; j < n; j++ )
            b[i] ^= ( a[i][j] * b[j] );
        b[i] = b[i] / a[i][i];
    }
    return 1;
}
   
   
void init ()
{
    int i, j;
    int t1, t2, t3, t4;
    for ( i = 0; i < 30; i++ )
    {
        t1 = i / 6;
        t2 = i % 6;
        for ( j = 0; j < 30; j++ )
        {
            t3 = j / 6;
            t4 = j % 6;
            if ( abs(t1-t3) + abs(t2-t4) <= 1 )
                a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
      
}
   
int main()
{
    int t, k, i;
    scanf("%d",&t);
    for ( k = 1; k <= t; k++ )
    {
        for ( i = 0; i < 30; i++ )
            scanf("%d",&b[i]);
   
        init();
        Gauss ( 30, a, b );
        printf("PUZZLE #%d\n",k);
        for ( i = 1; i <= 30; i++ )
        {
            printf("%d ", b[i-1]);
            if ( i % 6 == 0 ) printf("\n");
        }
    }
    return 0;
}