#include<iostream>
using namespace std;
void strev(char c[99999])
{
	int len = strlen(c),l;
	(len/2)*2==len?l = len/2:l = len/2+1;
	for(int i = 0; i <len/2; i++)
		swap(c[i],c[l+i]);
}
int ati(char c[99999])
{
	int x=0,len = strlen(c);
	for(int i =0 ;i <len; i++)
	{
		x*=10; 
		x+=c[i]-'0';
	}
	return x;
}
void ita(int x,char c[99999])
{
	int i =0;
	while(x)
	{
		c[i++] = x%10 +'0';
		x/=10;
	}
	c[i] = '\0';
	strev(c);
}
int main()
{
	char cx[99999] ,cy[99999];
	int n,x=0,y=1 ;
	while(cin>>n)
	{
		while(n--)
		{
			cin>>cx>>cy;
			x = ati(cx);
			y = ati(cy);
			ita(x,cx);
			ita(y,cy);
			strev(cx);
			strev(cy);
			x = ati(cx);
			y = ati(cy);
			x+=y;
			ita(x,cx);
			strev(cx);
			x = ati(cx);
			cout<<x<<endl;
		}
	}
	return 0;
}