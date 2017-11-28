#include <iostream>
using namespace std;
bool flg, newflg;
int num;
struct node
{
	int count;
	node *next[10];
}a[1000005];

void insert(char *s, node *rt)
{
	node *p = rt;
	int i=0, index;
	int len = strlen(s);
	newflg = false;
	while (s[i])
	{
		index = s[i] - '0';
		if (p->next[index] == NULL)
		{
			newflg = true;
			p->next[index] = &a[num++];
			p->next[index]->count = 0;
			memset(p->next[index], NULL, sizeof(p->next[index]));
		}
	
		if (p->next[index]->count == 1)
		{
			flg = false;
			return;
		}
		p = p->next[index];
		i++;
	}
	p->count = 1;
}

int main()
{
	int t, n;
	char str[1000];
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		num = 0;
		node *root = new node;
		root->count = 0;
		memset(root->next, NULL, sizeof(root->next));
		getchar();
		flg = true;
		newflg = true;
		while (n--)
		{
			scanf("%s", &str);
			if (flg && newflg)
				insert(str, root);
		}
		if (flg && newflg)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}