/*
ID: rz109291
PROG: tour
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <memory.h>
#include <map>
using namespace std;

map<string, int> str2ind;
map<int, string> ind2str;
int N, V;
bool g[200][200];
int outd[200];
int f[200][200];

const int INF = 10000;

int main()
{
	freopen("tour.in", "r", stdin); freopen("tour.out", "w", stdout);
	cin >> N >> V;
	string a, b;
	int ai, bi;
	for (size_t i = 0; i < N; i++)
	{
		cin >> a;
		str2ind[a] = i + 1;
		ind2str[i + 1] = a;
	}
	for (size_t i = 0; i < V; i++)
	{
		cin >> a >> b;
		ai = str2ind[a];
		bi = str2ind[b];
		g[bi][ai] = g[ai][bi] = true;
		outd[ai]++;
	}
	f[1][1] = 1;
	for (int i = 1; i <= N; i++)
	{
		for (int j = i+1; j <= N; j++)
		{
			for (int k = 1; k < j; k++)
			{
				if (g[k][j] && f[i][k])
				{
					f[i][j] = max(f[i][j], f[i][k] + 1);
				}
				f[j][i] = f[i][j];
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		if (g[i][N])
		{
			ans = max(ans, f[i][N]);
		}
	}
	if (ans == 0)
		cout << 1 << endl;
	else
		cout << ans << endl;
	fclose(stdin); fclose(stdout);
}