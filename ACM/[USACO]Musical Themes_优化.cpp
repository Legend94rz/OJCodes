/*
ID: rz109291
PROG: theme
LANG: C++
*/
#include <iostream>
#include <cstdio>
using namespace std;
int N;
int a[6000], s[6000];
int main()
{
	freopen("theme.in", "r", stdin); freopen("theme.out", "w", stdout);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> a[i];
		s[i] = a[i] - a[i - 1];
	}
	int ans = 1;
	for (int i = 1; i <= N-ans; i++)
	{
		for (int j = i+ans+1; j <= N-ans; j++)
			{
				int k = 0;
				while (s[i + k] == s[j + k] && j>i+k+1)k++;
				if (k > ans)
					ans = k;
			}
	}
	if (ans < 4)
		ans = -1;
	cout << ans + 1 << endl;

	fclose(stdin); fclose(stdout);
}