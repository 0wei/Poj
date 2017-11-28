#include <stdio.h>
#include <memory>

const int MAX = 1000008;
char instr[MAX], str[MAX<<1];
int nRad[MAX<<1];

int maxRad;

int Mmin(int a, int b)
{
	return a > b ? b : a;
}

void Manacher()
{
	int i, j, maxx;
	int n = strlen(instr);
	memset(str, '#', sizeof(str));
	for (i=0; i<n; i++)
	{
		str[(i+1)<<1] = instr[i];
	}
	n = (n+1)<<1;
	str[n] = '$';
	
	maxRad = j = maxx = 0;
	for (i=0; i<n; i++)
	{
		if (i < maxx)
		{
			nRad[i] = Mmin(nRad[2*j - i] , maxx-i);
		}
		else nRad[i] = 1;
		
		while (str[i - nRad[i]] == str[i + nRad[i]])
		{
			nRad[i]++;
		}

		if (maxRad < nRad[i])
		{
			maxRad = nRad[i];
		}

		if (nRad[i] + i > maxx)
		{
			j = i; 
			maxx = nRad[i] + i;
		}
	}
}


int main()
{
	int t=1;
	while (scanf("%s", &instr) !=EOF && instr[0] != 'E')
	{
		Manacher();
		printf("Case %d: %d\n", t++, maxRad-1);
	}
}