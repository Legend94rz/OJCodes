#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long i64;

vector<int> V;
double f;
vector<i64> S;
int T;
int N, K;
int x;

int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N>>K;
		V.clear();
		S.clear();
		for (int i = 0; i < N; i++)
		{
			cin >> x;
			V.push_back(x);
		}
		sort(V.begin(), V.end(), less<int>());
		S.push_back(V[0]);
		for (int i = 1; i < N; i++)
			S.push_back(S[i - 1] + V[i]);
		f = S[N - 1]*1.0 / N;
		for (int k = 1; k <= K; k++)
		{
			double cnt = (double)(upper_bound(V.begin(), V.end(), f) - V.begin());
			f = 1.0 / N * (cnt * f + (S[N - 1] - S[cnt - 1]));
		}
		printf("Case #%d: %.6lf\n", t, f);
	}
}

