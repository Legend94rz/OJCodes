#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string.h>
using namespace std;

vector<int> poly;
int f[1 << 20];
int n, m, T;
double x[20], y[20];
const double eps = 1e-10;


bool polySolution(double x1, double y1, double x2, double y2, double& a, double& b)
{
	double u = (x2*x1*x1 - x1 * x2*x2);
	if (abs(u) < eps)
		return false;
	a = (x2*y1 - x1*y2) / u;
	if (a >= 0 || abs(a)<eps)
		return false;
	b = (y1 - a * x1*x1) / x1;
	return true;
}

bool atPoly(double x0, double y0, double a, double b)
{
	return abs(y0 - (a*x0*x0 + b * x0)) < eps;
}

void init()
{
	memset(f, 0x3f, sizeof(f));
	f[0] = 0;
	poly.clear();

	for (int i = 0; i < n; i++)
	{
		poly.push_back(1 << i);
	}

	for (int i = 0; i < n-1; i++) 
	{
		for (int j = i+1; j < n; j++)
		{
			double a, b;
			bool valid = polySolution(x[i], y[i], x[j], y[j], a, b);
			int s = 0;
			if (valid)
			{
				s = (s | (1<<i) | (1<<j));
				for (int k = 0; k < n; k++)
				{
					if (atPoly(x[k], y[k], a, b))
					{
						s |= (1 << k);
					}
				}
				poly.push_back(s);
			}
		}
	}
}

int main()
{
	freopen("angrybirds.in", "r", stdin);freopen("angrybirds.out", "w", stdout);
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> x[i] >> y[i];
		}
		init();
		for (int i = 0; i < 1 << n; i++)
		{
			for (size_t j = 0; j < poly.size(); j++)
			{
				f[i | poly[j]] = min(f[i | poly[j]], f[i] + 1);
			}
		}
		cout << f[(1 << n) - 1] << endl;
	}
	fclose(stdin);fclose(stdout);
}
