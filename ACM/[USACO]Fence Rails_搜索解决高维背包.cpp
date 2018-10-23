/*
ID: rz109291
PROG: fence8
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

int bags, its;
int sz[60], cost[1030], Ssz[60], Scost[1030];

void qsort(int* a, int s, int t)
{
	int k = a[(s + t) / 2], i = s, j = t;
	do
	{
		while (a[i] < k) i++;
		while (a[j] > k) j--;
		if (i <= j)
		{
			int u = a[i]; a[i] = a[j]; a[j] = u;
			i++; j--;
		}
	} while (i <= j);
	if (s < j)qsort(a, s, j);
	if (i < t)qsort(a, i, t);
}

bool dfs(int it, int st, int* rest, int curWaste, const int maxWaste)
{
	if (curWaste > maxWaste)
		return false;
	if (it < 1)
		return true;

	for (int i = st; i <= bags; i++)
	{
		if (rest[i] >= cost[it])
		{
			rest[i] -= cost[it];
			int k = 0, J;
			if (rest[i] < cost[1])
				k = rest[i];
			if (cost[it - 1] == cost[it])
				J = i;
			else
				J = 1;
			if (dfs(it - 1, J, rest, curWaste+k, maxWaste))
				return true;
			rest[i] += cost[it];
		}
	}
	return false;
}


bool check(int mid)
{
	int rest[60], maxWaste = 0;
	memcpy(rest, sz, sizeof(sz));
	return dfs(mid, 1, rest, 0, Ssz[bags]-Scost[mid]);
}

int main()
{
	freopen("fence8.in", "r", stdin); freopen("fence8.out", "w", stdout);
	cin >> bags;
	for (int i = 1; i <= bags; i++)
	{
		cin >> sz[i];
	}


	cin >> its;
	for (int i = 1; i <= its; i++)
	{
		cin >> cost[i];
	}
	qsort(cost, 1, its);
	qsort(sz, 1, bags);

	for (int i = 1; i <= bags; i++)
		Ssz[i] = Ssz[i - 1] + sz[i];
	for (int i = 1; i <= its; i++)
		Scost[i] = Scost[i - 1] + cost[i];

	int s = 0, l = 0, r = 0;
	for (r = 1; r <= its; r++)
	{
		if (s + cost[r] > Ssz[bags])break;
		s += cost[r];
	}
	r -= 1;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid))
			l = mid + 1;
		else
			r = mid - 1;
	}
	cout << r << endl;


	fclose(stdin); fclose(stdout);
}