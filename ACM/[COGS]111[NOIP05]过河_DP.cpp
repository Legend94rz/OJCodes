#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <vector>
#include <string.h>
#include <set>
using namespace std;

vector<int> stone;

int f[100010];
bool is_stone[100010];
int S, T, L, M;

int main()
{
	freopen("river.in", "r", stdin); freopen("river.out", "w", stdout);
	cin >> L;
	cin >> S >> T >> M;
	int t = -1;
	stone.push_back(0);
	for (int i = 0;i < M;i++)
	{
		cin >> t;
		stone.push_back(t);
	}
	sort(stone.begin(), stone.end(), less<int>());

	if (S == T)
	{
		int ans = 0;
		for (int i = 1; i < stone.size(); i++)
		{
			ans += (stone[i] % S == 0);
		}
		cout << ans << endl;
	}
	else
	{
		int zipped = 0;
		int k = (T - 1) * T;
		for (int i = 1; i < stone.size(); i++)
		{
			stone[i] -= zipped;
			int len = stone[i] - stone[i - 1];
			if (len > k)
			{
				zipped += (len - k);
				stone[i] = stone[i - 1] + k;
			}
			is_stone[stone[i]] = true;
		}

		memset(f, 0x3f, sizeof(f));
		f[0] = 0;
		int ML = stone[stone.size() - 1] + 1;
		for (int i = 1; i <= ML; i++)
		{
			int mh = 0x3f3f3f3f;
			for (int j = S; j <= T; j++)
			{
				if (i - j >= 0 && f[i - j] <= mh)
					mh = f[i - j];
			}
			f[i] = mh + is_stone[i];
		}
		cout << f[ML] << endl;
	}
	fclose(stdin); fclose(stdout);
}
