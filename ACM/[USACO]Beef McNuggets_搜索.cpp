/*
ID: rz109291
LANG: C++
PROG: nuggets
*/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n;
int a[100];
bool f[10000];
int s;
void dfs(int i, int m)//当前第i个数，当前和m
{
	if (m > s)return;
	f[m] = true;
	if (i >= n)return;
	//cout << i << ' ' << m << endl;
	for (int j = 0; j < s / a[i] + 1; j++)
	{
		dfs(i + 1, m + j*a[i]);
	}
}
int main()
{
	//freopen("nuggets.in", "r", stdin); freopen("nuggets.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		s += a[i];
	}
	s *= 2;
	dfs(0, 0);
	bool hasAns = false;
	s /= 2;
	for (int i = s; i >= 0; i--)
	{
		if (!f[i] && f[i*2])
		{
			cout << i << endl;
			hasAns = true;
			break;
		}
		else if(!f[i] && !f[i*2])
		{
			cout << 0 << endl;
			hasAns = true;
			break;
		}
	}
	if (!hasAns)cout << 0 << endl;//all can be satisfied.
	//what about no bound?
	fclose(stdin); fclose(stdout);
}