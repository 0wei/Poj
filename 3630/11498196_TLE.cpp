#include <iostream>
using namespace std;
bool flg;
struct node{
	node *fail; //失败指针
	node *next[10]; //Tire每个节点的26个子节点（最多26个字母）
	int count; //是否为该单词的最后一个节点
	node(){ //构造函数初始化
		fail=NULL;
		count=0;
		memset(next,NULL,sizeof(next));
	}
}*q[500001]; //队列，方便用于bfs构造失败指针
void insert(char *str,node *root){
	node *p=root;
	int i=0,index;
	int len = strlen(str);
	while(str[i])
	{
		index=str[i]-'0';
		if(p->next[index]==NULL)
			p->next[index]=new node();
		else
		{
			if (i == len-1 || p->next[index]->count != 0)
				flg = false;
		}
		p=p->next[index];
		i++;
	}
	p->count++;

}

int main()
{
	int t, n;
	char str[1000];
	cin>>t;
	while (t--)
	{
		cin>>n;
		node *root = new node;
		flg = true;
		while (n--)
		{
			cin>>str;
			if (flg)
				insert(str, root);
		}
		if (flg)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}