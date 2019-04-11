#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long i64;
int T;
int n;
i64 a[200], f[200];

i64 calc(int l, int r)
{
	i64 s = 0;
	for (int i = l; i <= r; i++)
	{
		s += (i - 1)*a[i];
	}
	for (int k = l; k <= r; k++)
	{
		i64 tmp = 0;
		for (int i = k+1, j = l - 1; i <= r; i++, j++)
		{
			tmp += j * a[i];
		}
		for (int i = l, j = r-1; i <= k; i++, j--)
		{
			tmp += j * a[i];
		}
		s = min(s, tmp);
	}
	return s;
}

int main()
{
	cin >> T;
	for(int t=1;t<=T;t++)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		memset(f, 0x7f, sizeof(f));
		f[0] = 0;
		//cout << calc(3, 4) << endl;
		for(int i=1;i<=n;i++)
			for (int j = i - 1; j >= 0; j--)
			{
				f[i] = min(f[i], f[j] + calc(j + 1, i));
			}
		printf("Case #%d: %lld\n", t, f[n]);
	}
}
