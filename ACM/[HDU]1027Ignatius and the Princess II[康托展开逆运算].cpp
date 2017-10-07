#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int n, m;
int a[1001];
bool used[1001];
int fac(int x)
{
	int s = 1;
	for (int i = 1; i <= x; i++)
	{
		s = s*i;
		if (s > m)
			return s;
	}
	return s;
}
int main()
{
	while (true)
	{
		cin >> n >> m;
		if (cin.eof())break;
		m--;
		memset(used, 0, sizeof(used));
		for (int i = n - 1; i >= 0; i--)
		{
			int f = fac(i);
			int x = m / f;
			int y = m%f;
			int t = 0;
			for (int j = 1; j <= n; j++)
			{
				if (!used[j])
				{
					t++;
					if (t > x)
					{
						a[i] = j;
						used[j] = true;
						break;
					}
				}
			}
			m = y;
		}
		for (int i = n - 1; i > 0; i--)
		{
			cout << a[i] << ' ';
		}cout << a[0] << endl;
	}
}
