#include<iostream>
using namespace std;
int judge(int b)
{
	for(int i = 2; i < b/2; i++)
		if(b%i==0)
			return false;
	return true;
}
int main()
{
	int n ;
	while(cin>>n&&n)
	{
		for(int i = 3; i < n/2; i++)
			if(judge(n-i))
			{
				printf("%d = %d + %d\n",n,i,n-i);
				break;
			}
	}
	return 0;
}