#include <string.h>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
#define MAXN 150000
typedef long long ll;

class obj {
public:
	int type;
	int x, y;
	int oriid;
	obj(int x, int y, int c, int id) :x(x), y(y), type(c), oriid(id) {}
	bool operator< (const obj& b)const
	{
		if (x < b.x)
			return true;
		else if (x == b.x && type < b.type)
			return true;
		else
			return false;
	}
	bool operator>(const obj& b)const
	{
		if (x > b.x)
			return true;
		else if (x == b.x && type < b.type)
			return true;
		else
			return false;
	}
};

int T, N, K;
int p[MAXN], h[MAXN], x[MAXN], y[MAXN];
bool flag[MAXN];
vector<obj> v;

void gen(int a[], int L)
{
	ll A, B, C;
	int M;
	cin >> a[1] >> a[2] >> A >> B >> C >> M;
	for (int i = 3; i <= L; i++)
		a[i] = (A * a[i - 1] + B * a[i - 2] + C) % M + 1;
}

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N >> K;
		v.clear();
		memset(flag, 0, sizeof(flag));

		gen(p, N); gen(h, N); gen(x, K); gen(y, K);
		for (int i = 1; i <= N; i++)
			v.push_back(obj(p[i], h[i], 0, -1));
		for (int i = 1; i <= K; i++)
			v.push_back(obj(x[i], y[i], 1, i));
		int maxPH = 0;
		sort(v.begin(), v.end(), less<obj>());
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].type == 0)
				maxPH = max(maxPH, v[i].x + v[i].y);
			else
			{
				flag[v[i].oriid] |= (v[i].x + v[i].y <= maxPH);
			}
		}

		int minPH = 0x7f7f7f7f;
		sort(v.begin(), v.end(), greater<obj>());
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].type == 0)
				minPH = min(minPH, v[i].x - v[i].y);
			else
				flag[v[i].oriid] |= (v[i].x - v[i].y >= minPH);
		}
		int ans = 0;
		for (int i = 1; i <= K; i++)
		{
			ans += flag[i];
		}
		printf("Case #%d: %d\n", t, ans);
	}
}
