/*
ID: rz109291
PROG: stall4
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
const int inf = 1 << 30;
using namespace std;
int tot, N, M, head[3000], ed[80000], e[80000], nxt[80000],S,T,NN;
int vh[3000], h[3000];
int a, b;
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
	int minh = NN;
	int ege = head[p];
	while (ege)
	{
		if (e[ege] > 0)
		{
			int b = ed[ege];
			if (h[b] + 1 == h[p])
			{
				int k = sap(b, min(rest, e[ege]));
				rest -= k; e[ege] -= k; e[ege ^ 1] += k;
				if (h[S] >= NN)return f - rest;
			}
			if (h[b] < minh)minh = h[b];
			if (rest == 0)break;
		}
		ege = nxt[ege];
	}
	if (rest == f)
	{
		vh[h[p]]--;
		if (vh[h[p]] == 0)h[S] = NN;
		h[p] = minh + 1;
		vh[h[p]]++;
	}
	return f - rest;
}

int main()
{
	freopen("stall4.in", "r", stdin); freopen("stall4.out", "w", stdout);
	cin >> N >> M;
	S = 0; T = N + M + 1; NN = 2 + N + M;
	vh[0] = NN;
	tot = 1;
	for (int i = 1; i <= N; i++)
	{
		cin >> a;
		for (int j = 0; j < a; j++)
		{
			cin >> b;
			add(i, b + N, 1);
		}
	}
	for (int i = 1; i <= N; i++)
	{
		add(S, i, 1);
	}
	for (int i = 1; i <= M; i++)
	{
		add(i + N, T, 1);
	}

	int flow = 0;
	while (h[S]<NN)
	{
		flow += sap(S, inf);
	}
	cout << flow << endl;

	fclose(stdin); fclose(stdout);
}