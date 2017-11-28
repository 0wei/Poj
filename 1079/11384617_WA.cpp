#include <iostream>
using namespace std;

int n, m;
struct node
{
	int a, b;	//	a -> n, b -> m;  a/b  n/m
};

node result(int b)
{
	int l=1, r = 5000;
	while (l < r)
	{
		int a = (l + r) >>1;
		if (a * m > b * n)
			r = a;
		else
			l = a+1;
	}
	node t;
	t.a = l;
	t.b = b;
	return t;
}

bool operator <=(node p1, node p2)		//	p1 <= p2
{
	return (p1.a*p2.b <= p1.b * p2.a);
}

bool operator <(node p1, node p2)		//	p1 < p2
{
	return (p1.a*p2.b < p1.b * p2.a);
}

node operator -(node p1, node p2)
{
	node t;
	t.a = p1.a*p2.b - p2.a*p1.b;
	t.b = p1.b * p2.b;
	return t;
}

int main()
{
	node reg, err;
	int i;
	bool bl = true;
	while (cin>>n>>m)
	{
		reg.a = n;
		reg.b = m;
		err.a = 5000;
		err.b = 1;
		if (bl)
			bl = false;
		else
			cout<<endl;
		for (i=1; i<=m; i++)
		{
			node x = result(i);
			node y = x;
			y.a--;
			if ((x - reg) <= (reg - y))
				y = x;
			node tmp = y - reg;
			if (tmp.a < 0)
				tmp.a = -tmp.a;
			if (tmp < err)
			{
				err = tmp;
				cout<<y.a<<"/"<<y.b<<endl;
			}
		}
	}
	return 0;
}