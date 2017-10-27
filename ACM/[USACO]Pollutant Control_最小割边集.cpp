/*
ID: rz109291
PROG: milk6
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
struct A
{
	int no, C;
};
int N, M, S, T;
int head[100], ed[2010], nxt[2010], e[2010], C[2010];
bool removed[2010];
int h[100], vh[100];
int tot;
vector<A> q;
vector<int> Vex;
bool cmp(const A& a, const A& b)
{
	if (b.C < a.C)
		return true;
	else if (b.C == a.C && a.no < b.no)
		return true;
	return false;
}
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
		if (e[ege] > 0 && !removed[ege])
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
	freopen("milk6.in", "r", stdin); freopen("milk6.out", "w", stdout);
	cin >> N >> M;
	tot = 1;
	memset(vh, 0, sizeof(vh));
	memset(h, 0, sizeof(h));
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
	cout << ans;
	for (int i = 2; i < tot; i+=2)
	{
		A x;
		x.C = C[i];
		x.no = i / 2;
		q.push_back(x);
	}
	sort(q.begin(), q.end(), cmp);
	for (size_t i = 0; i < q.size(); i++)
	{
		removed[q[i].no * 2] = true;
		int tmp = 0;
		memset(vh, 0, sizeof(vh));
		memset(h, 0, sizeof(h));
		memcpy(e, C, sizeof(C));
		vh[0] = N;
		while (h[S] < N)
			tmp += sap(S, 1 << 30);
		if (tmp + C[q[i].no * 2] == ans)	//todo : e[q[i].no*2]==0?
		{
			Vex.push_back(q[i].no);
			ans -= C[q[i].no * 2];
		}
		else
			removed[q[i].no * 2] = false;
	}
	sort(Vex.begin(), Vex.end());

	cout<<' ' << Vex.size() << endl;
	for (int i = 0; i < Vex.size(); i++)
	{
		cout<< Vex[i] << endl;
	}
	fclose(stdin); fclose(stdout);
}
