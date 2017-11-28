#include <stdio.h>
#include <string.h>
const int N = 50005;
int n;
int f[N];
void Init(void)
{
    for(int i=1; i<=n;i++)
		f[i]=i;
}
int Find(int n)
{
    if(f[n]!=n) 
		return f[n]=Find(f[n]);
    else 
		return f[n];
}
bool Union(int x,int y)
{
    int f_x=Find(x);
    int f_y=Find(y);
    f[f_x]=f_y;
	if (f_x != f_y)
		return true;
	return false;
}



int main()
{
	int k;
	int a, b, i;
	int cnt, t=1;
	while (scanf("%d%d", &n, &k)!=EOF && n+k)
	{
		Init();
		cnt = 0;
		for (i=0; i<k; i++)
		{
			scanf("%d%d", &a, &b);
			if (Union(a, b))	
				cnt++;
		}
		printf("Case %d: %d\n", t, n-cnt);
	}
	return 0;
}