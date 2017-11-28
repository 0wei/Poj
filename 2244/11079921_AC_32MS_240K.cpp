#include <iostream>
using namespace std;

int fun(int m,int k,int i)
{
 
    if(i==1)
        return (m+k-1)%m;
    else
        return (fun(m-1,k,i-1)+k)%m;
 
}
int main()
{
     int n;
	 while (cin>>n && n != 0)
	 {
		 int m = 2;
		 while(true)
		 {
			if (fun(n-1,m,n-1) == 0)
			{
				cout<<m<<endl;
				break;
			}
			m++;
		 }
	 }
    return 0;
}
