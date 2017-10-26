/*
ID: rz109291
PROG: milk6
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct A
{
	int no;
	int c;
	bool flag;
};
int N, M, S, T;
int head[100], ed[2010], nxt[2010], e[2010], C[2010];
int h[100], vh[100];
int tot;
vector<A> q;
bool cmp(const A& a, const A& b)
{
	if (a.c > b.c)return true;
	if (a.c == b.c && a.no < b.no)return true;
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
int cmp2(const void* a, const void* b)
{
	return *(const int*)a - *(const int*)b;
}
int main()
{
	/*
	----- our output ---------
	39_21
	22
	24
	42
	54
	58
	65
	68
	71
	77
	92
	93
	97
	100
	103
	105
	117
	152
	163
	166
	169
	170
	---- your output ---------
	39_13
	22
	24
	65
	66
	71
	92
	97
	115
	124
	152
	167
	169
	170
	--------------------------

	10 200
	5 10 3
	3 10 5
	2 5 1
	4 10 1
	3 8 1
	3 8 1
	2 10 1
	4 6 1
	4 6 1
	2 5 3
	3 5 1
	4 10 1
	5 10 1
	1 7 2
	4 6 1
	4 10 1
	2 10 1
	5 10 3
	3 6 1
	3 10 1
	3 5 1
	1 10 2
	3 10 4
	1 10 1
	2 9 1
	2 7 1
	4 10 2
	4 10 1
	5 6 1
	2 7 1
	5 6 1
	3 6 1
	5 10 1
	1 9 3
	5 7 2
	5 9 1
	3 4 1
	5 10 1
	4 10 1
	4 10 1
	2 8 1
	1 3 1
	4 6 1
	2 5 4
	4 7 1
	5 8 1
	3 10 1
	4 10 3
	4 6 2
	4 10 1
	2 4 3
	5 8 1
	4 5 1
	1 5 1
	3 4 5
	4 10 4
	3 8 3
	1 3 1
	4 10 1
	4 10 1
	3 10 1
	5 10 1
	3 8 3
	1 7 2
	1 10 3
	2 10 3
	5 7 1
	1 5 1
	4 10 1
	3 10 1
	1 2 3
	5 10 4
	5 9 1
	5 10 4
	2 8 3
	4 10 1
	1 10 1
	5 10 4
	5 10 4
	4 5 1
	2 5 2
	4 6 4
	5 10 2
	3 10 1
	4 5 3
	5 10 2
	5 10 4
	5 10 2
	2 6 1
	5 7 1
	5 9 3
	1 2 2
	1 10 1
	3 8 1
	2 4 1
	4 5 1
	1 10 5
	2 10 1
	3 5 4
	1 2 1
	5 10 1
	5 10 1
	1 2 1
	1 7 2
	1 10 1
	5 10 2
	3 10 5
	4 5 1
	3 8 4
	4 10 4
	1 7 3
	4 10 1
	3 9 2
	1 9 1
	2 10 3
	4 10 2
	1 3 1
	2 10 1
	2 7 3
	3 6 1
	5 8 2
	5 6 1
	1 7 4
	2 10 3
	5 6 1
	2 9 1
	2 9 1
	5 10 1
	4 7 2
	5 10 2
	4 10 1
	1 9 1
	5 10 4
	3 4 1
	3 10 1
	3 5 1
	1 6 4
	5 10 3
	3 5 3
	4 5 5
	1 9 1
	4 10 1
	2 10 1
	4 7 1
	3 10 2
	3 7 1
	1 6 1
	2 6 4
	3 10 1
	5 10 1
	1 7 1
	1 4 2
	5 10 1
	2 5 2
	5 10 1
	2 5 5
	5 9 1
	5 10 4
	2 4 1
	5 6 3
	4 7 1
	5 10 4
	1 4 1
	1 8 1
	1 7 1
	1 10 1
	2 10 3
	1 8 1
	1 2 4
	1 2 5
	3 10 4
	3 9 1
	4 10 3
	3 10 1
	4 10 3
	3 4 1
	3 8 1
	5 10 1
	1 8 1
	2 9 1
	3 4 2
	1 7 1
	5 7 1
	1 9 2
	5 9 5
	2 10 1
	4 8 1
	4 7 5
	3 7 1
	2 8 1
	5 7 1
	2 4 3
	2 3 2
	5 7 1
	2 3 2
	4 9 3
	5 7 4
	4 10 1
	5 10 1
	5 10 1
	*/
	freopen("milk6.in", "r", stdin); freopen("milk6.out", "w", stdout);
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
	int tmp=0,l=0,edges[1001];
	for (int i = 2; i < tot; i+=2)
	{
		A a;
		a.c = e[i ^ 1];
		a.no = i/2;
		q.push_back(a);
	}
	sort(q.begin(), q.end(), cmp);
	for (size_t i = 0; i < q.size(); i++)
	{
		if (tmp + q[i].c <= ans && q[i].c>0)
		{
			tmp += q[i].c;
			edges[l++] = q[i].no;
		}
		if (tmp == ans)break;
	}
	qsort(edges, l, sizeof(int), cmp2);
	cout << ans << ' ' << l << endl;
	if (l > 0)
	{
		for (int i = 0; i < l; i++)
		{
			cout<<edges[i] << endl;
		}
	}
	fclose(stdin); fclose(stdout);
}
