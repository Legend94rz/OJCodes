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
	int m[2000];
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

void add(BigNum& a, const BigNum& b)
{
	a.len = max(b.len, a.len);
	int c = 0;
	for (int i = 0; i < a.len; i++)
	{
		a.m[i] = a.m[i] + b.m[i] + c;
		c = a.m[i] / a.T;
		a.m[i] %= a.T;
	}
	if (c > 0) a.m[a.len++] = c;
}
void output(const BigNum& a)
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
}

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
	/*
	Here are the respective outputs:
	----- our output ---------
	200_1606938044258990275541962092341162602522202993782792835301376
	---- your output ---------
	200_256
	--------------------------

	------ Data for Run 8 [length=1896 bytes] ------
	400
	3992 4000 3972 3980 3952 3960 3932 3940 3912 3920 3892 3900 3872
	3880 3852 3860 3832 3840 3812 3820 3792 3800 3772 3780 3752 3760
	3732 3740 3712 3720 3692 3700 3672 3680 3652 3660 3632 3640 3612
	3620 3592 3600 3572 3580 3552 3560 3532 3540 3512 3520 3492 3500
	3472 3480 3452 3460 3432 3440 3412 3420 3392 3400 3372 3380 3352
	3360 3332 3340 3312 3320 3292 3300 3272 3280 3252 3260 3232 3240
	3212 3220 3192 3200 3172 3180 3152 3160 3132 3140 3112 3120 3092
	3100 3072 3080 3052 3060 3032 3040 3012 3020 2992 3000 2972 2980
	2952 2960 2932 2940 2912 2920 2892 2900 2872 2880 2852 2860 2832
	2840 2812 2820 2792 2800 2772 2780 2752 2760 2732 2740 2712 2720
	2692 2700 2672 2680 2652 2660 2632 2640 2612 2620 2592 2600 2572
	2580 2552 2560 2532 2540 2512 2520 2492 2500 2472 2480 2452 2460
	2432 2440 2412 2420 2392 2400 2372 2380 2352 2360 2332 2340 2312
	2320 2292 2300 2272 2280 2252 2260 2232 2240 2212 2220 2192 2200
	2172 2180 2152 2160 2132 2140 2112 2120 2092 2100 2072 2080 2052
	2060 2032 2040 2012 2020 1992 2000 1972 1980 1952 1960 1932 1940
	1912 1920 1892 1900 1872 1880 1852 1860 1832 1840 1812 1820 1792
	1800 1772 1780 1752 1760 1732 1740 1712 1720 1692 1700 1672 1680
	1652 1660 1632 1640 1612 1620 1592 1600 1572 1580 1552 1560 1532
	1540 1512 1520 1492 1500 1472 1480 1452 1460 1432 1440 1412 1420
	1392 1400 1372 1380 1352 1360 1332 1340 1312 1320 1292 1300 1272
	1280 1252 1260 1232 1240 1212 1220 1192 1200 1172 1180 1152 1160
	1132 1140 1112 1120 1092 1100 1072 1080 1052 1060 1032 1040 1012
	1020 992 1000 972 980 952 960 932 940 912 920 892 900 872 880 852
	860 832 840 812 820 792 800 772 780 752 760 732 740 712 720 692
	700 672 680 652 660 632 640 612 620 592 600 572 580 552 560 532
	540 512 520 492 500 472 480 452 460 432 440 412 420 392 400 372 380
	352 360 332 340 312 320 292 300 272 280 252 260 232 240 212 220 192
	200 172 180 152 160 132 140 112 120 92 100 72 80 52 60 32 40 12 20
	*/

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
	cout << f[N - 1] - 1 << ' '/* << cn[N - 1] << endl*/;
	output(cn[N - 1]);
	cout << endl;
	fclose(stdin); fclose(stdout);
}
