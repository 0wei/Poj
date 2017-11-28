#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	double n, p;
	while (scanf("%lf %lf", &n, &p) !=EOF)
	{
		printf("%0.0lf\n", pow(p, 1/n));
	}
	return 0;
}