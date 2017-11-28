//http://poj.org/problem?id=1077
#include <iostream>
#include <queue>
#include <vector>
#include <iterator>
#include <string>
using namespace std;

const int MAXX_SIZE = 362885;

int fac[] = {1,1,2,6,24,120,720,5040,40320};

struct Nod
{
	string str;	//数组
	int postion9;  //可交换的位置
}nod[MAXX_SIZE];

struct Step
{
	int srt;
	char c;		//l0, r1, u2, d3

}step[MAXX_SIZE];

int dir[][2] = {1,0, -1,0, 0,1, 0,-1 };

char st[] = {'u', 'd', 'l', 'r'};

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

void Show(int n)
{
	while (step[n].srt != -1)
	{
		cout/*<<"当前点:"<<nod[n].str<<" "*/<<step[n].c/*<<" 之后: "<<nod[step[n].srt].str<<endl*/;
		n = step[n].srt;
	}
	cout<<endl;
}

void bfs()
{
	queue<int>que;
	bool used[MAXX_SIZE];
	string str = "123456789";
	int i, m, n = Kt(str, 9);
	int ii, jj, ti, tj, t;
	bool flag;
	nod[n].str = str;
	nod[n].postion9 = 8;
	step[n].srt = -1;
	que.push(n);
	used[n] = false;

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
			flag = false;
			if (used[m])
			{
				used[m] = false;
				nod[m].str = nod[n].str;
				nod[m].postion9 = t;
				step[m].srt = n;
				step[m].c = st[i];
				que.push(m);
				flag = true;
			}
			swap(nod[n].str[nod[n].postion9], nod[n].str[t]);
		/*	if (flag)
			{
				cout<<nod[m].str<<":"<<endl;
				Show(m);
				cout<<endl;
			}*/
		}
	}
}



int main()
{
	bfs();
	int i, n=9, m;
	char c;
	string str;
	for (i=0; i<n; i++)
	{
		cin>>c;
		str+= c == 'x' ? '9' : c;
	}
	m = Kt(str, n);
	if (step[m].srt == 0)
		cout<<"unsolvable"<<endl;
	else 
		Show(m);
	return 0;
}