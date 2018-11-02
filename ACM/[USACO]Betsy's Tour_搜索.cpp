/*
ID: rz109291
PROG: betsy
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

bool vs[10][10];
int N;
int ans;
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, -1, 0, 1 };

bool dead(int x, int y)
{
	return (vs[x - 1][y] && vs[x + 1][y] && !vs[x][y - 1] && !vs[x][y + 1])
		|| (!vs[x - 1][y] && !vs[x + 1][y] && vs[x][y - 1] && vs[x][y + 1]);
}

int cntfree(int x, int y)
{
	int n = 0;
	for (int i = 0; i < 4; i++)
	{
		int tx = x + dx[i], ty = y + dy[i];
		if (!vs[tx][ty])
			n++;
	}
	return n;
}

void dfs(int x, int y, int d)
{
	if (x == N && y == 1 && d == N * N)
	{
		ans++;
		return;
	}
	vs[x][y] = true; 
	int nfree = 0, nnes = 0, nx, ny;
	for (int i = 0; i < 4; i++)
	{
		int tx = x + dx[i], ty = y + dy[i], t=0;
		if (!vs[tx][ty] && !(tx==N && ty==1))
			t = cntfree(tx, ty);
		if (t == 1)
		{
			nx = tx; ny = ty;
			nnes++;
			nfree += t;
		}
	}
	if (nnes == 1)
		dfs(nx, ny, d + 1);
	else if (nnes == 0)
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i], ty = y + dy[i];
			if (tx == N && ty == 1 && d != N * N - 1) continue;
			if (!vs[tx][ty] && !dead(tx, ty))
			{
				dfs(tx, ty, d + 1);
			}
		}
	vs[x][y] = false;
}

int main()
{
	freopen("betsy.in", "r", stdin); freopen("betsy.out", "w", stdout);
	cin >> N;
	for (int i = 0; i <= N + 1; i++)
	{
		vs[N + 1][i] = vs[0][i] = true;
		vs[i][0] = vs[i][N + 1] = true;
	}
	dfs(1, 1, 1);
	cout << ans << endl;
	fclose(stdin); fclose(stdout);
}
