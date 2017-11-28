#include<iostream>  
#include<cmath>  
using namespace std;  
int main()  
{  
	double d = sqrt(5.0);  
	int m,n,t;  
	while(scanf("%d%d", &m, &n) != EOF)  
	{  
		if(m > n)  
		{  
			t = m;  
			m = n;  
			n = t;  
		}  
		t = n - m;  
		if(m == (int)(t*(1 + d) / 2))  
			printf("0\n");  
		else  
			printf("1\n");  
	}  
	return 0;  
}