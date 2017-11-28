#include <stdio.h>

long long big_mod(long long a,long long p,long long m)  //a^p%m
{
    if (a==0 || m==1)
        return 0;
    if (p==0)
        return 1;
    if (p%2)
        return ((a%m)*big_mod(a,p-1,m))%m;
    long long tmp=big_mod(a,p/2,m);
    return (tmp*tmp)%m;

}

int main()
{
	int z;
	int a, p, m;;
	int h;
	int i;
	scanf("%d",&z);
	while (z--)
	{
		scanf("%d%d", &m,&h);
		long long sum=0;
		for (i=0; i<h; i++)
		{
			scanf("%d%d",&a, &p);
			sum += big_mod(a, p, m);
		}
		sum %= m;
		printf("%lld\n", sum);
		
	}
	return 0;
}