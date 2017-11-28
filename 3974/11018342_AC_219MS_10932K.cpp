//十七、	Manacher算法一个字符串里面最长回文数长度
#include<stdio.h>
#include<string.h>

#define M 1000008

char o[M],s[M<<1];
int p[M<<1];
int r;

int MMin(int a,int b)
{
	return a>b?b:a;
}

void Manacher()
{
	int i,j,max;
	int n=strlen(o);
	memset(s,'#',sizeof(s));

	
	for(i=0;i<n;i++)
		s[(i+1)<<1]=o[i];
	s[n=(n+1)<<1] =0;
	r=max=0;
	for(i=0;i<n;i++)
	{
		if(max>i)
		{
			p[i]=MMin(p[2*j-i],max-i);	  //基于对称的原则:由于以j中点向两边扩展max, 所以p[i] = p[2*j-i], 
											//需要考虑: p[2*j - i] > max-i 时, p[i] = max - i, 因为只有部分能够确定已经匹配
		}
		else
		{
			p[i]=1;
		}

		while(s[i-p[i]]==s[i+p[i]]) 
		{
			p[i]++;
		}

		if(p[i]>r)
		{
			r=p[i];
		}
		
		if(i+p[i]>max)
		{
			max=i+p[i];     
			j=i;
		}
	}
}
int main()
{
	int t=0;

	while(~scanf("%s",o),o[0]^'E')
	{
		Manacher();
		printf("Case %d: %d\n",++t,r-1);
		
	}

	return 0;
}
