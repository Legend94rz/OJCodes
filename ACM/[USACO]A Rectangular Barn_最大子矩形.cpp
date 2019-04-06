/*
ID: rz109291
PROG: rectbarn
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

bool g[3001][3001];
int R, C, P;
int lft[3001], rit[3001], top[3001];

bool isBound(int x, int y)
{
	return g[x][y] || x<1 || y<1 || x>R || y>C;
}

int main()
{
	freopen("rectbarn.in", "r", stdin); freopen("rectbarn.out", "w", stdout);
	cin >> R >> C >> P;
	for (int i = 0; i < P; i++)
	{
		int x, y;
		cin >> x >> y;
		g[x][y] = true;
	}

	for (int i = 1; i <= C; i++)
	{
		rit[i] = C;
	}
	int ans = 0;
	for (int i = 1; i <= R; i++)
	{
		int leftmost = 1;
		for (int j = 1; j <= C; j++)
		{
			if (isBound(i, j))
			{
				lft[j] = 1;
				leftmost = j + 1;
				top[j] = 0;
			}
			else
			{
				lft[j] = max(leftmost, lft[j]);
				top[j] = top[j] + 1;
			}
		}
		int ritmost = C;
		for (int j = C; j >= 1; j--)
		{
			if (isBound(i, j))
			{
				rit[j] = C;
				ritmost = j - 1;
			}
			else
				rit[j] = min(ritmost, rit[j]);

			int t = (rit[j] - lft[j] + 1)*top[j];
			if (ans < t)
				ans = t;
		}
	}
	cout << ans << endl;
	fclose(stdin); fclose(stdout);
}