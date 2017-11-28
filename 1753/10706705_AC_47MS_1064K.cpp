#include<iostream>
#include<memory.h>
using namespace std;

#define MAXN 65536
int que[MAXN*2];
int front,rear;
bool used[MAXN];
int step[MAXN];
bool find0;
void bfs(int p)
{
	find0=false;
	step[p]=0;
	if(p==0||p==65535)
	{
		cout<<"0"<<endl;
		find0=true;
		return;
	}
	memset(used,false,sizeof(used));
	memset(que,0,sizeof(que));
	memset(step,0,sizeof(step));
	rear=front=0;
	que[rear++]=p;
	used[p]=true;
	while(rear>front)
	{
		int tmp=que[front++];
		int t=tmp;
		for(int i=0;i<16;i++)
		{
			tmp=t;
			tmp^=1<<(15-i);   //第i位本身取反
			if(i%4==0)tmp^=1<<(14-i);  //只有左边
			else if(i%4==3)tmp^=1<<(16-i); //只有右边
			else tmp^=5<<(14-i);   //两边都有

			if(i<=3) tmp^=1<<(15-4-i);  //只有下边
			else if(i>=12)tmp^=1<<(15+4-i);//只有上边
			else
			{
				tmp^=1<<(15-4-i); 
				tmp^=1<<(15+4-i); 

			}
			if(tmp==0||tmp==65535)
			{
				cout<<step[t]+1<<endl;
				find0=true;
				return;
			}
			if(used[tmp]==false)
			{
				que[rear++]=tmp;
				used[tmp]=true;
				step[tmp]=step[t]+1;
			}
		}
	}
}
int main()
{
	int i;
	char color;
	int id;
	id=0;
	for(i=0;i<15;i++)
	{
		
			cin>>color;
			if(color=='b')id+=1;
			id<<=1;
	}
	cin>>color;
	if(color=='b')id+=1;
	bfs(id);
		if(find0==false)
		{
			cout<<"Impossible"<<endl;
		}
	
	return 0;
}