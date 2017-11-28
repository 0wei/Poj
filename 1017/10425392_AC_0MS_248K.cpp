#include<iostream>
using namespace std;
int main()
{
	int a[7],b[7],i,n,c;
	while(1)
	{   
		c=0;
		for(i = 1 ; i< 7 ;i++)
			cin>>a[i];
		for(i = 1; i < 7; i++)
			if(a[i]==0)
				c++;
		if(c==6)
			break;
		n =a[6];   //6
		n+=a[5];
		n+=a[4];
		n+=a[3]/4;
		a[3]%=4;
		b[1] =a[5]*11;
		b[2] =a[4]*5;

		if(a[3] !=0)
			n++;
		if(a[3]==1)
		{
			b[1]+=7;
			b[2]+=5;
		}
		else if(a[3]==2)
		{
			b[1]+=6;
			b[2]+=3;
		}
		else if(a[3]==3)
		{
			b[1]+=5;
			b[2]+=1;
		}
		a[1] -=b[1];    
		a[2] -=b[2];
		if(a[2]<0)  // a2<0
			a[1]+=a[2]*4;
		else 
		{
			n+=a[2]/9;
			a[2]%=9;
			if(a[2]!=0)
			{
				n++;
				a[1]=a[1]-36+4*a[2];
			}
		}
		if(a[1]>0)
		{
			n+=a[1]/36;
			if(a[1]%36!=0)
				n++;
		}
		cout<<n<<endl; 
	}
	return 0;
}