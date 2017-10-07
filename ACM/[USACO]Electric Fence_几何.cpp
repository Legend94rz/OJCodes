/*
ID: rz109291
LANG: C++
PROG: fence9
*/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n, m, p;
int ans;
int main()
{
	freopen("fence9.in", "r", stdin); freopen("fence9.out", "w", stdout);
	cin >> n >> m >> p;

	for (int y = 1; y < m; y++)
	{
		int x1, x2;
		if (y*n%m == 0)
			x1 = y*n / m + 1;
		else
			x1 = int(ceil(double(y*n) / m));
		if (y*(n - p) % m == 0)
			x2 = y*(n - p) / m + p - 1;
		else
			x2 = int(floor(double(y*(n - p)) / m)) + p;
		ans += x2 - x1 + 1;
	}
	cout << ans << endl;
	fclose(stdin); fclose(stdout);
}