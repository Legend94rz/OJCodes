//这个编辑器写得真渣！
#include <iostream>
using namespace std;
int m, n, lim;
int t;
int cnt;
int a[100];
void dfs(int x, int prev, int s)
{
	if (x == n-1)
	{
		if (m -s >=prev)
			cnt++;
		return;
	}
	for (int i = prev; i <= lim; i++)
	{
		a[x] = i;
		dfs(x + 1, i, s + i);
	}
}
int main()
{
	cin >> t;
	while (t--)
	{
		cnt = 0;
		cin >> m >> n;
		if (n == 0) { cout << 0 << endl; continue; }
		lim = m / n + 1;
		dfs(0, 0, 0);
		cout << cnt << endl;
	}


}