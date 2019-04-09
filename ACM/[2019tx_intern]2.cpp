#include <iostream>
#include <algorithm>
using namespace std;
int ans;
int ans2;
int a[300200];
int n;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int s = a[1];
	for (int i = 2; i <= n; i++)
	{
		ans += abs(s);
		s += a[i];
	}
	s = a[n];
	for (int i = n-1; i >=1; i--)
	{
		ans2 += abs(s);
		s += a[i];
	}
	cout << min(ans, ans2) << endl;
}
