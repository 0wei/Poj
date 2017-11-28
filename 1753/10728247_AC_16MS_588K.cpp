#include<iostream>
#include<queue>
using namespace std;
int Arr[16]={0xc800,0xe400,0x7200,0x3100,
0x8c80,0x4e40,0x2720,0x1310,
0x08c8,0x04e4,0x0272,0x0131,
0x008c,0x004e,0x0027,0x0013};

queue<int> stk;
bool used[65536];
int step[65536];
bool flags;
void BFS(int p)
{
	if(p==0||p==65535)
	{	
		cout<<"0"<<endl;
		flags=true;
		return;
	}
	stk.push(p);
	used[p]=true;
	step[p]=0;
	while(!stk.empty())
	{
		int t=stk.front();
		int tt=t;
		stk.pop();
		for(int i=0;i<16;i++)
		{
			t=tt;
			t^=Arr[i];
			if(t==0||t==65535)
			{	
				cout<<step[tt]+1<<endl;
				flags=true;
				return;
			}
			if(used[t]==false)
			{
				stk.push(t);
				used[t]=true;
				step[t]=step[tt]+1;
			}
		}
	}
}

int main()
{
	int id;
	
	id=0;
	while(!stk.empty())stk.pop();
	memset(used,false,sizeof(used));
	char c;
	for(int i=0;i<16;i++)
	{
		cin>>c;
		id<<=1;
		if(c=='b')id++;
	}
	//cout<<id<<endl;
	BFS(id);
	if(flags==false)
		cout<<"Impossible" <<endl;
	return 0;
}





