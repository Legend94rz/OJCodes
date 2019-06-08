#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;

int n;
int a[2100000];
void qsort(int s, int t)
{
	int i = s, j = t, u, k = a[(rand()%(t-s+1))+s];
	while (i <= j)
	{
		while (a[i] < k) i++;
		while (a[j] > k) j--;
		if (i <= j)
		{
			u = a[i]; a[i] = a[j]; a[j] = u;
			i++; j--;
		}
	}
	if (s < j)qsort(s, j);
	if (i < t)qsort(i, t);
}

int main()
{
	freopen("sorttest.in", "r", stdin); freopen("sorttest.out", "w", stdout);
	srand((unsigned int)time(NULL));

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	qsort(1, n);
	printf("%d", a[1]);
	for (int i = 2; i <= n; i++)
	{
		printf(" %d", a[i]);
	}
	printf("\n");

	fclose(stdin); fclose(stdout);
}