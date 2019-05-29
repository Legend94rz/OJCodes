#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <tuple>
using namespace std;
typedef long long i64;
typedef unsigned short WORD;
#define LOW_WORD(x) (x&((1<<16)-1))
const i64 MAXP = 1e18;

int T, N, K;
i64 P;
vector<pair<int, int>> constrains[200];
i64 f[110][1 << 16];
int a, b, c;
int cnt[1 << 16];

bool check(int b, int n)
{
	for (auto tp : constrains[b])
	{
		int len = get<0>(tp);
		int c = get<1>(tp);
		if (cnt[n &((1 << len) - 1)] != c)
			return false;
	}
	return true;
}

int main()
{
	//preprocess
	cnt[0] = 0;
	for (int i = 1;i < 1 << 16;i++)
	{
		cnt[i] = cnt[i >> 1] + (i & 1);
	}
	
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N >> K >> P;
		//init
		for (int i = 0; i <= N; i++)
			constrains[i].clear();
		for (int i = 1; i <= K; i++)
		{
			cin >> a >> b >> c;
			constrains[b].push_back(make_pair(b-a+1, c));
		}
		//dp
		memset(f, 0, sizeof(f));
		for(int j=0;j<1<<16;j++)
			if (check(N, j))
				f[N][j] = 1;

		for (int i = N - 1; i > 0; i--)
		{
			for(int j=0;j<1<<16;j++)
				if (check(i, j))
				{
					f[i][j] = f[i + 1][LOW_WORD(j << 1)] + f[i + 1][LOW_WORD((j << 1) + 1)];
					if (f[i][j] > MAXP) f[i][j] = MAXP + 1;		//必须要加(不然会加爆?)
				}
		}
		//construct ans
		printf("Case #%d: ", t);
		for (int i = 1, j=0; i <= N; i++, j=LOW_WORD(j<<1))
		{
			if (P <= f[i][j])
			{
				cout << '0';
			}
			else
			{
				cout << '1';
				P = P - f[i][j];
				j +=1;
			}
		}
		cout << endl;
	}
}
