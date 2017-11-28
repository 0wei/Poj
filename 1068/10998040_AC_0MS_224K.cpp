#include <iostream>

#include <vector>
using namespace std;

vector<int> arr;

vector<int> vec;

int main()
{
	int t, n;
	int x, tmpx, i, j;
	int left, right;
	cin>>t;
	while (t--)
	{
		cin>>n;
		vec.clear();
		arr.clear();
		tmpx = 0;
		while (n--)
		{
			cin>>x;
			for (i=0; i<x-tmpx; i++)
				arr.push_back(-1);  //左括号 "("
			arr.push_back(1);	//右括号 ")"
			tmpx = x;
		}
		left = right = 0;
		
		for (i=arr.size()-1; i>=0; i--)
		{
			if (arr[i] == 1)
			{
				for (j=i; j>=0; j--)
				{
					if (arr[j] == 1)
					{
						left++;
						right++;
					}
					else
					{
						left--;
					}
					if (left == 0)
					{
						vec.push_back(right);
						right = 0;
						break;
					}
				}
			}
		}
		cout<<vec[vec.size()-1];
		for (i=vec.size()-2; i>=0; i--)
			cout<<" "<<vec[i];
		cout<<endl;
	}
	return 0;
}