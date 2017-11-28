#include<iostream>
using namespace std;
void operat(int s[1000],int n,int r[1000])
{
	int i,t,j;
	for(i = 0; i < 1000; i++)
		r[i] =0;
	for(i = 1000-1; i >=0; i--)
	{	if(s[i]!=0)break;	}
	i++;
	if(n < 10)
	{
		for(t = 0; t < i ;t++)
			r[t] = s[t]*n;
		j = 0;

	}
	else if(n/10 < 10)
	{
		for(t = 0; t < i; t++)
			r[t] =  n%10 * s[t];
		for(t = 0; t <i ;t++)
			r[t+1] += n/10 * s[t]  ;
		j = 1;
	}
	else
	{
		for(t = 0; t < i; t++)
			r[t] = n%10 *s[t]  ;
		for(t = 0; t <i ;t++)
			r[t+1] += n/10%10 * s[t]  ;
		for(t = 0; t <i ;t++)
			r[t+2] += n/100 * s[t] ;
		j = 2;
	}
	for(t = 0; t <= i+j; t++)
	{
		r[t+1] += r[t]/10;
		s[t] = r[t]%10;
	}
}
int main()
{
	int n,i;
	int s[1000] ,r[1000], a[10];
	while(cin>>n&&n)
	{
		for(i = 0 ; i < 1000; i++)
			s[i] = a[i] = 0;
		s[0] = 1;
		for(i = 1; i <=n ;i++)
		{	
			operat(s,i,r);
		}
		for(i = 1000-1; i >=0; i--)
			if(s[i]!=0)
				break;
		i++;
		while(i--)
		{	a[s[i]]++;}
		cout<<n<<"! --";
		for(i = 0; i < 10; i++)
		{
			if(i==0||i ==5)
			{	cout<<endl;}
			printf("    (%d)%5d",i,a[i]);
		}
		cout<<endl;
	}
	return 0;
}