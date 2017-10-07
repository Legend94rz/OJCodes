/*
USER: rz109291
PROG: wormhole
LANG: C++
*/
#include <stdio.h>
#include <stdlib.h>
int x[100], y[100], right[100], pair[100];
int n;
int ans;
bool check()
{
	for (int i = 1; i <= n; i++)
	{
		int start = i;
		for (int cnt = 0; cnt < n; cnt++)
		{
			start = right[pair[start]];
		}
		if (start != 0) return true;
	}
	return false;
}

void solve()
{
	int i;
	for (i = 1; i <= n; i++)
		if (!pair[i])
			break;
	if (i > n)
		ans += check();
	for (int j = i + 1; j <= n; j++)
		if (!pair[i] && !pair[j])
		{
			pair[i] = j; pair[j] = i;
			solve();
			pair[i] = pair[j] = 0;
		}
}
int main()
{
	freopen("wormhole.in","r",stdin);freopen("wormhole.out","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j && x[i] < x[j] && y[i] == y[j] && (!right[i] || x[j] < x[right[i]]))
			{
				right[i] = j;
			}
		}
	}
	solve();
	printf("%d\n", ans);
	fclose(stdin);fclose(stdout);
}