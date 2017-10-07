/*
ID: rz109291
LANG: C++
PROG: nuggets
*/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n;
int a[100];
bool f[100000];
int m;
int g;
bool hasOne;
int gcd(int x, int y)
{
	if (y == 0)return x;
	return gcd(y, x%y);
}
int main()
{
	freopen("nuggets.in", "r", stdin); freopen("nuggets.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] > m)
			m = a[i];
		if (a[i] == 1)
			hasOne = true;
	}
	m *= m;
	g = a[0];
	f[0] = true;
	for (int i = 1; i < n; i++)
		g = gcd(g, a[i]);
	if (g != 1)
	{
		cout << 0 << endl;
		goto END;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = a[i]; j <= m; j++)
		{
			if (f[j - a[i]])
				f[j] = true;
		}
	}
	for (int i = m; i >= 0; i--)
	{
		if (!f[i])
		{
			cout << i << endl;
			break;
		}
	}
	if (hasOne)
		cout << 0 << endl;
	END:
	fclose(stdin); fclose(stdout);
}