#include <stdio.h>
#include <string.h>

typedef char phrases[70];

int main()
{
	phrases ph[1005];
	int cnt[1005], t=0;
	char str[100];
	int M, N, i, j, k;
	int len;
	scanf("%d%d", &M, &N);
	getchar();
	for (i=0; i<M; i++)
		gets(ph[i]);
	for (k=0; k<N; k++)
	{
		gets(str);
		len = strlen(str);
		memset(cnt, 0, sizeof(cnt));

		for (i=0; i<len; i++)
		{
			for (j=0; j<M; j++)
				if (str[i] == ph[j][i])
					cnt[j]++;

		}
		for (i=0; i<M; i++)
			if (cnt[i] == len)
				t++;
		
	}
	printf("%d\n", t);
	return 0;
}