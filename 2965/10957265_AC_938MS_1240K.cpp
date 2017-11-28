#include <iostream>
#include <queue>
using namespace std;

int chang[] = {
	63624, 62532, 61986, 61713,
	36744, 20292, 12066, 7953,
	35064, 17652, 8946, 4593,
	34959, 17487,8751, 4383};

	struct point 
{
	int x, y;
};


bool used[65536];
int step[65536];

int path[20];
point pt[65536];

int main()
{
	queue<int> que;
	int id, n;
	char ch;
	int i, j;
	id = 0;
	for (i=0; i<16; i++)
	{
		id <<= 1;
		cin>>ch;
		if (ch == '+')
			id += 1;
	}
	memset(used, false, sizeof(used));
	step[id] = 0;
	pt[id].x = id;
	n = id;
	used[id] = true;
	que.push(id);
	
	while (!que.empty())
	{
		int tmp = que.front();
		que.pop();
		for (i=0; i<16; i++)
		{
			id = tmp;
			id ^= chang[i];
			if (!used[id])
			{
				used[id] = true;
				que.push(id);
				step[id] = step[tmp] + 1;
				pt[id].x = tmp;
				pt[id].y = i;
				
			}
			if (id == 0)
				goto L;
		}
	}
L:
	cout<<step[0]<<endl;
	j = 0;
	while (id != n)
	{
		path[j++] = pt[id].y;
		id = pt[id].x;
	}
	for (i=j-1; i>=0; i--)
		cout<<path[i]/4+1<<" "<<path[i] % 4+1<<endl;
	return 0;
}