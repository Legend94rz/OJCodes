#define N 50001
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int f[3*N], Next[3*N], Prev[3*N];
int n, k;
int d, x, y;
int ans;
int getf(int x)
{
	int c = x, t;
	while (x != f[x])x = f[x];
	while (c != x)
	{
		t = f[c];
		f[c] = x;
		c = t;
	}
	return x;
}
void join(int a, int b)
{
	int x = getf(a);
	int y = getf(b);
	f[x] = y;
}
bool judge(int a, int b)
{
	return getf(a) == getf(b);
}
void init()
{
	for(int i=0;i<=n;i++)
	{
		int n=i+N;
		int p=i+2*N;
		f[i] = i;
		f[n] = n;
		f[p] = p;
		Next[i] = n;
		Next[n] = p;
		Next[p] = i;
		Prev[i] = p;
		Prev[n] = i;
		Prev[p] = n;
	}
}
int main()
{
	scanf("%d%d", &n, &k);
	init();
	for (int i = 0; i < k; i++)
	{
		scanf("%d%d%d", &d, &x, &y);
		if (x == y && d == 2 || x > n || y > n) { ans++; continue; }
		if (d == 1)
		{
			if (judge(Next[x], y) || judge(Next[y], x))
			{
				ans++; continue;
			}
			join(x, y);
			join(Prev[x], Prev[y]);
			join(Next[x], Next[y]);
		}
		else
		{
			if (judge(x, y) || judge(Next[y], x))
			{
				ans++; continue;
			}
			join(Next[x], y);
			join(Prev[y], x);
			join(Next[y], Prev[x]);
		}
	}
	printf("%d\n", ans);
	//system("pause");
}
