#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int num, arr[10], len, i, big, small, result, cnt;
	while (cin>>num && num != -1)
	{
		cout<<"N="<<num<<":"<<endl;
		cnt = 0;
		if (num <1000 || num > 9999)
		{
			cout<<"No!!"<<endl;
			continue;
		}
		bool flg = false;
		while (!flg || num != 6174 && num != 0)
		{
			flg = true;
			len = 0;
			while (num)
			{
				arr[len++] = num % 10;
				num /= 10;
			}
			sort(arr, arr+len);
			big = small = 0;
			for (i=0; i<len; i++)
			{
				small *= 10;
				big *= 10;
				small += arr[i];
				big += arr[len-1-i];
			}
			num = big - small;
			if (num != 0 || cnt != 0)
			cout<<big<<"-"<<small<<"="<<num<<endl;
			cnt ++;
		}
		if (big == small && cnt == 1)
			cout<<"No!!"<<endl;
		else
		cout<<"Ok!! "<<cnt<<" times"<<endl;

	}
	return 0;
}