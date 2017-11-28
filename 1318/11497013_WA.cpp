#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string dir[105];
string str;
int map[26];
int dirlen[105];

bool judge(int p, int len)
{
	int i;
	for (i=0; i<len; i++)
		map[dir[p][i] - 'a']--;
	for (i=0; i<26; i++)
	{	
		if (map[i] != 0)
		{
			return false;
		}
	}
	return true;

}



int main()
{
	int i, j, len, n=0;
	bool flg;
	while (cin>>dir[n] && dir[n][0] != 'X') n++;
	for (i=0; i<n; i++)
		dirlen[i] = dir[i].length();
	while (cin>>str && str[0] != 'X')
	{

		flg = false;
		len = str.length();
		for (i=0; i<n; i++)
		{
			if (len == dirlen[i])
			{
				memset(map, 0, sizeof(map));
				for (j=0; j<len; j++)
					map[str[j]-'a'] ++;
				if (judge(i,len))
				{
					flg = true;
					cout<<dir[i]<<endl;
				}
			}

		}
		if (!flg)
			cout<<"NOT A VALID WORD"<<endl;
		cout<<"******"<<endl;		
	}
	return 0;
}