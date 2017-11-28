#include<iostream>
#include <math.h>
using namespace std;
int main()
{
	int n, v, t;
	double time, min;
	while(cin>>n&&n)
	{
		min = 4.5 * 3600;
		while(n--)
		{
			cin>>v>>t;
			if (t < 0) continue;
			time = 4.5 / v * 3600 + t;
			if (time <= min)
				min = time;
		}
		t = ceil(min);	
		printf("%d\n", t);
	}
	return 0;
}