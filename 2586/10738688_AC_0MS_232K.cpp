#include<iostream>
using namespace std;
int main()
{
	int s,d,r,i;
	while(cin>>s>>d)
	{
		r=-1;
		if(d>4*s)  ////5,10月亏损
			r=10*s-2*d;
		else if(2*d>3*s) //4 5 7 9
			r=8*s-4*d;
		else if(3*d>2*s)  //3 4 5 8 9 10
			r= 6*s-6*d;
		else if(4*d>s)    //2 3 4 5 7 8 9 10 12
			r= 3*s-9*d;
		if(r>=0)
			cout<<r<<endl;
		else cout << "Deficit" << endl;
	}
	return 0;
}



/*
1 2 3 4 5       5 10亏   4 5 8 9
2 3 4 5 6  
3 4 5 6 7  
4 5 6 7 8  
5 6 7 8 9 

6 7 8 9 10
7 8 9 10 11
8 9 10 11 12
*/