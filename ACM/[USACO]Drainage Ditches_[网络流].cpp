/*
ID: rz109291
PROG: ditch
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, nn, a, b, c, S, T;
int head[300], ed[600], nxt[600], e[600], h[600], vh[600];
int tot;
void add(int x, int y, int z)
{
	tot++;
	ed[tot] = y; e[tot] = z;
	nxt[tot] = head[x]; head[x] = tot;

	tot++;
	ed[tot] = x; e[tot] = 0;
	nxt[tot] = head[y]; head[y] = tot;
}
int sap(int p, int f)
{
	if (p == T)return f;
	int rest = f;
	int minh = n;


	int ege = head[p];
	while (ege != 0)
	{
		if (e[ege] > 0)
		{
			int b = ed[ege];
			if (h[b] + 1 == h[p])
			{
				int k = sap(b, min(e[ege], rest));
				rest -= k; e[ege] -= k; e[ege ^ 1] += k;
				if (h[S] >= n)
					return f - rest;
				if (rest == 0)break;
			}
			if (h[b] < minh)minh = h[b];
		}
		ege = nxt[ege];
	}
	if (rest == f)
	{
		vh[h[p]]--;
		if (vh[h[p]] == 0)h[S] = n;
		h[p] = minh + 1;
		vh[h[p]]++;
	}
	return f - rest;
}
int main()
{
	freopen("ditch.in", "r", stdin); freopen("ditch.out", "w", stdout);
	tot = 1;
	cin >> m >> n;
	S = 1; T = n;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		add(a, b, c);
	}
	vh[0] = n;
	int flow = 0;
	while (h[1] < n)
	{
		flow += sap(1, 1 << 30);
	}
	cout << flow << endl;

	fclose(stdin); fclose(stdout);
}