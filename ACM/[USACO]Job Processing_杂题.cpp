/*
ID: rz109291
PROG: job
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n, m1, m2;
int costA[50], costB[50],finsA[50],finsB[50];
int curtime;
int timeline[2000];

int cmp(const void* a, const void* b)
{
	int x = *(const int*)a;
	int y = *(const int*)b;
	if (a > b)return 1;
	if (a < b)return -1;
	return 0;
}
int main()
{
	//freopen("job.in", "r", stdin); freopen("job.out", "w", stdout);
	cin >> n >> m1 >> m2;
	for (int i=0;i<m1;i++)
		cin >> costA[i];
	for (int i = 0; i < m2; i++)
		cin >> costB[i];
	qsort(costA, m1, sizeof(int), cmp);
	qsort(costB, m2, sizeof(int), cmp);
	curtime = 0;
	for (int i = 0;i<n;)
	{
		vector<int> availables;
		for (int j = 0; j < m1; j++)
		{
			if (finsA[j] <= curtime)
				availables.push_back(j);
		}//find available A machines

		int tmp;
		for (int j = 0; j < availables.size(); j++,i++)
		{
			timeline[i] = curtime + costA[availables[j]];
			if (j == 0)
			{
				tmp = timeline[i];
			}
		}
		curtime = tmp;
	}




	//for (int i = 0; i < n; i++)
	//{
	//	cout << timeline[i] << endl;
	//}

	fclose(stdin); fclose(stdout);
}