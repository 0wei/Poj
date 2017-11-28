#include <stdio.h>
const int N = 30005;
int n, f[N];
int ans;
void Init(void){
    for(int i=0; i<n;i++)
		f[i]=i;
}
int Find(int n){
    if(f[n]!=n) 
		return f[n]=Find(f[n]);
    else return f[n];
}
void Union(int x,int y){
    int f_x=Find(x);
    int f_y=Find(y);
    f[f_x]=f_y;
}

void Count()
{
	int x = Find(0), c = 1;
	for (int i=1; i<n;i++)
	{
		if (Find(i) == x)
			c++;
	}
	printf("%d\n", c);
}

int main()
{
	int  m, k, i, j, wh, tmp;
	while (scanf("%d%d", &n, &m)!=EOF &&n+m)
	{
		Init();
		for (i=0; i<m; i++)
		{
			scanf("%d%d", &k, &tmp);
			for (j=1; j<k; j++)
			{
				scanf("%d", &wh);
				Union(tmp, wh);
			}
		}
		Count();

	}
	return 0;
}