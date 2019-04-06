/*
ID: rz109291
PROG: wissqu
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

char g[10][10];
bool used[10][10];
int n[256];
int tot;

char ansC[20];
int ansX[20], ansY[20];
bool hasPrint = false;

bool can(char c, int x, int y)
{
	return (!used[x][y] && n[c]>0 &&
		g[x - 1][y - 1] != c && g[x - 1][y] != c && g[x - 1][y + 1] != c && 
		g[x][y - 1] != c && g[x][y] != c && g[x][y + 1] != c && 
		g[x + 1][y - 1] != c && g[x + 1][y] != c && g[x + 1][y + 1] != c);
}

void dfs(int p)
{
	if (p == 16)
	{
		if (!hasPrint)
		{
			hasPrint = true;
			for (int i = 0; i < p; i++)
			{
				cout << ansC[i] << ' ' << ansX[i] << ' ' << ansY[i] << endl;
			}
		}
		tot++;
		return;
	}
	char l, h;
	if (p == 0)
		l = h = 'D';
	else
	{
		l = 'A'; h = 'E';
	}
	for (char c = l; c <= h; c++)
	{
		for (int i = 1; i <= 4; i++)
		{
			for (int j = 1; j <= 4; j++)
			{
				if (can(c, i, j))
				{
					char t = g[i][j];
					g[i][j] = c;
					used[i][j] = true;
					n[c]--;
					ansC[p] = c; ansX[p] = i; ansY[p] = j;
					dfs(p + 1);
					n[c]++;
					used[i][j] = false;
					g[i][j] = t;
				}
			}
		}
	}
}


int main()
{
	freopen("wissqu.in", "r", stdin); freopen("wissqu.out", "w", stdout);
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			cin >> g[i][j];
		}
	}
	n['A'] = n['B'] = n['C'] = n['E'] = 3;
	n['D'] = 4;
	dfs(0);
	cout << tot << endl;
	fclose(stdin); fclose(stdout);
}