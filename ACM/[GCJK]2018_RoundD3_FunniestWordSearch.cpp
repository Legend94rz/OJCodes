#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAXN 105
typedef long long LL;
int T;
int R, C, W;

vector<string> word[MAXN];
LL total[MAXN][MAXN];
LL Left[MAXN][MAXN][MAXN];
LL Up[MAXN][MAXN][MAXN];
LL col_left[MAXN];
LL col_up[MAXN];
char map[MAXN][MAXN];
string s;

int findWord(int i, int j, int k, int dir)
{
	char buf[200] = { 0 };
	if (dir == 0)
		for (int t = 0; t < k; t++)
			buf[t] = map[i][j - t];//left
	else
		for (int t = 0; t < k; t++)
			buf[t] = map[i - t][j];//up
	int ans = 0;
	string w(buf);
	for (size_t t = 0; t < word[k].size(); t++)
		if (word[k][t] == w)
			ans++;
	return ans;
}

LL gcd(LL a, LL b)
{
	if (b == 0)return a;
	return gcd(b, a % b);
}

int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> R >> C >> W;
		for (int r = 1; r <= R; r++)
			for (int c = 1; c <= C; c++)
				cin >> map[r][c];
		for (int i = 0; i < MAXN; i++)
			word[i].clear();
		for (int w = 1; w <= W; w++)
		{
			cin >> s;
			if (s.length() > max(R, C))
				continue;
			word[s.length()].push_back(s);
			reverse(s.begin(), s.end());
			word[s.length()].push_back(s);
		}
		//if (t!=37)
		//	continue;
		memset(Left, 0, sizeof(Left));
		memset(Up, 0, sizeof(Up));
		for (int i = 1; i <= R; i++)
			for (int j = 1; j <= C; j++)
			{
				for (int k = 1; k <= j; k++)
					Left[i][j][k] = Left[i][j][k - 1] + (LL)findWord(i, j, k, 0) * k;
				for (int k = 1; k <= i; k++)
					Up[i][j][k] = Up[i][j][k - 1] + (LL)findWord(i, j, k, 1) * k;
			}
		LL max1 = 0, max2 = 1, cnt = 0;
		for (int i1 = 1; i1 <= R; i1++)
			for (int j1 = 1; j1 <= C; j1++)
			{
				memset(total, 0, sizeof(total));
				memset(col_left, 0, sizeof(col_left));
				memset(col_up, 0, sizeof(col_up));
				for (int i2 = i1; i2 <= R; i2++)
				{
					for (int j2 = j1; j2 <= C; j2++)
					{
						LL w = (LL)j2 - j1 + 1;
						LL h = (LL)i2 - i1 + 1;
						col_left[j2] += Left[i2][j2][w];
						col_up[j2] += Up[i2][j2][h];
						total[i2][j2] = total[i2][j2 - 1] + col_left[j2] + col_up[j2];
						//update ans
						if (total[i2][j2] * max2 > max1 * (w + h))
						{
							max1 = total[i2][j2];
							max2 = w + h;
							cnt = 1;
						}
						else if (max1 * (w + h) == total[i2][j2] * max2)
							cnt++;
					}
				}
			}
		LL c = gcd(max1, max2);
		printf("Case #%d: %lld/%lld %lld\n", t, LL(max1 / c), LL(max2 / c), cnt);
	}
}
