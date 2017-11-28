#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string dir[105], sor[105], st;
	int i=0, j, n, len;
	bool flg, all;
	while (cin>>dir[i] && dir[i++][0] != 'X');
	n = i;
	sort(dir, dir+n);

	for (i=0; i<n; i++)
	{
		sor[i]= dir[i];
		sort(sor[i].begin(), sor[i].end());
	}
	while (cin>>st && st[0] != 'X')
	{
		sort(st.begin(), st.end());
		all = false;
		for (i=0; i<n; i++)
		{
			flg = true;
			if (st.length() != sor[i].length())
				continue;
			for (j=0; j<st.length(); j++)
				if (st[j] != sor[i][j])
				{
					flg = false;
					break;
				}
			if (flg)
			{
				cout<<dir[i]<<endl;
				all = true;
			}
			/*if (st.compare(sor[i]) == 0)
			{
				cout<<dir[i]<<endl;
				flg = true;
			}*/
		}
		if (!all)
			cout<<"NOT A VALID WORD"<<endl;
		cout<<"******"<<endl;
	}
	return 0;
}