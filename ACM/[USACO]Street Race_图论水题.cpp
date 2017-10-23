/*
ID: rz109291
PROG: race3
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int head[1000], ed[100001], nxt[10000];
int tot, S, T;
bool isUnavoid[200], isSplit[200], vis[200], tmp[200];
int N;
void add(int x, int y)
{
	tot++;
	ed[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}

bool dfs(int s, int p)
{
	if (s == T)
		return false;
	vis[s] = true;
	int ege = head[s];
	while (ege)
	{
		int b = ed[ege];
		if (!vis[b] && b != p)
		{
			if (!dfs(b, p))
				return false;
		}
		ege = nxt[ege];
	}
	return true;
}
void search(int s, int t)
{
	if (s == t)return;
	int ege = head[s];
	vis[s] = true;
	while (ege)
	{
		int b = ed[ege];
		if (!vis[b])
			search(b, t);
		ege = nxt[ege];
	}
}
int main()
{
	freopen("race3.in", "r", stdin);freopen("race3.out", "w", stdout);
	N = 0;
	for (;;)
	{
		int x;
		for (;;)
		{
			cin >> x;
			if (x < 0)
				break;
			add(N, x);
		}
		if (x == -1)
			break;
		N++;
	}
	S = 0; T = N - 1;
	int c1 = 0, c2 = 0;
	for (int i = 1; i < N - 1; i++)
	{
		memset(vis, 0, sizeof(vis));
		isUnavoid[i] = dfs(0, i);
		if (isUnavoid[i])
			c1++;
	}
	for (int i = 1; i < N-1; i++)
	{
		if (isUnavoid[i])
		{
			memset(vis, 0, sizeof(vis));
			search(0, i);
			memcpy(tmp, vis, sizeof(vis));
			memset(vis, 0, sizeof(vis));
			search(i, T);
			
			bool flag = false;
			for (int j = 0; j < N; j++)
			{
				if (vis[j] == tmp[j] && vis[j] && j != i)
				{
					isSplit[i] = false;
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				isSplit[i] = true;
				c2++;
			}
		}
	}
	cout << c1;
	for (int i = 0; i < N; i++)
	{
		if (isUnavoid[i])
			cout<<' ' << i;
	}cout << endl;
	cout << c2;
	for (int i = 0; i < N; i++)
	{
		if (isSplit[i])
			cout << ' ' << i ;
	}cout << endl;

	fclose(stdin); fclose(stdout);
}