#include <iostream>
using namespace std;
bool prm[1005];	//全局为false
void Prime()
{
	int i, t;
	prm[1] = false;
	for (i=2; i<1005; i++)
	{
		if (!prm[i])
		{
			t = i<<1;
			while (t<1005)
			{
				prm[t] = true;
				t+= i;
			}
		}
	}
}
int main()
{
	int n, c, i, j, cnt;
	Prime();
	while (cin>>n>>c)
	{
		cout<<n<<" "<<c<<":";
		for (i=1, cnt=0; i<=n; i++)
		{	
			if (!prm[i])
				cnt++;
		}
		//for (i=1; i<=n; i++)
		//		if (!prm[i])
		//			cout<<i<<" ";
		//	cout<<endl;
		if (2*c > cnt)
		{
			for (i=1; i<=n; i++)
				if (!prm[i])
					cout<<" "<<i;
			cout<<endl;
			/*continue;*/
		}
		else
		{
			if (cnt % 2 == 0)
			{
				for (j=1, i=1; j<(cnt-2*c)/2+1;i++)
				{
					if (!prm[i])
						j++;
				}
				for (j=0; j<2*c; i++)
					if (!prm[i])
					{
						j++;
						cout<<" "<<i;
					}
				cout<<endl;
			}
			else
			{
				for (j=1, i=1; j<(cnt-2*c+1)/2+1;i++)
				{
					if (!prm[i])
						j++;
				}
				for (j=1; j<2*c; i++)
					if (!prm[i])
					{
						j++;
						cout<<" "<<i;
					}
				cout<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
}