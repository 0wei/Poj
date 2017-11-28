#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string dir[105], sor[105], st;
	int i=0, j, n, len;
	bool flg;
	while (cin>>dir[i] && dir[i][0] != 'X')
	{
		sor[i] = dir[i];
		sort(sor[i].begin(), sor[i].end());
		i++;
	}
	n = i;
	while (cin>>st && st[0] != 'X')
	{
	
		sort(st.begin(), st.end());
		flg = false;
		for (i=n-1; i>=0; i--)
		{
			if (st.compare(sor[i]) == 0)
			{
				cout<<dir[i]<<endl;
				flg = true;
			}
		}
		if (!flg)
			cout<<"NOT A VALID WORD"<<endl;
		cout<<"******"<<endl;
	}
	return 0;
}