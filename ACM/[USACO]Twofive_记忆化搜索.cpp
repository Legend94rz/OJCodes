/*
ID: rz109291
PROG: twofive
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <memory.h>
using namespace std;

char cr;
int N;
int f[6][6][6][6][6];
string W;
char ans[26];

bool ok(int p, char c)
{
	return (ans[p] == 0 || ans[p] == c);
}

int dfs(int a, int b, int c, int d, int e, char now)
{
	if (now == 'Z')return 1;
	if (f[a][b][c][d][e] > 0) return f[a][b][c][d][e];
	int res = f[a][b][c][d][e];
	if (a < 5 && ok(a, now)) res += dfs(a + 1, b, c, d, e, now + 1);
	if (b < a && ok(b + 5, now)) res += dfs(a, b + 1, c, d, e, now + 1);
	if (c < b && ok(c + 10, now)) res += dfs(a, b, c + 1, d, e, now + 1);
	if (d < c && ok(d + 15, now)) res += dfs(a, b, c, d + 1, e, now + 1);
	if (e < d && ok(e + 20, now)) res += dfs(a, b, c, d, e + 1, now + 1);
	f[a][b][c][d][e] = res;
	return res;
}

int main()
{
	freopen("twofive.in", "r", stdin); freopen("twofive.out", "w", stdout);
	cin >> cr;
	int tmp=0;
	if (cr == 'N')
	{
		cin >> N;
		//map int -> string
		for (int i = 0; i < 25; i++)
		{
			for (ans[i] = 'A'; ; ans[i]++)
			{
				memset(f, 0, sizeof(f));
				if ((tmp = dfs(0, 0, 0, 0, 0, 'A')) < N)
					N -= tmp;
				else
					break;
			}
		}
		printf("%s\n", ans);
	}
	else
	{
		cin >> W;
		//map string -> int

		for (int i = 0; i < W.length(); i++)
		{
			for (ans[i] = 'A'; ans[i]<W[i]; ans[i]++)
			{
				memset(f, 0, sizeof(f));
				tmp += dfs(0, 0, 0, 0, 0, 'A');
			}
		}
		cout << tmp+1 << endl;
	}

	fclose(stdin); fclose(stdout);
}