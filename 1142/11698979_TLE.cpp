#include <iostream>
using namespace std;
int tsum, sum;

int GetSum(int n)
{
	int s=0;
	while (n)
	{
		s += n%10;
		n /= 10;
	}
	return s;
}

// (a * b) % c;
int Mult_Mod(int a, int b, int c)
{
	a %= c;
	b %= c;
	int ret = 0;
	while (b)
	{
		if (b & 1)
		{
			ret += a;
			ret %=c;
		}
		a <<= 1;
		if (a >= c)
			a %= c;
		b >>= 1;
	}
	return ret;
}

// a^x % n
int Pow_Mod(int x, int n, int c)
{
	if (n == 1)
		return  x % c;
	x %= c;
	int tmp = x;
	int ret = 1;
	while(n)
	{
		if (n & 1)
			ret = Mult_Mod(ret, tmp, c);
		tmp = Mult_Mod(tmp, tmp, c);
		n>>= 1;
	}
	return ret;
}

bool Check(int a, int n, int x, int t)
{
	int ret = Pow_Mod(a, x, n);
	int last = ret;
	int i;
	for (i=1; i<=t; i++)
	{
		ret = Mult_Mod(ret, ret, n);
		if (ret == 1 && last != 1 && last != n-1)
			return true;
		last = ret;
	}
	if (ret != 1)
		return true;
	return false;
}

bool Miller_Rabin(int n)
{
	if (n < 2) return false;
	if (n == 2) return true;
	if ((n & 1) == 0) return false;
	int x = n-1;
	int t = 0;
	int i;
	while ((x & 1) == 0)
	{
		x >>= 1;
		t++;
	}
	for (i=0; i<20; i++)
	{
		int a = rand()%(n-1)+1;
		if (Check(a, n, x, t))
			return false;
	}
	return true;
}

int Gcd(int a, int b)
{
	int t;
	if (a < 0)
		a *= -1;
	if (a == 0)
		return 1;
	while (b)
	{
		t = a % b;
		a = b; 
		b = t;
	}
	return a;
}

int Pollard_rho(int x, int c)
{
	int i=1, k = 2;
	int x0 = rand()%x;
	int y = x0;
	int d;
	while (1)
	{
		i++;
		x0 = (Mult_Mod(x0, x0, x)+c)%x;
		d = Gcd(y-x0, x);
		if (d != 1 && d != x)
			return d;
		if (y == x0)
			return x;
		if (i == k)
		{
			y = x0;
			k += k;
		}
	}
}

void FindFactor(int n)
{
	if (Miller_Rabin(n))
	{
		tsum += GetSum(n);
		return;
	}
	int p = n;
	while (p >= n)
		p = Pollard_rho(p, rand()%(n-1)+1);
	FindFactor(p);
	FindFactor(n/p);
}

int main()
{
	int n, i;
	while (cin>>n && n)
	{
	
		for (i=n+1; ; i++)
		{	
			tsum = 0, sum = 0;
			if (!Miller_Rabin(i))
			{
				sum = GetSum(i);
				FindFactor(i);
				if (sum == tsum)
					break;
			}
		}
		cout<<i<<endl;
	}
	return 0;
}