#include <iostream>
#include <cstdio>
using namespace std;
int a[100][100];
int N;
int x, y, z;
int f[30][30][30][30];

int max(int a1, int a2, int a3, int a4)
{
	int ans = a1;
	if (ans < a2)
		ans = a2;
	if (ans < a3)
		ans = a3;
	if (ans < a4)
		ans = a4;
	return ans;
}

int main()
{
	freopen("fgqs.in", "r", stdin); freopen("fgqs.out", "w", stdout);
	cin >> N;
	for(;;)
	{
		cin >> x >> y >> z;
		if (x == y && x == z && z == 0)
			break;
		a[x][y] = z;
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			for (int m = 1; m <= N; m++)
				for (int n = 1; n <= N; n++)
				{
					int t = a[m][n] + a[i][j];
					if (i == m && j == n)
					{
						t = a[m][n];
					}
					f[i][j][m][n] = max(f[i - 1][j][m - 1][n], f[i - 1][j][m][n - 1], f[i][j - 1][m - 1][n], f[i][j - 1][m][n - 1]) + t;
				}
	cout << f[N][N][N][N] << endl;
	fclose(stdin); fclose(stdout);
}
