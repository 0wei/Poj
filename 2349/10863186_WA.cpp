#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
struct struct_edges
{   int bv,tv; //bv 起点  tv 终点
     double w; //权值
};
struct_edges edges[300000]; //边集
struct struct_a
{   
	double x;
	double y;
};
struct_a arr_xy[300000];
int point[300000],p,e;  //n 顶点数, e 边数(注意是无向网络)
double dis[300000];
int kruscal_f1(int point[], int v)  
{ 
	int i = v;
     while(point[i] > 0) 
		 i = point[i]; 
	 return i;
}
bool UDlesser(struct_edges a, struct_edges b)
{
	return a.w < b.w;
}

void kruscal() //只需要准备好n，e，递增的边集edges[]即可使用
{  
	int v1,v2,i,j;
     for(i=0; i<p ;i++) 
		 point[i]=0;
     i = j = 0;
     while(j<p-1 && i<e) 
	 {
          v1 = kruscal_f1(point, edges[i].bv);
          v2 = kruscal_f1(point, edges[i].tv);
          if(v1 != v2) 
		  {
               dis[i] = edges[i].w; //注意sum初始为0
               point[v1]=v2;
               j++;
		  }
          i++;
	 }
}

int main()
{  
	
	int k,i,j,n;
	cin>>n; 
	k=0;
	int s;
     while(n--) 
	 {
		 cin>>s>>p;
         memset(dis, 0, sizeof(dis)); 
		 k++;
          for(i=0; i<p ;i++)
               cin>>arr_xy[i].x>>arr_xy[i].y; 
		  e=0;
          for(i=0; i<p ;i++) //从0开始计数
               for(j=i+1; j<p ;j++) //注意是无向网络
               {   
                    edges[e].bv=i; edges[e].tv=j;
                    edges[e].w=sqrt((arr_xy[i].x-arr_xy[j].x)*(arr_xy[i].x-arr_xy[j].x)+(arr_xy[i].y-arr_xy[j].y)*(arr_xy[i].y-arr_xy[j].y));
                    e++;
					edges[e].bv=j; edges[e].tv=i;
					edges[e].w = edges[e-1].w;
					e++;
			   }
			  sort(edges,edges+e,UDlesser);  //得到一个递增的边集，注意是从0开始计数
               kruscal();
              cout<<fixed<<setprecision(2)<<dis[p - s]<<endl;  

	 }
}
