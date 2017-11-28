#include<stdio.h>
#include<string.h>
#define ML 100001

int f[ML];
int l;

int main()
{
    int n;
    while(scanf("%d",&n)!=-1)
    {
        l=0;
        f[0]=-1000000;
        int max=f[0];
        int s;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&s);
            if(s>max)
            {
				f[++l]=s;
				max=s;
				continue;
			}
			f[l]=s;
			max=f[l];
	
		
        }
        printf("%d\n",l);
    }
}

