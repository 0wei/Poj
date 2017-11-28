#include<iostream>
using namespace std;
int main()
{
	float n,c,s;
	while(cin>>c&&c)
	{
		s = 0.5,n = 1;
		while(s<=c)
		{
			s+=1/(++n+1);
		}
		cout<<n<<" card(s)"<<endl;
	}
	return 0;
}