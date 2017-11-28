#include <iostream>
#include <queue>
#include <string>
using namespace std;
const int N = 4;
const int MAX = 65536;

int arr[16]={0xc800,0xe400,0x7200,0x3100,0x8c80,0x4e40,0x2720,0x1310,0x08c8,0x04e4,0x0272,0x0131,0x008c,0x004e,0x0027,0x0013};

int main()
{
	queue<int>que;
	bool used[MAX];
	int step[MAX];
	bool flag;
	string str;
	int n, t, i, j;

	n = 0;

	for (i=0; i<N; i++)
	{
		cin>>str;	
		for (j=0; j<N; j++)
		{
			n<<=1;//b 用0表示, w用1表示, 全w十进制为65535
			if (str[j] == 'w')
				n+= 1;
		}
	}
	if (n == 0 || n == 65535)
	{
		cout<<"0"<<endl;
		flag = false;
	}
	memset(used, false, sizeof(used));
	memset(step, 0, sizeof(step));
	while (!que.empty()) que.pop();
	flag = true;
	used[n] = true;
	step[n] = 0;
	que.push(n);
	while (!que.empty() && flag)
	{
		n = que.front();
		que.pop();


		for (i=0; i<16; i++)
		{
			t = n ^ arr[i];
			if (!used[t])
			{
				used[t] = true;
				step[t] = step[n] + 1;
				que.push(t);
			}
			if (t == 65535 || t == 0)
			{
				cout<<step[t]<<endl;
				flag = false;
				break;
			}
		}
	}
	if (flag)
		cout<<"Impossible"<<endl;

	return 0;
}