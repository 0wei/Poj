#include <stdio.h>
#include <string>
char habb[20][10] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu"};
char Tzolkin[20][10] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
int main()
{
	int t, day, year, all;
	char month[10];
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d. %s %d", &day, &month, &year);
		int i=-1;
		while (strcmp(month, habb[++i]) != 0);
		all = day+1 + year*365 + i * 20;
		printf("%d %s %d\n", (all-1)%13+1, Tzolkin[(all-1)%20], (all-1)/260);
	}
	return 0;
}