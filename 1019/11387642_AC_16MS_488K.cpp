#include <iostream>
#include <cmath>
using namespace std;
const int N = 32000;
unsigned a[N];
unsigned s[N];

void initialize()
{
	a[1] = 1;
	s[1] = 1;
	int i;
	for ( i=2; i<N; i++)
	{
		a[i] = a[i-1] + (int)log10((double)i) + 1;
		s[i] = s[i-1] + a[i];
	}
	//cout<<i<<endl;
}

void GetNum(int n)
{
	int i;
	int len = 0;
	for (i=1; s[i]<n; i++);

	int pos = n - s[i-1];
	for (i=1; len < pos; i++)
		len += (int)log10((double)i) + 1;
	
	cout<<(i-1) / (int)pow((double)10,len-pos)%10<<endl;
}

int main()
{
	int n;
	initialize();
	//cout<<INT_MAX<<endl;
	int t;
	cin>>t;
	while (t--)
	{
		cin>>n;
		GetNum(n);
	}
	return 0;
}