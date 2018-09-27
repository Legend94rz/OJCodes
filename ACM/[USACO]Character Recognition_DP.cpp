/*
ID: rz109291
PROG: charrec
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <fstream>
#include <memory.h>
using namespace std;

bool font[540][30];
int fontLine;
int N;
bool inp[1500][30];

int f[1500];
int prefi[1500];
int prefk[1500];
int cost[1500][25][30];
int diff[1500][25][30];

int Diff(int i, int j, int k)
{
	int cnt = 0;
	for (int t = 1; t <= 20; t++)
	{
		if (font[k * 20 + j + 1][t] != inp[i][t])
			cnt++;
	}
	return cnt;
}

int Cost(int i, int k, int ki, int L)
{
	int c = 0;
	for (int t = 0; t < L; t++)
	{
		c += diff[i + t][ki + t][k];
	}
	return c;
}


int main()
{
	string S = " abcdefghijklmnopqrstuvwxyz";
	ifstream fin("font.in");
	fin >> fontLine;
	string s;
	for (size_t i = 1; i <= fontLine; i++)
	{
		fin >> s;
		for (int j = 1; j <= s.length(); j++)
		{
			font[i][j] = (s[j-1] == '1');
		}
	}

	freopen("charrec.in", "r", stdin); freopen("charrec.out", "w", stdout);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> s;
		for (size_t j = 1; j <= s.length(); j++)
		{
			inp[i][j] = (s[j-1] == '1');
		}
	}
	memset(f, 0x3f, sizeof(f));
	memset(cost, 0x3f, sizeof(cost));
	f[0] = 0;
	prefi[0] = 0;
	prefk[0] = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int k = 0; k < 27; k++)
		{
			for (int j = 0; j < 20; j++)
			{
				diff[i][j][k] = Diff(i, j, k);
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int k = 0; k < 27; k++)
		{
			for (int j = 0; j < 20; j++)
			{
				int t1 = Cost(i, k, 0, j);
				int t2 = Cost(i + j, k, j + 1, 20-1-j);
				if (t1 + t2 < cost[i][19][k])
					cost[i][19][k] = t1 + t2;
			}

			int t = 0;
			for (int j = 0; j < 20; j++)
			{
				t += diff[i + j][j][k];
			}
			cost[i][20][k] = t;

			for (int j = 0; j < 20; j++)
			{
				int t1 = Cost(i, k, 0, j);
				int t2 = Cost(i + j + 1, k, j, 20 - j);
				if (t1 + t2 < cost[i][21][k])
					cost[i][21][k] = t1 + t2;
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		int t = 0x3f3f3f3f;
		for (int k = 0; k < 27; k++)
		{
			for (int j = 19; j <= 21; j++)
			{
				if (i>=j && t > f[i - j] + cost[i - j + 1][j][k])
				{
					t = f[i - j] + cost[i - j + 1][j][k];
					prefi[i] = i - j;
					prefk[i] = k;
				}
			}
		}
		f[i] = t;
	}
	string ans;
	for (int p = N; p; p = prefi[p])
	{
		ans += S[prefk[p]];
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	fclose(stdin); fclose(stdout);
}
