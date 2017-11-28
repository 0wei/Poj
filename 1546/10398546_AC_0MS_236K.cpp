#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
const int Max = 100;
int kk;
int judge(int a[Max],int ti)       
{
	for(int i = ti-1;i< kk; i++)
		if(a[i]!=0)
			return 1;
	return 0;
}
void encod(int a[Max],int c)
{
	int t=1,ti=1, ci = 0,i;
	char ca[4*Max];
	while(judge(a,ti))
	{
		if(ti>1&&a[ti-1]!=0)    
		{
			ti--;
			t= a[ti++];      
		}
		else
			t = a[ti++];    
		while(t<c&&ti<kk)
		{
			t*=10;
			t+=a[ti++];
		}
		for( i =ti; i<kk; i++)
		{
			a[i-1] = t/c;
			t = 10*(t % c) + a[i];
		}
		a[i-1] = t/c;
		if(t%c<10)
			ca[ci++] = t%c+ 48;   //'0' ASCII码为48
		else
		{
			ca[ci++] = t%c + 55;  //'A' ASCII码为65
		}
	}
	ca[ci] = '\0';
	if(strlen(ca) < 8)
	{
		reverse(ca,ca+strlen(ca));
		printf("%7s\n",ca);
	}
	else
		printf("%7s\n","ERROR");
}
int main()
{
	int a[Max], ac,i,c ,s ,l;  //c是进制
	char ca[100];
	while(cin>>ca>>ac>>c)
	{
		a[1] = 0;
		s=0,l = strlen(ca);
		for(i = 0; i < l; i++)
			if(ca[i] -'0' < 10)
				s += (ca[i] - '0') * pow((double)ac,l-1-i);
			else
				s +=(ca[i] - 55)  * pow((double)ac,l-1-i);
		i = 1;
		while(s)
		{
			a[i++] = s%10; 
			s/=10;
		}
		kk = i;
		reverse(a+1,a+i);
		encod(a,c);
	}
	return 0;
}