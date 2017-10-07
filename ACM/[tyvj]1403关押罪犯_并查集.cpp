#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct Edge
{
	int a, b, e;
};
int n, m;
Edge g[100001];
int f[20001];
int opp[20001];
int comparer(const void* a, const void* b)
{
	const Edge* A = (const Edge*)a;
	const Edge* B = (const Edge*)b;
	if (A->e < B->e)return 1;
	if (A->e > B->e)return -1;
	return 0;
}
int getf(int x)
{
	int c = x, t;
	while (x != f[x])x = f[x];
	while (f[c] != x)
	{
		t = f[c];
		f[c] = x;
		c = t;
	}
	return x;
}
void join(int a, int b)
{
	int x = getf(b);
	int y = getf(a);
	f[y] = x;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i++)f[i] = i;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &g[i].a, &g[i].b, &g[i].e);
	}
	qsort(g, m, sizeof(Edge), comparer);
	int ans=0;
	for (int i = 0; i < m; i++)
	{
		int x = getf(g[i].a);
		int y = getf(g[i].b);
		if(x==y)
		{
			ans = g[i].e;
			break;
		}
		else
		{
			if (!opp[g[i].a] && !opp[g[i].b])
			{
				opp[g[i].a] = g[i].b;
				opp[g[i].b] = g[i].a;
			}
			else if (!opp[g[i].a])
			{
				join(g[i].a, opp[g[i].b]);
				opp[g[i].a] = g[i].b;
			}
			else if (!opp[g[i].b])
			{
				join(g[i].b, opp[g[i].a]);
				opp[g[i].b] = g[i].a;
			}
			else
			{
				join(g[i].b, opp[g[i].a]);
				join(g[i].a, opp[g[i].b]);
			}
		}

	}
	printf("%d\n", ans);
	//system("pause");
}