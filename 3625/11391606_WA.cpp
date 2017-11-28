/*
 * poj3625.cpp
 *
 *  Created on: 2010-8-18
 *      Author: friendy
 */

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

struct Edge{
	int s,t;
	double dis;
	bool operator<(const Edge &other)const{
		return dis<other.dis;
	}
}edg[1000001];
double sum=0;
double point[1001][2];
int map[1001][1001];
int f[1001],_rank[1001],n;
bool visted[1000001];
void Init(){
	int i;
	for(i=1;i<=n;i++){
		f[i]=i;
		_rank[i]=0;
	}
}

int Find(int x){
	if(x!=f[x])
		f[x]=Find(f[x]);
	return f[x];
}

void Union(int i,int j,int k){
	/*int x=Find(i);
	int y=Find(j);
	if(x==y)
		return ;*/
	if (visted[i] && visted[j]) return;
	visted[i] = visted[j] = true;
	sum+=sqrt((double)edg[k].dis);
	/*if(_rank[x]>_rank[y])
		f[y]=x;
	else
	{
		f[x]=y;
		if(_rank[x]==_rank[y])
			_rank[y]++;
	}*/
}
int main(){
	int i,j,m,num,a,b;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%lf %lf",&point[i][0],&point[i][1]);
	}
	Init();
	memset(map,0,sizeof(map));
	memset(visted, false, sizeof(visted));
	for(i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		visted[a] = visted[b] = true;
		map[a][b]=map[b][a]=1;
	}
	num=0;
	for(i=1;i<=n-1;i++){
		for(j=i+1;j<=n;j++){
			if(map[i][j]){
				edg[num].s=i;
				edg[num].t=j;
				edg[num].dis=0.0;
				num++;
			}
			else{
				edg[num].s=i;
				edg[num].t=j;
				edg[num].dis=(point[i][0]-point[j][0])*(point[i][0]-point[j][0])+(point[i][1]-point[j][1])*(point[i][1]-point[j][1]);
				num++;
			}
		}
	}
	sort(edg,edg+num);

	for(i=0;i<num;i++){
		Union(edg[i].s,edg[i].t,i);
	}
	printf("%.2f\n",sum);
}
