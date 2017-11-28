#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s,st[20],t;
	int i,a[10],n,w;
	while(cin>>s&&s !="-1")
	{
		w = 1,st[0] = s,n = 0;
		while(w)
		{
			t = "";
			for(i = 0; i <10; i++)
				a[i] = 0;
			for(i =0; i < s.length(); i++)
			{
					 if(s[i] =='0')	a[0]++;
				else if(s[i] =='1') a[1]++;
				else if(s[i] =='2') a[2]++;
				else if(s[i] =='3') a[3]++;
				else if(s[i] =='4') a[4]++;
				else if(s[i] =='5') a[5]++;
				else if(s[i] =='6') a[6]++;
				else if(s[i] =='7') a[7]++;
				else if(s[i] =='8') a[8]++;
				else if(s[i] =='9') a[9]++;
			}
			for(i = 0; i < 10; i++)
			{	
				if(a[i]!=0)
				{
					if(a[i]/10!=0)
					{
						t +=a[i]/10 +'0';
						t +=a[i]%10 +'0';
					}
					else
						t +=a[i] +'0';				
					t +=i +'0';
				}
			}
			n++;
		//	cout<<t<<"  "<<n<<endl;
			if(15 == n)
			{
				w = 0;
				cout<<st[0]<<" can not be classified after 15 iterations"<<endl;
				break;
			}
			else if(n==1&&t ==st[0])
			{
				w = 0;
				cout<<st[0]<<" is self-inventorying "<<endl;
			}
			else if(n!=1&&t == s)
			{
				w = 0;
				cout<<st[0]<<" is self-inventorying after "<<n-1<<" steps "<<endl;
			}
			else if(n!=1)
			{
				for(i = 1; i< n-1 ; i++)
					if(t == st[i])
					{	
						w = 0;
						cout<<st[0]<<" enters an inventory loop of length "<< n-i<<" "<<endl;
					}
			}
			st[n] = s = t;
		}
	}
	return 0;
	
}