/*
ID: rz109291
PROG: cowcycle
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <list>
#include <cmath>
using namespace std;

int F, R, F1, F2, R1, R2;
int a[100], b[100];
int optA[100], optB[100];
double optVar=99999999.0;


//void check(int* a, int* b)
//{
//	list<double> c1;
//	if (a[F] * b[R] < 3 * a[1] * b[1])return;
//	for (int i = 1; i <= F; i++)
//	{
//		list<double> c2, c3;		//合并 c1 c2两个降序序列至 c3
//		for (int j = 1; j <= R; j++)
//		{
//			c2.push_back( a[i]*1.0 / b[j] );
//		}
//		auto j = c1.begin(), k = c2.begin();
//		for (; j != c1.end() && k != c2.end();)
//		{
//			if (*j > *k)
//				c3.push_back(*j++);
//			else
//				c3.push_back(*k++);
//		}
//		if(k!=c2.end())
//			c3.insert(c3.end(), k, c2.end());
//		if (j != c1.end())
//			c3.insert(c3.end(), j, c1.end());
//		c1 = c3;
//	}
//	double t[150];
//	int j = 0;
//	for (auto i = c1.begin(); i != c1.end(); i++)
//	{
//		t[j++] = *i;
//	}
//
//	double s1 = 0, avr = 0, var = 0, s2 = 0;
//	for (auto i = 1; i < F*R; i++)
//	{
//		s1 += abs(t[i]-t[i-1]);
//		s2 += pow(abs(t[i] - t[i - 1]), 2);
//	}
//	avr = s1 / (R*F-1); 
//	var = s2 - s1*avr;
//	if (var < optVar)
//	{
//		optVar = var;
//		memcpy(optA, a, sizeof(optA));
//		memcpy(optB, b, sizeof(optB));
//	}
//}

//为何插入排序比合并有序序列快？

void check(int* a, int* b)
{
	if (a[F] * b[R] < 3 * a[1] * b[1])return;
	double t[150];
	int L = 0;
	for (int i = 1; i <= F; i++)
	{
		for (int j = 1; j <= R; j++)
		{
			double f = (double)a[i] / b[j];
			int k = L;
			while (k > 0 && t[k-1]<f)
			{
				t[k] = t[k - 1];
				k--;
			}
			t[k] = f; L++;
		}
	}
	double s1 = 0, avr = 0, var = 0, s2 = 0;
	for (auto i = 1; i < F*R; i++)
	{
		s1 += t[i] - t[i - 1];
		s2 += pow(t[i] - t[i - 1], 2);
	}
	avr = s1 / (R*F - 1);
	var = s2 - s1 * avr;
	if (var < optVar)
	{
		optVar = var;
		memcpy(optA, a, sizeof(optA));
		memcpy(optB, b, sizeof(optB));
	}
}



void dfs(int* g, int cur, int start, const int ed)
{
	if (g == a && cur > F)
	{
		dfs(b, 1, R1, R2 - R + 1);
		return;
	}
	if (g == b && cur > R)
	{
		check(a, b);
		return;
	}
	for (int i = start; i <= ed; i++)
	{
		g[cur] = i;
		dfs(g, cur + 1, i + 1, ed + 1);
	}
}

int main()
{
	freopen("cowcycle.in", "r", stdin); freopen("cowcycle.out", "w", stdout);
	cin >> F >> R;
	cin >> F1 >> F2 >> R1 >> R2;
	dfs(a, 1, F1, F2 - F + 1);
	for (int i = 1; i <= F; i++)
	{
		cout << optA[i];
		if (i != F)
			cout << ' ';
	}
	cout << endl;
	for (int i = 1; i <= R; i++)
	{
		cout << optB[i];
		if (i != R)
			cout << ' ';
	}
	cout << endl;

	fclose(stdin); fclose(stdout);
}