#include <iostream> 
#include <string> 
#include <algorithm> 
using namespace std; 
#define MAXN 10000003 
int n, cn[MAXN], len; 
char a[100]; 
int main() 
{ 
	int i, t, ans; 
	cin>>n; 
	while (n--) 
	{ 
		scanf("%s", a); 
		len = strlen(a); 
		ans = 0; 
		for (i=0; i<len; i++) 
		{ 
			if (a[i]>='0'&&a[i]<='9') t = a[i]-'0'; 
			else if (a[i]>='A'&&a[i]<='Z') t = a[i]-'A'; 
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
	return 0; 
}