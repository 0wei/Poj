#include <iostream> 
#include <string> 
#include <algorithm> 
using namespace std; 
#define MAXN 10000003 
int n, cn[MAXN], len; 
char s[100]; 
int main() 
{ 
	int i, t, ans,a[200]; 
	a['A'] = a['B'] = a['C'] = 2;
	a['D'] = a['E'] = a['F'] = 3;
	a['G'] = a['H'] = a['I'] = 4;
	a['J'] = a['K'] = a['L'] = 5;
	a['M'] = a['N'] = a['O'] = 6;
	a['P'] = a['R'] = a['S'] = 7;
	a['T'] = a['U'] = a['V'] = 8;
	a['W'] = a['X'] = a['Y'] = 9;
	while(cin>>n)
	{
		while (n--) 
		{ 
			scanf("%s", s); 
			len = strlen(s); 
			ans = 0; 
			for (i=0; i<len; i++) 
			{ 
				if (s[i]>='0'&&s[i]<='9') t = s[i]-'0'; 
				else if (s[i]>='A'&&s[i]<='Z') t = a[s[i]]; 
				else t =-1; 
				if (t != -1) ans *= 10, ans += t; 
			} 
			cn[ans]++; 
		} 
		int sign = 0; 
		for (i=0; i<MAXN; i++) 
		{ 
			if (cn[i] > 1) 
			{ 
				printf("%03d-%04d %d\n", i/10000, i%10000, cn[i]); 
				sign = 1; 
			} 
		} 
		if (sign == 0) 
			printf("No duplicates.\n"); 
	}
	return 0; 
}
