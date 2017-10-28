/*
ID: rz109291
PROG: frameup
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
int N, M,ind[256];
bool G[256][256];
bool occ[256],vis[256];
char m[50][50];
vector<char> alpha;
char ans[27] = { 0 };
void dfs(int pos)
{
	if (pos == alpha.size())
	{
		ans[pos] = '\0';
		cout << ans << endl;
	}
	for (char i = 'A'; i <= 'Z'; i++)
	{
		if (ind[i] == 0 && !vis[i] && occ[i])
		{
			ans[pos]=i;
			vis[i] = true;
			for (char j = 'A'; j <= 'Z'; j++)
			{
				if (G[i][j])
					ind[j]--;
			}
			dfs(pos+1);
			vis[i] = false;
			for (char j = 'A'; j <= 'Z'; j++)
			{
				if (G[i][j])
					ind[j]++;
			}
		}
	}
}
void findUpper(char x, set<char>& p)
{
	int l = 100, r=0, t = 100, b=0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (m[i][j] == x)
			{
				l = min(l, j);
				r = max(r, j);
				t = min(t, i);
				b = max(b, i);
			}
		}
	}
	bool v[256] = { 0 };
	for (int i = t; i <= b; i++)
	{
		if (m[i][l] != x)
			p.insert(m[i][l]);
		if (m[i][r] != x)
			p.insert(m[i][r]);
	}
	for (int i = l; i <= r; i++)
	{
		if (m[t][i] != x)
			p.insert(m[t][i]);
		if (m[b][i] != x)
			p.insert(m[b][i]);
	}
}
int main()
{
	freopen("frameup.in", "r", stdin); freopen("frameup.out", "w", stdout);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> m[i][j];
			if (m[i][j] >= 'A' && m[i][j] <= 'Z' && !occ[m[i][j]])
			{
				occ[m[i][j]] = true;
				alpha.push_back(m[i][j]);
			}
		}
	}
	sort(alpha.begin(),alpha.end());
	for (size_t i = 0; i < alpha.size(); i++)
	{
		set<char> tmp;
		findUpper(alpha[i], tmp);
		for (set<char>::iterator j = tmp.begin(); j != tmp.end(); j++)
		{
			if (*j != '.')
			{
				G[alpha[i]][*j] = true;
				ind[*j]++;
			}
		}
	}
	dfs(0);
	fclose(stdin); fclose(stdout);
}
