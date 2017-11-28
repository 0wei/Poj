#include <iostream>
using namespace std;

int main()
{
	int t, n; 	
	int i, j;
	int ar[32];
	ar[0] = 1; 
	for (i=1; i<31; i++)
	{
		ar[i] = ar[i-1]*2;
	}

	cin>>t;
	while (t--)
	{		
		cin>>n;
		j=0;
		for (i=1; i<31; i++)
		{
			if (n % ar[i] == 0)   //某一个数都能够被同层的第一个数或者更下层的第一个数整除，若碰到不能整除了则说明该数是在i-1这一层
			{
				j++;	
			}
			else break;
		}
		cout<<n - ar[j]+1<<" "<<n + ar[j]-1<<endl;
	}

	return 0;
}