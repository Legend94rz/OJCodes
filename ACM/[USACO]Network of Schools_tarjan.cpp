/*
ID: rz109291
PROG: schlnet
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
int head[500], ed[10001], nxt[10001];
int nhead[500], ned[10001], nnxt[10001];
int low[500], dfn[500], lab[500];
int ind[500], outd[500];
stack<int> st;
int vis[500];
int tot, ntot, tim, cnt, N;

void add(int x, int y)
{
	tot++;
	ed[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
void add2(int x, int y)
{
	outd[x] ++; ind[y]++;
	ntot++;
	ned[ntot] = y;
	nnxt[ntot] = nhead[x];
	nhead[x] = ntot;
}
void tarjan(int s)
{
	int j;
	vis[s] = 1;
	st.push(s);
	dfn[s] = low[s] = ++tim;
	int ege = head[s];
	while (ege != 0)
	{
		int b = ed[ege];
		if (vis[b]==0) tarjan(b);
		if (vis[b]==1) low[s] = min(low[b], low[s]);
		ege = nxt[ege];
	}
	if (dfn[s] == low[s])
	{
		cnt++;
		do
		{
			j = st.top();
			st.pop();
			vis[j] = 2;
			lab[j] = cnt;
		} while (j!=s);
	}
}


int main()
{
	freopen("schlnet.in", "r", stdin); freopen("schlnet.out", "w", stdout);
	cin >> N;
	vector<vector<int>> inp(N + 1);
	int a;
	for (int i = 1; i <= N; i++)
	{
		for (;;)
		{
			cin >> a;
			if (!a)break;
			add(i, a);
			inp[i].push_back(a);
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (vis[i] == 0)
			tarjan(i);
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < inp[i].size(); j++)
		{
			if (lab[i] != lab[inp[i][j]])
				add2(lab[i], lab[inp[i][j]]);
		}
	}
	int ansA = 0, ind0 = 0, outd0 = 0;
	for (int i = 1; i <= cnt; i++)
	{
		if (ind[i] == 0)
		{
			ansA++;
			ind0++;
		}
		if (outd[i] == 0)
			outd0++;
	}
	if (cnt == 1)
	{
		cout << 1 << endl << 0 << endl;
	}
	else
	{
		cout << ansA << endl << max(outd0, ind0) << endl;
	}
	fclose(stdin); fclose(stdout);
}
