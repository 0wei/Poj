#include<iostream>
using namespace std;
int prime[1000001];
int main()
{
	int n,j ;
	for(int i = 2; i< 1000001; i++)
	{	if(prime[i]) continue;
		j = i+i; 
		while(j < 1000001)
		{
			prime[j] = 1;
			j+=i;
		}
	}
	while(cin>>n&&n)
	{
		for(int i = 3; i < n/2; i++)
			if(prime[i]==0&&prime[n-i]==0)
			{
				printf("%d = %d + %d\n",n,i,n-i);
				break;
			}
	}
	return 0;
}