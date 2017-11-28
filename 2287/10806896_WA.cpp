
#include<iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, nn;
	int m;
	int i, j;
	int tian[1020], king[1020];
	while(cin>>n && n!=0)
	{
		for(i=0; i<n; i++)
			cin>>tian[i];
		for(i=0; i<n; i++)
			cin>>king[i];
		sort(tian, tian + n);
		sort(king, king + n);
		i = j = 0;
		m = 0;
		nn = n-1;
		while(i < n)
		{
			if(tian[i] > king[j])
			{
				m++;
			}
			else 
			{
				if(tian[i] < king[nn--])
					m--;
				j--;	
			}
			i++;
			j++;
		}
		cout<<m * 200<<endl;
	}
	return 0;
}

