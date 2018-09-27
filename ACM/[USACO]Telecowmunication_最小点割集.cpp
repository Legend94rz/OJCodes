/*
ID: rz109291
PROG: telecow
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

int N, M, c1, c2, NN;
int head[1200], ed[5000], nxt[5000], c[5000], c_bak[5000], enab[5000];
int inner[1200];
int vh[1200], h[1200];
int tot = 1;
const int INF = 0x3f3f3f3f;


void add(int x, int y, int cap)
{
	tot++;
	ed[tot] = y; c[tot] = cap; enab[tot] = true;
	nxt[tot] = head[x];
	head[x] = tot;

	tot++;
	ed[tot] = x; c[tot] = 0; enab[tot] = true;
	nxt[tot] = head[y];
	head[y] = tot;
}

int sap(int m, int f)
{
	if (m == c2) return f;
	int rest = f;
	int minH = NN;
	for (int ege = head[m]; ege; ege = nxt[ege])
	{
		if (c[ege]==0 || !enab[ege])continue;
		int b = ed[ege];
		if (h[b] + 1 == h[m])
		{
			int t = sap(b, min(c[ege], rest));
			c[ege] -= t; c[ege ^ 1] += t;
			rest -= t;
			if (rest == 0)break;
			if (h[c1] >= NN)break;
		}
		minH = min(minH, h[b]);
	}
	if (rest == f)
	{
		vh[h[m]]--;
		if (vh[h[m]] == 0)h[c1] = NN;
		h[m] = minH+1;
		vh[h[m]]++;
	}
	return f - rest;
}

int main()
{
	freopen("telecow.in", "r", stdin); freopen("telecow.out", "w", stdout);
	cin >> N >> M >> c1 >> c2;
	int x, y;

	for (int i = 1; i <= N; i++)
	{
		inner[i] = tot + 1; add(i, i + N, 1);
	}

	for (int i = 0; i < M; i++)
	{
		cin >> x >> y;
		add(x + N, y, INF); add(y + N, x, INF);
	}
	memcpy(c_bak, c, sizeof(c));
	NN = 2 * N;
	vh[0] = NN;
	int flow = 0;
	while (h[c1+N] < NN)flow += sap(c1+N, INF);

	int ans[1500];
	int L = 0;
	for (int i = 1; i <= N; i++)
	{
		if (i == c1 || i == c2)continue;
		memcpy(c, c_bak, sizeof(c));
		memset(vh, 0, sizeof(vh));
		memset(h, 0, sizeof(h));
		enab[inner[i]] = false;
		vh[0] = NN;
		int t = 0;
		while (h[c1+N] < NN)
			t += sap(c1+N, INF);
		if (t + 1 == flow - L)
			ans[L++] = i;
		else
			enab[inner[i]] = true;
	}
	cout << flow << endl;
	for (int i = 0; i < L; i++)
	{
		cout << ans[i];
		if (i != L - 1)cout << ' '; else cout << endl;
	}
	fclose(stdin); fclose(stdout);
}