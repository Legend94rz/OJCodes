/*
ID: rz109291
PROG: fc
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <limits.h>
using namespace std;
int N;
double x[10001], y[10001], alg[10001];
int perm[10001],pmin;
double minx = INT_MAX, miny=INT_MAX;
int stack[10001];
int top,head;
void Qsort(int s, int t)
{
	int i = s, j = t;
	double k = alg[(s + t) >> 1];
	int u;
	double v;
	while (i<=j)
	{
		while (alg[i] < k)i++;
		while (alg[j] > k)j--;
		if (i <= j)
		{
			u = perm[i]; perm[i] = perm[j]; perm[j] = u;
			v = alg[i]; alg[i] = alg[j]; alg[j] = v;
			i++; j--;
		}
	}
	if (i < t)Qsort(i, t);
	if (s < j)Qsort(s, j);
}
bool checkTop3(int t1,int t2,int t3)
{
	double v1[2], v2[2];
	v1[0] = x[t2] - x[t1]; v1[1] = y[t2] - y[t1];
	v2[0] = x[t3] - x[t2]; v2[1] = y[t3] - y[t2];
	return (v1[0] * v2[1] - v1[1] * v2[0]) > 0;
}
double dist(int i, int j)
{
	return sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
}
int main()
{
	freopen("fc.in", "r", stdin); freopen("fc.out", "w", stdout);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x[i] >> y[i];
		if (x[i] < minx)
		{
			minx = x[i]; miny = y[i];
			pmin = i;
		}
		else if (y[i] < miny && x[i] == minx)
		{
			minx = x[i]; miny = y[i];
			pmin = i;
		}
	}
	double t = x[pmin]; x[pmin] = x[0]; x[0] = t;
	t = y[pmin]; y[pmin] = y[0]; y[0] = t;
	for (int i = 1; i < N; i++)
	{
		alg[i] = atan2(y[i] - miny, x[i] - minx);
		perm[i] = i;
	}
	Qsort(1,N-1);
	stack[top++] = perm[0];
	stack[top++] = perm[1];
	for (int i = 2; i < N; i++)
	{
		while (top>=2 && !checkTop3(stack[top-2],stack[top-1],perm[i]))
		{
			top--;
		}
		stack[top++] = perm[i];
	}
	double ans = 0;
	for (int i = head+1; i < top; i++)
	{
		ans += dist(stack[i],stack[i-1]);
	}ans += dist(stack[top - 1], stack[head]);
	printf("%.2lf\n",ans);
	fclose(stdin); fclose(stdout);
}
