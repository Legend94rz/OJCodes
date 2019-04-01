#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int N, M;
int pre[10003];
int x, y;
int nxt[500000], head[10003], ed[500000], tot;
int dst[10003];
int q[30010]; 
bool vis[10003];
bool dup[1003][1001];


void add(int x, int y)
{
	tot++;
	ed[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
	pre[y] = x;
}

void dij()
{
	dst[1] = 0;
	int k = 1;
	for (;;)
	{
		vis[k] = true;
		int ege = head[k];
		while (ege)
		{
			int b = ed[ege];
			if (dst[b] < 1 + dst[k])
			{
				dst[b] = 1 + dst[k];
				pre[b] = k;
			}
			ege = nxt[ege];
		}
		int maxh = 0;
		bool flag = false;
		for (int i = 1; i <= N; i++)
		{
			if (dst[i] > maxh && !vis[i])
			{
				maxh = dst[i];
				k = i;
				flag = true;
			}
		}
		if (!flag)
			break;
	}

}

int main()
{
	cin >> N >> M;
	memset(dst, 0, sizeof(dst));
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y;
		if (!dup[x][y])
			add(x, y);
		dup[x][y] = true;
	}
	dij();
	for (int i = 1; i <= N; i++)
	{
		cout << pre[i] << endl;
	}
}