/*
m 个人, 数到 k 退出
*/


#include <iostream>
#include <string>
using namespace std;

int fun(int m,int k,int i){

	if(i==1)
		return (m+k-1)%m;
	else
		return (fun(m-1,k,i-1)+k)%m;

}
int main()
{
	string str[100];
	int n, w, s;
	int i;
	while (scanf("%d", &n) != EOF)
	{
		for (i=0; i<n; i++)
			cin>>str[i];
		scanf("%d,%d", &w, &s);
		for(i=1;i<=n;i++)
		{
			int t = fun(n,s,i) + w -1;
			while(t>=n)
			{
				t -= n;
			}
			cout<<str[t]<<endl;
		}
	}
	return 0;
}
