#include <iostream>
#include <string>
using namespace std;
string dir[10005];
int dirlen[10005];
string str;
int len;	//str.length()
int fix[10005], f;
void Change(int k)
{
	int pos = 0;
	for (int i=0; i<len; i++)
	{
		if (str[i] != dir[k][i])	//不相同则替换掉.
			pos ++;
		if (pos == 2)
			break;
	}
	if (pos != 2)
		fix[f++] = k;
}
void Delete(int k)	//删除str 里的一个字母 len -1 == dirlen[k]
{
	int pos = 0;
	for (int i=0,j=0; i<len && j<dirlen[k]; )
	{
		if (str[i] != dir[k][j])
		{
			i++;
			pos ++;
			if (pos == 2)
				break;
		}
		else
		{
			i++;
			j++;
		}
		
	}
	if (pos != 2)
		fix[f++] = k;
}
void Add(int k)	//在str 中添加一个词len + 1 == dirlen[k]
{
	int pos = 0;
	for (int i=0,j=0; j<dirlen[k] && i<len; )
	{
		if (str[i] != dir[k][j])
		{
			j++;
			pos ++;
			if (pos == 2)
				break;
		}
		else
		{
			i++;
			j++;
		}
		
	}
	if (pos != 2)
		fix[f++] = k;
}
int main()
{
	int n=0,i;
	while (cin>>dir[n] && dir[n][0] != '#')
	{
		dirlen[n] = dir[n].length();
		n++;
	}
	while (cin>>str && str[0] != '#')
	{
		len = str.length();
		f = 0;
		bool flg = false;
		for (i=0; i<n; i++)
		{
			if (len == dirlen[i])
			{
				if(str.compare(dir[i]) == 0)
				{
					flg = true;
					break;
				}
				else 
					Change(i);
			}
			else if (len - 1 == dirlen[i])
				Delete(i);
			else if (len + 1 == dirlen[i])
				Add(i);
		}
		if (flg)
			cout<<str<<" is correct"<<endl;
		else
		{
			cout<<str<<":";
			for (i=0; i<f; i++)
				cout<<" "<<dir[fix[i]];
			cout<<endl;
		}
	}
	return 0;
}