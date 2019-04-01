#include <iostream>
#include <algorithm>
using namespace std;
int tot, nxt[120000], head[120000], ed[120000];
int N,x;
int f;
bool c[120000];


void add(int x, int y)
{
	tot++;
	ed[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}

int dfs(int r)
{
	int s = 1;
	int max_sub = 0;
	for (int ege = head[r]; ege; ege = nxt[ege])
	{
		int t = dfs(ed[ege]);
		if (t > max_sub)
			max_sub = t;
		s += t;
	}
	if (max(max_sub, N - s) <= N / 2)
	{
		c[r] = true;
		f++;
	}
	return s;
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> x;
		add(x, i);
	}
	dfs(0);
	cout << f << endl;
	for (int i = 1; i <= N; i++)
	{
		if (c[i])
			cout << i << endl;
	}
}
