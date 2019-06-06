#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
using namespace std;

int X[1011], Y[1011], Z[1011];
short type[1011];
int R, N, H, T;
bool vis[1011];
int tot;
int head[1011], ed[1000110], nxt[1000101];
int Q[10000];

bool is_connect(int i, int j)
{
	double d = sqrt(pow(X[i] - X[j], 2) + pow(Y[i] - Y[j], 2) + pow(Z[i] - Z[j], 2));
	return d <= 2 * R;
}

void add(int x, int y)
{
	tot++;
	ed[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}

void bfs()
{
	int l = 0, r = 0;
	for (int i = 1; i <= N; i++)
	{
		if (type[i]&1)
		{
			Q[++r] = i;
			vis[i] = true;
		}
	}
	while (l != r)
	{
		int k = Q[++l];
		for (int ege = head[k]; ege; ege = nxt[ege])
		{
			int b = ed[ege];
			if (!vis[b])
			{
				Q[++r] = b;
				vis[b] = true;
			}
		}	
	}
}

int main()
{
	freopen("2017cheese.in", "r", stdin); freopen("2017cheese.out", "w", stdout);
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> H >> R;
		memset(head, 0, sizeof(head));
		memset(ed, 0, sizeof(ed));
		memset(vis, 0, sizeof(vis));
		memset(nxt, 0, sizeof(nxt));
		memset(Q, 0, sizeof(Q));
		memset(type, 0, sizeof(type));
		tot = 0;
		for (int i = 1; i <= N; i++)
		{
			cin >> X[i] >> Y[i] >> Z[i];
			if (Z[i] <= R)
				type[i] |= 1;
			if (H - Z[i] <= R)
				type[i] |= 2;
			for (int j = 1; j < i; j++)
			{
				if (is_connect(i, j))
				{
					add(i, j); add(j, i);
				}
			}
		}
		bfs();
		bool flag = false;
		for (int i = 1; i <= N; i++)
		{
			if ((type[i] & 2) && vis[i])
			{
				cout << "Yes" << endl;
				flag = true;
				break;
			}
		}
		if(!flag)
			cout << "No" << endl;
	}
	fclose(stdin); fclose(stdout);
}
