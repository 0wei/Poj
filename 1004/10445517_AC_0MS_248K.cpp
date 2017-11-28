#include<iostream>
using namespace std;
int main()
{
	double cb,av=0;
	int n = 12;
	while(n--)
	{
		cin>>cb;
		av+=cb;
	}
	cout<<"$"<<av/12<<endl;
	return 0;
}