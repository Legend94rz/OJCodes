/*
ID: rz109291
PROG: milk4
LANG: C++
*/

/*
Given a Diophantine equation: \sum a_i * x_i = c, the Necessity and Sufficiency is:
gcd(a_i)|c
*/
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cstdio>
using namespace std;
int Q, P;
int v[150];
bool use[150];
int ans[150], K;
bool f[25000];


int cmp(const void* x, const void* y)
{
	return *(const int*)x > *(const int*)y;
}
bool check(int* a, int n)
{
	memset(f, 0, sizeof(f));
	f[0] = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = a[i]; j <= Q; j++)
		{
			f[j] = (f[j] || f[j - a[i]]);
		}
	}
	return f[Q];
}
void dfs(int s, int n)
{
	if (n == K)
	{
		if (check(ans, n))
		{
			cout << K;
			for (int j = 0; j < K; j++)
				cout << ' ' << ans[j];
			cout << endl;
			fclose(stdin); fclose(stdout);
			exit(0);
		}
		return;
	}
	for (int i = s; i <= P-K+n; i++)	//这里直接写 <P 也可以
	{
		ans[n] = v[i];
		dfs(i+1, n+1);
	}
}
int main()
{
	freopen("milk4.in", "r", stdin); freopen("milk4.out", "w", stdout);
	cin >> Q >> P;
	for (int i = 0; i < P; i++)
	{
		cin >> v[i];
	}
	qsort(v, P, sizeof(int), cmp);
	for (K = 1; K <= P; K++)
	{
		dfs(0, 0);
	}

}

