#include<stdio.h>
#include<string.h>
typedef struct Node{
	struct Node *next[15];
	int count;
}node;
node a[1000005];
int newflg,flg;
int num;
void Insert(char *str,node *root)
{ 
    int i=0,index; 
	node *p = root;
	newflg = false;
    while(str[i])
	{ 
        index=str[i]-'0'; 
        if(p->next[index] == NULL)
		{
			newflg = true;
			p->next[index] = &a[num++];
			p->next[index]->count=0;
			memset(p->next[index]->next,NULL,sizeof(p->next[index]->next));
		}
        if(p->next[index]->count == 1)
		{
			flg = false;
			return ;
		}
		p = p->next[index];
        i++;
	} 
	p->count = 1;
}
int main()
{
	int i;
	int ncase;
	scanf("%d",&ncase);
	while(ncase--)
	{
		int n;
		char str[11];
	    num =0;
		node *root =  &a[num++];
		root->count=0;
        memset(root->next,NULL,sizeof(root->next));
		scanf("%d",&n);
		getchar();
		newflg = true;
		flg = true;
		for(i=1;i<=n;i++)
		{
			gets(str);
			if (newflg && flg)
			Insert(str,root);
		}
		if(newflg && flg)
			printf("YES\n");
		else 
			printf("NO\n");
	}
	return 0;
}