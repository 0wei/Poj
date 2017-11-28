#include <iostream>
#include <queue>
using namespace std;

int arr[16]={0xc800,0xe400,0x7200,0x3100,0x8c80,0x4e40,0x2720,0x1310,0x08c8,0x04e4,0x0272,0x0131,0x008c,0x004e,0x0027,0x0013};

queue<int> que;
bool used[65536];
int step[65536];

int main()
{
	int num;
	int i;
	char ch;
	num = 0;
	for (i=0; i<16; i++)
	{
		cin>>ch;
		num <<= 1;
		if  (ch == 'b') 
			num += 1;
	}
	
	

	while (!que.empty())
		que.pop();
	memset(used, false, sizeof(used));
	que.push(num);
	step[num] = 0;
	used[num] = true;
	int tmp;
	bool flags = false;
	while (!que.empty() && !flags)
	{
		tmp = que.front();
		que.pop();
		for (i=0; i<16; i++)
		{
			num = tmp;
			num ^= arr[i];
			if (!used[num])
			{
				used[num] = true;
				step[num] = step[tmp] + 1;
				que.push(num);
			}
			if(num == 0 || num == 65535)
			{
				flags = true;
				break;
			}
		}
	}

	if (flags)
		cout<<step[num]<<endl;
	else 
		cout<<"Impossible"<<endl;
	
	return 0;
}