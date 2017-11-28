#include <iostream>
using namespace std;

int main()
{
	int n;
	int i;
	while(scanf("%d",&n) && n != -1)
	{
		double c1=1;
		double c2;
		for(i=1; i <n; i++)
		{
			if ((4 * i + 2) % (i +2) == 0)
				c2 = (4 * i + 2) / (i +2) * c1	;
			else 
				c2 = (4 * i + 2) * c1 /	(i +2) ;
			c1 = c2;
		}
		printf("%0.0f\n", c2);

	}
	return 0;
}