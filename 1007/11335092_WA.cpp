#include <iostream>
#include <string>
using namespace std;
int main ()
{
    int l,n,nub[200],i,j,k,js,a[200];
	string str[200];
	memset(a,-1,sizeof(a));
	while(cin>>l>>n){
		for (i=0;i<n;i++)
			cin>>str[i];
		for (i=0;i<n;i++)
		{
			js=0;
			for (j=0;j<l;j++)
				for (k=j+1; k<l; k++)
					if (str[i][j]>str[i][k])
						js++;
					nub[i] = js;
		}
		for (j=0;j<=n;j++)
		{
			k=0;js=0;
			for (i=0;i<=n;i++)
			{
				if (k<=nub[i])
				{
					k = nub[i];
					js = i;
				}
			}
			a[j] = js;//k;
			nub[js] = -1; 
		}
		for (i=n-1;i>=0;i--)
		{
			cout<<str[a[i]]<<endl;
		}
	}
	return 0;
}