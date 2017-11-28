#include<iostream>
#include<vector>
using namespace std;

void mul(vector<int> &v, int p)
{
	int i, tmp;
	
	for (i=0; i<v.size(); i++)
	{
		v[i] *= p;
	}
	for (i=0; i < v.size()-1; i++)
	{
		v[i+1] += v[i] / 10;
		v[i] %= 10;
	}
	
	while (v[i] >=10)     //最后一位要注意当v[i]是三位数或者更多位,需要连续进位
	{
		v.push_back(v[i] / 10);
		v[i] %= 10;
		i++;
	}
}

void div(vector<int> &v, int p)
{
	int i;
	for (i=v.size()-1; i>0; i--)
	{
		v[i-1] += v[i] % p * 10;
		v[i] /= p;
	}
	v[0] /= p;
}

int main()
{
	vector<int> vec;
	int n;
	int i;
	while(cin>>n && n!=-1)
	{
		vec.clear();
		vec.push_back(1);
		for (i=1; i<n; i++)
		{
			//mul(vec, i+1);
			mul(vec, (4 * i + 2));
			div(vec, i + 2);
		}
		i = vec.size()-1;
		while (vec[i] == 0)
		{
			i--;
		}
		while (i >= 0)
		{
			cout<<vec[i--];
		}
		cout<<endl;
	}
	return 0;
}
