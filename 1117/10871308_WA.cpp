#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	int n;
	int co;
	int arr[9999];
	int tmp[9999];
	int i, j;
	while(cin>>n)
	{
		co = 0;
		i = 0;
		j = 0;
		for (a = 1; a<10; a++)
			for(b=0; b<10; b++)
				for(c=0; c<10; c++)
				{
					int t = 100 * a + 10 * b + c;				
					if(t + 10 * a + b == n)
					{
						arr[i++] = b;
						arr[i++] = a;
						tmp[j++] = t;
						co++;
					}
					if(t + 10 * a + c == n)
					{
						arr[i++] = c;
						arr[i++] = a;
						tmp[j++] = t;
						co ++;
					}
					if(t + 10 * b + c == n)
					{
						arr[i++] = c;
						arr[i++] = b;
						tmp[j++] = t;
						co++;
					}
				}
			i = 0;
			j = 0;
			cout<<co<<endl;
			while(co--)
			{
				cout<<tmp[j++]<<" + "<<arr[i++]<<arr[i++]<<" = "<<n<<endl;
			}
	}
	return 0;
}