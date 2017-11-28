#include <iostream>
using namespace std;
__int64 extgcd(__int64 a, __int64 b, __int64 &x, __int64 &y)
{
    __int64 d, t;
    if (b == 0) 
	{
		x = 1;
		y = 0; 
		return a; 
	}
    d = extgcd(b, a % b, x, y);
    t = x - a / b * y;
	x = y;
	y = t;
    return d;
}
int main()
{
    __int64 x, y, m, n, L, X, Y, d, r;
    while (scanf("%I64d %I64d %I64d %I64d %I64d", &x ,&y ,&m ,&n ,&L)!=EOF)
    {
        d = extgcd(n - m, L, X, Y); r = L / d;
        if ((x - y) % d) 
			printf("Impossible\n");
        else 
		{
			printf("%I64d\n", ((x - y) / d * X % r + r) % r);
			
			
			/*X *= 1.0 * (x - y) / d;
			__int64 t =	1.0 * L / d;
			X = (X % t + t) % t;
			printf("%I64d\n", X);*/

		
		}
    }
    return 0;
}