#include<iostream>
#include<string>
using namespace std;
int main()
{
	int i,n,in, x,y;
	string s[32],si,st;
	for( i = 0; i < 32; i++)
		st += '.';	
	while(cin>>n)
	{
		in = 0; 
		while(in < n)
		{
			in++;
			for( i = 0; i < 32; i++)
				s[i] = st;
			cin>>x>>y>>si;
			cout<<"Bitmap #"<<in<<endl;

			for(i = 0; i <si.length(); i++)
			{
				if(si[i] =='.')
					break;
				if(si[i] =='E')
				{
					s[y-1][x] = 'X';
					x++;
				}
				if(si[i] =='N')
				{
					s[y][x] = 'X';
					y++;
				}
				if(si[i] =='W')
				{
					s[y][x-1] = 'X';
					x--;
				}
				if(si[i] =='S')
				{
					s[y-1][x-1] = 'X';
					y--;
				}
			}
			for(i = 31; i >=0; i--)
				cout<<s[i]<<endl;
			cout<<endl;
		}
	}
	return 0; 
}