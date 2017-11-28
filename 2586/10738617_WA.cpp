#include<iostream>
using namespace std;
int main()
{
	int s,d,r,i;
	while(cin>>s>>d)
	{
		r=0;
		for(i=1;i<5;i++)
			if((5-i)*s<d*i)  //每个表只有一个月亏损(如5,10亏损)
				if(r<(12-2*i)*s-2*i*d)
					r=(12-2*i)*s-2*i*d;
		if(r>=0)
			cout<<r<<endl;
		else cout << "Deficit" << endl;
	}
	return 0;
}