/*
ID: rz109291
PROG: vans
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;


class BigNum
{
public:
	int a[500];
	int l;
	BigNum(int x = 0)
	{
		memset(a, 0, sizeof(a));
		a[0] = x;
		for (l=0; a[l] > 0 || l==0;l++)
		{
			a[l + 1] = a[l] / 10;
			a[l] %= 10;
		}
	}
	void print()
	{
		for (int i = l-1; i>=0; i--)
		{
			cout << a[i];
		}cout << endl;
	}
};
int N;
BigNum f[1200], g[1200];
//int f[1200], g[1200];

void add(const BigNum& a, const BigNum& b, BigNum& c)
{
	c.l = max(a.l, b.l);
	for (int i = 0; i < c.l; i++)
	{
		c.a[i] = a.a[i] + b.a[i] + c.a[i];
		c.a[i + 1] += c.a[i] / 10;
		c.a[i] %= 10;
	}
	if (c.a[c.l] > 0)c.l++;
}
void mul(const BigNum& a, const int b, BigNum& c)
{
	c.l = a.l;
	for (int i = 0; i < a.l; i++)
	{
		c.a[i] = a.a[i] * b + c.a[i];
		c.a[i + 1] += c.a[i] / 10;
		c.a[i] %= 10;
	}
	while (c.a[c.l] > 0)c.l++;
}
void sub(const BigNum& a, const BigNum& b, BigNum& c)
{
	c.l = max(a.l, b.l);
	int y;
	for (int i = 0; i < c.l; i++)
	{
		y = 0;
		if (c.a[i] + a.a[i] - b.a[i] <0)
		{
			y = 10;
			c.a[i + 1]--;
		}
		c.a[i] = a.a[i] - b.a[i] + y + c.a[i];
	}
	if (c.l>1 && c.a[c.l-1] == 0)c.l--;
}

int main()
{
	freopen("vans.in", "r", stdin); freopen("vans.out", "w", stdout);
	cin >> N;
	g[0] = 0;
	f[1] = 0;
	g[1] = 1;
	f[2] = 1;
	g[2] = 1;

	for (int i = 3; i <= N; i++)
	{
		//f[i] = f[i - 1] + g[i - 1];
		//g[i] = 2 * f[i - 1] + g[i - 2] + g[i - 1] - g[i - 3];

		BigNum t1, t2, t3;
		add(f[i - 1] , g[i - 1], f[i]);
		
		mul(f[i - 1], 2, t1);
		add(g[i - 1], g[i - 2], t2);
		add(t1, t2, t3);
		sub(t3, g[i - 3], g[i]);
	}
	BigNum t;
	mul(f[N], 2, t);
	t.print();
	fclose(stdin); fclose(stdout);
}