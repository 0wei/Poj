#include <iostream>
using namespace std;
const int N = 1e6+5;
long long phi[N];

void Init()
{
	int i, j;
	for (i=1; i<N; i++)
		phi[i] = i;
	for (i=2; i<N; i+=2)
		phi[i] /= 2;
	for (i=3; i<N; i+=2)
		if (phi[i] == i)
			for (j=i; j<N; j+=i)
				phi[j] = phi[j] / i * (i - 1);
	//for (i=1; i<10; i++)
	//	cout<<phi[i]<<" ";
	for (i=3; i<N; i++)
		phi[i] += phi[i-1];

}

int main()
{
	int n;
	Init();
	while (cin>>n && n)
		cout<<phi[n]<<endl;
	return 0;
}