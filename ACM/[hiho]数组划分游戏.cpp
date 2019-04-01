#include <iostream>
using namespace std;
typedef long long i64;
int n, k;
int a[100010];
i64 S = 0;


bool check(i64 t)
{
	int tk = 0;
	i64 s = 0, _s = 0;
	for (int i = 1; i <= n; i++)
	{
		if (s < t)
			s += a[i];
		if (s>=t)
		{
			tk++;
			s = 0;
			if (tk == k - 1)
			{
				for (int j = i+1; j <= n; j++)
				{
					_s += a[j];
				}
				break;
			}
		}
	}


	return _s>=t;
}

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		S += a[i];
	}
	if (k == 1)
	{
		cout << S << endl;
		return 0;
	}
	i64 l = 1; i64 r = S;
	while (l <= r)
	{
		i64 m = (l + r) >> 1;
		if (check(m))
			l = m + 1;
		else
			r = m - 1;	
	}
	cout << r << endl;//todo
}