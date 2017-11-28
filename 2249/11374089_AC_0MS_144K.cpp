#include<iostream>
using namespace std;
double c(int c,int k)
{
 double a=1;
 int i,j=2;
 for(i=c;i>c-k;i--)
 a=a*i/(c-i+1);
 return a;
}
int main()
{
 int n,k;
 while(scanf("%d%d",&n,&k)!=EOF && (n!=0 || k!=0))
 {
  if(k>n/2 )k=n-k;
  printf("%.0lf\n",c(n,k));
 }
 return 0;

}
