/*根据面积公式，Area=1/2*abs((x0*y1-x1*y0)+(x1*y2-x2*y1)...+(xn*yn-1-xn-1*yn)+(xn*y0-x0*yn)) 
把相邻两点和原点组成一个三角形，而总面积是这n个三角形面积的和，而三角形面积是两个相邻边向量的叉积*/


#include <iostream>

using namespace std;

int dx[] = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, 0, 0, -1, -1, -1};

__int64 area;
char cstr[1000005];

int main()
{
	int t;
	string str;
	int x, y, tx, ty;
	int i;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", &cstr);
		int len = strlen(cstr); 
		if (len < 3)
		{
			printf("0\n");
			continue;
		}
		x = y = 0;
		area = 0;

		for (i = 0; i < len-1; i++)
		{
			tx = x + dx[cstr[i]-'0'];
			ty = y + dy[cstr[i]-'0'];
			area += tx*y - ty*x;
			x = tx;
			y = ty;
		}
		if (area < 0) area = -area;
		if (area % 2 == 0)
			printf("%I64d\n",area/2); 
		else
			printf("%I64d.5\n",area/2); 
	}
	return 0;
}