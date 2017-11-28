#include<iostream>
using namespace std;
int main()
{
	int f,a,b,c;
	double sum;
	while(cin>>f>>a>>b>>c&&f+a+b+c)
	{
		if(f<a) sum = 40+f-a;
		else    sum = f-a;
		if(a>b) sum +=40-a+b;
		else sum+= b-a;
		if(b<c) sum += 40+b-c;
		else    sum += b-c;
		sum = sum/40*360+360*3;
		cout<<sum<<endl;
	}
	return 0;
}