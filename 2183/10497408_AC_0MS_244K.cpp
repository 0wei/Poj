#include<iostream>
using namespace std;
const int MAX = 999999;
int data[MAX],position[MAX];
int main()
{
	int n,t,i,flags; 
	while(cin>>n)
	{
		i = 0,flags = 1;
		while(flags)
		{
			for(int j = 1; j < i ; j++)
				if(n==data[j])
				{
					printf("%d %d %d\n",n,i-j,i);
					flags = 0;
				}
			data[i++] = n;
			int m = data[i-1];
			t = n%100000;
			t/=10;
			n = t*t;
			m = t*t;
			n%=1000000;
		}
	}
	return 0;
}