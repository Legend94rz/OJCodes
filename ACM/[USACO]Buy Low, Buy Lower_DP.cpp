/*
ID: rz109291
LANG: C++
PROG: buylow
*/
#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <limits.h>
#include <cmath>
#include <string.h>
using namespace std;
class BigNum
{
public:
	int T = 10000000;
	int len;
	int m[200];
	BigNum()
	{
		len = 0;
		memset(m, 0, sizeof(m));
	}
	BigNum(int x)
	{
		len = 0;
		memset(m, 0, sizeof(m));
		m[0] = x;
		for (; m[len] > 0; len++)
		{
			m[len + 1] = m[len] / T;
			m[len] %= T;
		}
		if (len == 0)len = 1;
	}
	BigNum& operator+(const BigNum& b)
	{
		len = max(b.len, len);
		int c = 0;
		for (int i = 0; i < len; i++)
		{
			m[i] = m[i] + b.m[i] + c;
			c = m[i] / T;
			m[i] %= T;
		}
		if (c > 0) m[len++] = c;
		return *this;
	}
	BigNum& operator=(const BigNum& b)
	{
		this->len = b.len;
		memcpy(this->m, b.m, sizeof(b.m));
		return *this;
	}
	friend ostream& operator<<(ostream&, const BigNum&);
};

int N;
unsigned int a[6000];
int f[6000];
BigNum cn[6000];

ostream& operator<<(ostream& os, const BigNum& a)
{
	int a2 = ceil(log10(a.T + 1));
	for (int i = a.len - 1; i >= 0; i--)
	{
		if (i != a.len - 1)
		{
			int a1 = ceil(log10(a.m[i] + 1));
			if (a1 == 0)a1 = 1;
			for (int j = 0; j < a2 - a1 - 1; j++)
			{
				cout << '0';
			}
		}
		cout << a.m[i];
	}
	return os;
}

int main()
{
	freopen("buylow.in", "r", stdin); freopen("buylow.out", "w", stdout);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	a[N] = 0;
	N++;
	f[0] = 1;

	cn[0] = BigNum(1);	//

	for (int i = 1; i < N; i++)
	{
		int Mx = 0;
		BigNum c(0);
		set<unsigned int> s;
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[j] > a[i] && f[j] > Mx)
			{
				Mx = f[j];
				s.clear();
				c = BigNum(0);
			}
			if (a[j] > a[i] && f[j] == Mx)
			{
				if (s.find(a[j]) == s.end())
				{
					c = c + cn[j];//
					s.insert(a[j]);
				}
			}
		}
		f[i] = Mx + 1;
		if (c.len == 1 && c.m[0] == 0)c = 1;
		cn[i] = c;
	}
	cout << f[N - 1] - 1 << ' ' << cn[N - 1] << endl;
	fclose(stdin); fclose(stdout);
}
