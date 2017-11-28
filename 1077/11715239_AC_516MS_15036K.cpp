#include <iostream>
#include <queue>
#include <vector>
#include <iterator>
#include <string>
using namespace std;

const int MAXX_SIZE = 362885;

int fac[] = {1,1,2,6,24,120,720,5040,40320};
bool used[MAXX_SIZE];

struct Nod
{
	string str;	//数组
	int postion9;  //可交换的位置
}nod[MAXX_SIZE];

struct Step
{
	int last;
	char c;		//l0, r1, u2, d3

}step[MAXX_SIZE];

int dir[][2] = {1,0, -1,0, 0,1, 0,-1 };

char st[] = {'d', 'u', 'r', 'l'};

int Kt(string str, int n)
{
	int i, j, cnt, sum=0;
	for (i=0; i<n; i++)
	{
		cnt = 0;
		for (j=i+1; j<n; j++)
			if (str[i] > str[j])
				cnt++;
		sum += cnt * fac[n-1-i];
	}
	return sum;
}

string InverKt(int sum, int n)
{
	int i, j, t;
	bool Int[20];
	string str;
	for (i=0; i<n; i++)
	{
		t = sum / fac[n-1-i];
		for (j=0; j<n; j++)
		{
			if (Int[j])
			{
				if (t == 0)
					break;
				t--;
			}
		}
		str += j+1+'0';
		Int[j] = false;
		sum %= fac[n-1-i];
	}
	//str += '\0';
	return str;
}


void bfs(string str, int pos)
{
	queue<int>que;
	
	//string str = "123456789";
	int i, m, n = Kt(str, 9);
	int ii, jj, ti, tj, t;
	
	nod[n].str = str;
	nod[n].postion9 = pos;
	step[n].last = -1;
	que.push(n);
	used[n] = true;

	while (!que.empty())
	{
		n = que.front();
		que.pop();
		ii = nod[n].postion9 / 3;
		jj = nod[n].postion9 % 3;
		for (i=0; i<4; i++)
		{
			ti = ii + dir[i][0];
			tj = jj + dir[i][1];
			if (ti < 0 || ti > 2 || tj < 0 || tj > 2)
				continue;
			t = ti*3+tj;
			swap(nod[n].str[nod[n].postion9], nod[n].str[t]);
			m = Kt(nod[n].str, 9);

			if (!used[m])
			{
				used[m] = true;
				nod[m].str = nod[n].str;
				nod[m].postion9 = t;
				step[m].last = n;
				step[m].c = st[i] ;
				if (m == 0)
					return ;
				que.push(m);
			}
			swap(nod[n].str[nod[n].postion9], nod[n].str[t]);
		}
	}
}

void show(int m)
{
	if (step[m].last == -1)
		return;
	show(step[m].last);
	cout<<step[m].c;
}

int main()
{
	
	int i, n=9, m, pos;
	char c;
	string str;
	for (i=0; i<n; i++)
	{
		cin>>c;
		if (c == 'x')
		{
			pos = i;
			c = '9';
		}
		str+= c;
	}
	bfs(str, pos);
//	m = Kt(str, n);
	if (!used[0])
		cout<<"unsolvable"<<endl;
	else
		show(0);
	return 0;
}