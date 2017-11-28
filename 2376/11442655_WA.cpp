/*
	poj2376
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct interval
{
	int start, end;
	bool operator <(interval p)
	{
		if (this->start < p.start)
			return true;
		else if (this->start == p.start)
			return this->end > p.end;
		return false;
	}
}pt[25005];



int main()
{
	int n, len, i, j, s, d;
	
	scanf("%d%d", &n, &len);
	for (i=0; i<n; i++)
	{
		scanf("%d%d",&s,&d);
		pt[i].start = s;
		pt[i].end = d;
	}
	sort(pt, pt+n);
	/*for (i=0; i<n; i++)
	{
		printf("%d %d\n",pt[i].start, pt[i].end );
	}*/
	if (pt[0].start != 1)
		puts("-1");
	else
	{
		if (pt[0].end >= len)
		{
			puts("1");
			return 0;
		}
		int  hire=1;
		bool bl = true;
		while (bl)
		{
			int t=0;
			for (i=1; i<n; i++)
			{
				if (pt[i].start<=pt[t].end+1 && pt[i].end > pt[t].end)
					t = i;
			}
			if (t == 0)
			{
				puts("-1");
				bl = false;
			}
			hire++;
			if (pt[t].end>=len)
				break;
		}
		if (bl)
			printf("%d\n", hire);
		
	}
	return 0;
}