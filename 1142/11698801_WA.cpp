#include <iostream>

using namespace std;

int GetSum(int n)
{
	int s=0;
	while (n)
	{
		s += n %10;
		n /= 10;
	}
	return s;
}

bool Smith(int n)
{
	int sum = GetSum(n);
	int i=2;
	int tsum=0;
	while (i*i < n)
	{
		if (n % i == 0)
		{
			tsum += GetSum(i);
			n /= i;
			i = 2;
		}
		else
			i++;
		if (tsum > sum)
			return false;
	}
	if ((tsum + GetSum(n)) == sum)
		return true;
	return false;
}

int main()
{
	int n;
	int i;
	while (cin>>n && n)
	{
		for (i=n+1; ; i++)
		{
			if (Smith(i))
				break;
		}
		cout<<i<<endl;
	}
	return 0;
}