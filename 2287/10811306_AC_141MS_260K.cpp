
#include<iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int m;
	int i, j;
	int x, y;
	int tian[1020], king[1020];
	while(cin>>n && n!=0)
	{
		for(i=0; i<n; i++)
			cin>>tian[i];
		for(i=0; i<n; i++)
			cin>>king[i];
		sort(tian, tian + n);
		sort(king, king + n);
		i = j = n-1;
		x = y = 0;
		m = 0;
		while(n-- > 0)
		{
			if(tian[i] > king[j])
			{
				m++;
				i--;
				j--;
			}
			else if(tian[x] > king[y])
			{
				m++;
				x++;
				y++;
			}
			else
			{
				if(tian[x] < king[j])
					m--;
				j--;
				x++;
			}
			
		}
		cout<<m * 200<<endl;
	}
	return 0;
}

