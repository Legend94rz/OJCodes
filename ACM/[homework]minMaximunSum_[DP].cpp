#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
#define INF (0x3f3f3f3f)
int N, B;
int a[1001], s[1001];
int f[1001][1001], g[1001];

int findmax(int l, int r)
{
	int m = -INF;
	for (int i = l; i <= r; i++)
	{
		if (a[i] > m)
			m = a[i];
	}
	return m;
}
int main()
{
	cin >> N >> B;
	int m = -INF;
	memset(f, 0x3f3f3f3f, sizeof(f));
	memset(g, 0x3f3f3f3f, sizeof(g));
	for (int i = 1; i <= N; i++)
	{
		cin >> a[i];
		if (a[i] > m)
			m = a[i];
		s[i] = s[i - 1] + a[i];
		if (s[i] <= B)
			f[i][1] = m;
	}
	int t = INF;
	/*
	//another method:
	for (int j = 2; j <= N; j++)
	{
		for (int i = j; i <= N; i++)
		{
			for (int k = i-1; k >=1; k--)
			{
				if (s[i] - s[k] > B)
					break;
				f[i][j] = min( f[k][j - 1] + findmax(k + 1, i) ,f[i][j]);
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (f[N][i] < t)
			t = f[N][i];
	}
	cout<<t<<endl;
	*/
	g[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (s[i] - s[j] > B)
				break;
			g[i] = min(g[i], g[j] + findmax(j + 1, i));
		}
	}
	cout << g[N] << endl;
}