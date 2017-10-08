/*
ID: rz109291
LANG: C++
PROG: fence6
*/
#include <iostream>
#include <set>
#include <vector>
#include <cstdio>
#include <string.h>

using namespace std;
struct Edge
{
	int node[2];
	vector<int> neighboor[2];
	int e;
};
int n, m;
Edge edge[1000];
bool vis[1000];
int ans = 0x3f3f3f3f;
int head[300], ed[1000], e[1000], nxt[1000];
int tot;
void add(int x, int y, int z)
{
	tot++;
	ed[tot] = y; e[tot] = z;
	nxt[tot] = head[x]; head[x] = tot;
}
bool find(vector<int>& v, int x)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i] == x)
			return true;
	}
	return false;
}

void sure()
{
	for (size_t i = 1; i <= m; i++)
	{
		for (size_t k = 0; k < 2; k++)
		{
			if (edge[i].node[k] == 0)
			{
				edge[i].node[k] = ++n;
				for (size_t j = 0; j < edge[i].neighboor[k].size(); j++)
				{
					int p = edge[i].neighboor[k][j];
					if (edge[p].node[0] == 0 && find(edge[p].neighboor[0], i))
						edge[p].node[0] = n;
					if (edge[p].node[1] == 0 && find(edge[p].neighboor[1], i))
						edge[p].node[1] = n;
				}
			}
		}
	}
}
void dfs(int s, int len, int ori, int count)
{
	int ege = head[s];
	vis[s] = true;
	while (ege)
	{
		int b = ed[ege];
		if (!vis[b])
		{
			if (len + e[ege] < ans)
				dfs(b, len + e[ege], ori, count + 1);
		}
		else if (b == ori && len + e[ege] < ans && count >= 2)
		{
			ans = len + e[ege];
		}
		ege = nxt[ege];
	}
	vis[s] = false;
}
int main()
{
	freopen("fence6.in", "r", stdin); freopen("fence6.out", "w", stdout);
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c[2], x;
		cin >> a >> b >> c[0] >> c[1];
		edge[a].e = b;
		for (size_t k = 0; k < 2; k++)
		{
			for (size_t j = 0; j < c[k]; j++)
			{
				cin >> x;
				edge[a].neighboor[k].push_back(x);
			}
		}
	}
	sure();
	for (int i = 1; i <= m; i++)
	{
		add(edge[i].node[0], edge[i].node[1], edge[i].e);
		add(edge[i].node[1], edge[i].node[0], edge[i].e);
	}
	ans = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++)
	{
		memset(vis, 0, sizeof(vis));
		dfs(i, 0, i, 0);
	}
	cout << ans << endl;
	fclose(stdin); fclose(stdout);
}