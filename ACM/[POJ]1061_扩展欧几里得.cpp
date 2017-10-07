#include <iostream>
#include <cmath>
using namespace std;
__int64 m, n, x, y, L;
struct triple {
	__int64 d, x, y;
	triple(__int64 D, __int64 X, __int64 Y) { d = D; x = X; y = Y; }
};
triple gcd(__int64 a, __int64 b)
{
	if (b == 0)
		return triple(a, 1, 0);
	triple t = gcd(b, a%b);
	return triple(t.d, t.y, t.x - t.y*(a / b));
}
__int64 abs(__int64 a)
{
	if(a<0)return -a;
	return a;
}
int main()
{
	cin >> x >> y >> m >> n >> L;
	triple t = gcd(m - n, L);//如果m-n<0, 那么最大公约数求出来<0。

	if ((y - x) % t.d != 0)
		cout << "Impossible" << endl;
	else
	{
		__int64 x0 = t.x*((y - x) / t.d) % L;
		for (int i = 1; x0 < 0; i++)
		{
			x0 += abs(i*(L / t.d));
		}
		cout << x0 << endl;
	}
}
