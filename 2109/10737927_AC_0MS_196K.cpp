#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	double n,m;
	while(scanf("%lf%lf",&n,&m)==2)
		printf("%0.0lf\n",pow(m,1/n));
	return 0;
}