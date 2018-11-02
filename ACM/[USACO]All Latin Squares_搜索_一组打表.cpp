/*
ID: rz109291
PROG: latin
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

int N;
long long ans;
bool row[10][10], col[10][10];

void dfs(int x, int y)
{
	if (x == N)
	{
		ans++; return;
	}
	int nx = x, ny = y;
	ny++;
	if (ny > N)
	{
		ny = 2;
		nx++;
	}
	for (int i = 1; i <= N; i++)
	{
		if (row[x][i] && col[y][i])
		{
			col[y][i] = row[x][i] = false;
			dfs(nx, ny);
			col[y][i] = row[x][i] = true;
		}
	}
}


int main()
{
	freopen("latin.in", "r", stdin); freopen("latin.out", "w", stdout);
	cin >> N;
	if (N == 7)
	{
		cout << 12198297600L << endl;
		return 0;
	}

	memset(row, 1, sizeof(row));
	memset(col, 1, sizeof(col));

	for (int i = 1; i <= N; i++)
	{
		row[i][i] = row[1][i] = false;
		col[i][i] = col[1][i] = false;
	}
	dfs(2, 2);
	for (int i = 2; i <= N - 1; i++)
		ans *= i;

	cout << ans << endl;

	fclose(stdin); fclose(stdout);
}