#include<iostream>
using namespace std;
int main()
{
	int n ,s; 
	bool bl = true;
	while(cin>>n&&n)
	{
		if(bl)
		{
			cout<<"PERFECTION OUTPUT\n";
			bl = false;
		}
		s = 0;
		printf("%5d  ",n);
		for(int i =1; i <= n/2; i++)
			if(n%i==0)
				s +=i;
		if(s==n)
			cout<<"PERFECT"<<endl;
		if(s < n)
			cout<<"DEFICIENT"<<endl;
		if(s > n)
			cout<<"ABUNDANT"<<endl;
	}
	cout<<"END OF OUTPUT"<<endl;
	return 0;
}