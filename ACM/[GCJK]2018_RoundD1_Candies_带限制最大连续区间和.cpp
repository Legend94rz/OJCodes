#include <iostream>
#include <cstdio>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std; 
typedef long long LL;

multiset<LL, greater<LL> > tree;
int T, N;
LL O, D, L, A, B, C, M;
LL X[500007], S[500007], m[500007];
//i64
void erase_one(multiset<LL, greater<LL>>& s, LL x)
{
	auto it = s.find(x);
	if (it!=s.end())
		s.erase(it);
}

int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		tree.clear();
		cin >> N >> O >> D;
		cin >> X[1] >> X[2] >> A >> B >> C >> M >> L;
		S[1] = X[1] + L;
		S[2] = X[2] + L; m[1] = S[1]; m[2] = S[2] + S[1];
		for (int i = 3; i <= N; i++)
		{
			X[i] = (A * X[i - 1] + B * X[i - 2] + C) % M;
			S[i] = X[i] + L;
			m[i] = m[i - 1] + S[i];
		}
		int odd = 0;
		LL ans = -(1LL<<63);
		for (int i = 1, j=1; i <= N; i++)
		{
			while (j<=N && odd + (abs(S[j])&1) <= O)
			{
				tree.insert(m[j]);
				odd += (abs(S[j])&1);
				j++;
			}
			//ask
			auto p = tree.lower_bound(D + m[i - 1]);
			if (p != tree.end())
			{
				ans = max(ans, (*p) - m[i - 1]);
			}

			erase_one(tree, m[i]);
			if (odd>0 && (abs(S[i]) & 1))
				odd -= 1;
		}
		if (ans != -(1LL << 63))
			printf("Case #%d: %lld\n", t, ans);
		else
			printf("Case #%d: IMPOSSIBLE\n", t);
	}
}
