#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int E = 300;
int n, m, Q;
int a, b, c, MC;
int head[E], ed[E], col[E], next[E];
int tot;
bool v[E];

void add(int x, int y, int z)
{
	tot++;
	col[tot] = z;ed[tot]=y;
	next[tot] = head[x];
	head[x] = tot;
}

void check(int a, int b, int c,int& p)
{
	int ege = head[a];
	v[a] = true;
	while (ege != 0)
	{
		if (col[ege] == c && !v[ed[ege]])
		{
			if(ed[ege]==b)
			{
				p++;
			}
			check(ed[ege],b,c,p);
		}
		ege = next[ege];
	}
	v[ed[ege]] = false;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c); add(b, a, c);
		if (c >= MC)MC = c;
	}
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++)
	{
		int ans = 0;
		scanf("%d%d", &a, &b);
		for (int j = 1; j <= MC; j++)
		{
			memset(v, 0, sizeof(v));
			int t=0;
			check(a,b,j,t);
			ans+=t;
		}
		printf("%d\n", ans);
	}
	//system("pause");
}