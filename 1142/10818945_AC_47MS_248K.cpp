#include <iostream>
#include <math.h>
using namespace std;

bool prim(int x)
{
	int i;
	for(i=2; i<sqrt(x+1.0); i++)
	{
		if(x % i ==0)
			return false;
	}
	return true;
}

int Getsum(int i)
{
	int sum = 0;
	while(i != 0)
	{
		sum += i % 10;
		i /=10;
	}
	return sum;
}

bool smith(int n)
{
	if(prim(n)) return false;
	int tmp = n;
	int i = 2;
	int sum_s = 0;
	int sum_n = Getsum(n);

	while(i < sqrt(n + 1.0))
	{
		if(n % i == 0 && prim(i))
		{
			sum_s +=Getsum(i);
			n /= i;
		}
		else i++;
	}
	sum_s += Getsum(n);
	return sum_n == sum_s ? true : false;
	
}

int main()
{

	int n;

	while(cin>>n && n != 0)
	{
		while(!smith(++n));
		cout<<n<<endl;
	}
	return 0;
}