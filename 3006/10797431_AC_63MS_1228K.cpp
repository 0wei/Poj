
#include<iostream>
using namespace std;

void MakePrime(bool *p, int n)
{
	int i, tmp;
	for(i=2; i<n; i++)
	{
		if(p[i])
		{
			tmp = i;
			while(tmp < n)
			{
				p[tmp] = false;
				tmp+=i;
			}
			p[i] = true;
		}
	}
}

int main()
{
	bool prime[1000000];
	memset(prime, true, sizeof(prime));
	prime[1] = false;
	MakePrime(prime,1000000);
	int a, d, n;
	int i, t; 
	while(cin>>a>>d>>n && a + d + n != 0)
	{
		
		i = 0;
		t = a - d;
		while(i != n)
		{
			t += d;
			if(prime[t])
			{
				i++;
			}
		}
		cout<<t<<endl;
	}
}