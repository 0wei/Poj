#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

struct Edge{		//s - > t 的权值是dis
	int s,t;
	int dis;
	bool operator<(const Edge &other)const{
		return dis<other.dis;
	}
}edg[1000001];
int sum;
int f[1001],n;

void Init(){
	int i;
	for(i=1;i<=n;i++){
		f[i]=i;
	}
}

int Find(int x){
	if(x!=f[x])
		f[x]=Find(f[x]);
	return f[x];
}

void Union(int i,int j,int k){
	int x=Find(i);
	int y=Find(j);
	if(x==y)
		return ;
	sum+=edg[k].dis;
	f[x] = y;
}
int main(){
	int num;
	int i, j;
	char ch1, ch2;
	int road, len;
	while (cin>>n && n)
	{
		num = sum = 0;
		Init();
		for (i=1; i<n; i++)
		{
			cin>>ch1>>road;
			for (j=0; j<road; j++)
			{
				cin>>ch2>>len;
				edg[num].s = ch1 - 'A' + 1;
				edg[num].t = ch2 - 'A' + 1;
				edg[num++].dis = len;
			}
		}


		sort(edg,edg+num);

		for(i=0;i<num;i++){
			Union(edg[i].s,edg[i].t,i);

		}
		cout<<sum<<endl;
	}
	return 0;
}
