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
using namespace std;
int n, m1, m2;
int costA[50], costB[50];
int curtime;
int timeline[2000];
vector<int> finsA(50), finsB(50);

int cmp(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}
int main()
{
	/*
	----- our output ---------
	3_5
	---- your output ---------
	3_7
	--------------------------
	------ Data for Run 1 [length=16 bytes] ------
	5 2 3
	1 1
	3 1 4
	----------------------------


	----- our output ---------
	5_11
	---- your output ---------
	5_13
	--------------------------
	------ Data for Run 2 [length=14 bytes] ------
	2 2 2
	3 5
	8 5
	----------------------------



	----- our output ---------
	10_14
	---- your output ---------
	10_4
	--------------------------
	------ Data for Run 3 [length=13 bytes] ------
	10 1 2
	1z  
	2 3
	----------------------------

	----- our output ---------
	27_103
	---- your output ---------
	38_109
	--------------------------
	------ Data for Run 4 [length=15 bytes] ------
	10 2 1
	3 19
	10
	----------------------------

	*/

	//freopen("job.in", "r", stdin); freopen("job.out", "w", stdout);
	cin >> n >> m1 >> m2;
	for (int i = 0; i < m1; i++)
		cin >> costA[i];
	for (int i = 0; i < m2; i++)
		cin >> costB[i];
	qsort(costA, m1, sizeof(int), cmp);
	qsort(costB, m2, sizeof(int), cmp);

	int ans = 0;
	curtime = timeline[0];
	for (int i = 0; i < n;)
	{
		vector<int> availables;
		for (int j = 0; j < m1; j++)
		{
			if (finsA[j] <= curtime)
				availables.push_back(j);
		}//find available A machines

		for (int j = 0; j < availables.size() && i < n; j++, i++)
		{
			finsA[availables[j]] = timeline[i] = max(timeline[i], curtime) + costA[availables[j]];
			if (timeline[i] > ans)
				ans = timeline[i];
		}
		curtime = *min_element(finsA.begin(), finsA.begin() + m1);
	}
	cout << ans << ' ';
	ans = 0;
	curtime = timeline[0];
	for (int i = 0; i < n; )
	{
		vector<int> availables;
		for (int j = 0; j < m2; j++)
		{
			if (finsB[j] <= curtime)
				availables.push_back(j);
		}
		for (int j = min((int)availables.size() - 1, n - i - 1); j >= 0 && i < n; j--, i++)
		{
			finsB[availables[j]] = timeline[i] = max(timeline[i], curtime) + costB[availables[j]];
			if (timeline[i] > ans)
				ans = timeline[i];
		}
		curtime = *min_element(finsB.begin(), finsB.begin() + m2);
	}
	cout << ans << endl;


	//for (int i = 0; i < n; i++)
	//{
	//	cout << timeline[i] << endl;
	//}

	fclose(stdin); fclose(stdout);
}