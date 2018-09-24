/*
ID: rz109291
PROG: bigbrn
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int f[1200][1200];
int N, T;
bool map[1200][1200];
int ans;


int main()
{
	freopen("bigbrn.in", "r", stdin); freopen("bigbrn.out", "w", stdout);
	cin >> N >> T;
	int x, y;
	for (int i = 0; i < T; i++)
	{
		cin >> x >> y;
		map[x][y] = true;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (map[i][j])
				f[i][j] = 0;
			else
				f[i][j] = min(f[i][j - 1], min(f[i - 1][j], f[i - 1][j - 1])) + 1;
			if (ans < f[i][j])
				ans = f[i][j];
		}
	}
	cout << ans << endl;
	fclose(stdin); fclose(stdout);
}



