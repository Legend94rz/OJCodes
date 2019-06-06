#include <iostream>
#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct job
{
	int B, J;
};

job jobs[10001];
int N, T;
int cmp(const void* a, const void* b)
{
	job A = *(job*)a;
	job B = *(job*)b;
	if (A.J > B.J)
		return -1;
	else
		return 1;
}

int main()
{
	freopen("commando.in", "r", stdin); freopen("commando.out", "w", stdout);
	for (int t=1;;t++)
	{
		cin >> N;
		int assign = 0;
		int finish = 0;
		if (N == 0)
			break;
		for (int i = 0; i < N; i++)
		{
			cin >> jobs[i].B >> jobs[i].J;
		}
		qsort(jobs, N, sizeof(job), cmp);
		for (int i = 0; i < N; i++)
		{
			assign += jobs[i].B;
			finish = max(finish, assign + jobs[i].J);
		}
		printf("Case %d: %d\n", t, finish);
	}
	fclose(stdin); fclose(stdout);
}