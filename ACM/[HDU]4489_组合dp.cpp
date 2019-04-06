#include <iostream>
using namespace std;
typedef __int64 i64;

i64 f[100][100];
i64 ans[100];
i64 C[100][100];

int T;
int x, y;


void init(int n)
{
	for (int i = 0; i <= n; i++)
	{
		C[i][0] = C[0][i] = 1;
	}
	C[0][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
}


int main()
{
	init(21);
	ans[1] = 1;f[1][0] = 1;f[1][1] = 1;f[0][0] = f[0][1] = 1;
	for (int n = 2; n <= 20; n++)
	{
		for (int j = 1;j <= n;j++)
		{
			ans[n] += C[n - 1][j - 1] * f[j - 1][0] * f[n - j][1];
		}
		f[n][0] = f[n][1] = ans[n] / 2;
	}

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> x >> y;
		cout << x << ' ' << ans[y] << endl;
	}
}