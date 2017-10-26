/*
ID: rz109291
PROG: milk6
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int N, M, S, T;
int head[100], ed[2010], nxt[2010], e[2010], C[2010];
int h[100], vh[100];
int tot;
void add(int x, int y, int z)
{
	tot++;
	ed[tot] = y; C[tot] = e[tot] = z;
	nxt[tot] = head[x];
	head[x] = tot;

	tot++;
	ed[tot] = x; C[tot] = e[tot] = 0;
	nxt[tot] = head[y];
	head[y] = tot;
}
int sap(int m, int f)
{
	if (m == T)return f;
	int rest = f;
	int minh = N;

	int ege = head[m];
	while (ege)
	{
		if (e[ege] > 0)
		{
			int b = ed[ege];
			if (h[b] + 1 == h[m])
			{
				int k = sap(b, min(rest, e[ege]));
				e[ege] -= k; e[ege ^ 1] += k; rest -= k;
				if (h[S] >= N) return f - rest;
				if (rest == 0)break;
			}
			if (h[b] < minh)
				minh = h[b];
		}
		ege = nxt[ege];
	}
	if (f == rest)
	{
		vh[h[m]]--;
		if (vh[h[m]] == 0)h[S] = N;
		h[m]=minh+1;
		vh[h[m]] ++;
	}
	return f - rest;
}
int main()
{
	//freopen("milk6.in", "r", stdin); freopen("milk6.out", "w", stdout);
	cin >> N >> M;
	tot = 1;
	vh[0] = N;
	S = 1; T = N;

	int a, b, c;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		add(a, b, c);
	}
	int ans = 0;
	while (h[S] < N)
	{
		ans += sap(S, 1 << 30);
	}
	int edges[1000];
	int l = 0,tmp=0;
	for (int i = 2; i < tot; i+=2)
	{
		if (0 == e[i])
		{
			edges[l++] = i / 2;
			tmp += C[tot];
			if (tmp == ans)
				break;
		}
	}
	cout << ans << ' ' << l << endl << edges[0];
	for (int i = 1; i < l; i++)
	{
		cout<<' ' << edges[i];
	}cout << endl;

	fclose(stdin); fclose(stdout);
}
