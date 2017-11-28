/*
题意:题目大意：有N个男毕业生，举行了D次晚会，D行N列的矩阵，0表示Ni没有参加这次晚会，1表示参加了。判断有没有人参加了所有晚会
*/
#include <iostream>
#include <vector>
using namespace std;



int main()
{
	vector<int> arr;
	int n, d, t;
	int i, j;
	while(cin>>n>>d )
	{
		if(n==0 && d==0) break;
		arr.assign(n,1);
		for (i=0; i<d; i++)
			for (j=0; j<n; j++)
			{
				cin>>t;
				if(arr[j] == 1)
					arr[j] = t;
			}

		for (i=0; i<n; i++)
			if(arr[i] == 1)
				goto L;
		cout<<"no"<<endl;
		continue;
L:
		cout<<"yes"<<endl;
	}
	return 0;
}