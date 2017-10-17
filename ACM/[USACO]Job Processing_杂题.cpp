/*
ID: rz109291
PROG: job
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <string.h>
using namespace std;
int n, m[2];
int cost[2][50];
int timeline[2000];
int fins[2][50];

int cmp(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}
int main()
{
	freopen("job.in", "r", stdin); freopen("job.out", "w", stdout);
	cin >> n >> m[0] >> m[1];
	for (int k = 0; k < 2; k++)
	{
		for (int i = 0; i < m[k]; i++)
			cin >> cost[k][i];
		qsort(cost[k], m[k], sizeof(int), cmp);
		memcpy(fins[k], cost[k], sizeof(cost[k]));
	}

	int ans[2] = { 0 };
	for (int k = 0; k < 2; k++)
	{
		for (int i = (k==0)?0:(n-1); i < n && i>=0; i += k==0?1:-1)
		{
			int p = 0;
			for (int j = 1; j < m[k]; j++)
			{
				if (fins[k][j] < fins[k][p])
				{
					p = j;
				}
			}
			timeline[i] = timeline[i] + fins[k][p];
			if (timeline[i] > ans[k])
				ans[k] = timeline[i];
			fins[k][p] += cost[k][p];
		}
	}
	cout << ans[0] << ' ' <<ans[1]<<endl;
	fclose(stdin); fclose(stdout);
}