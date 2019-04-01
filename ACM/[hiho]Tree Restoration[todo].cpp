#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, k;
int dep[500];
int at_dep[500][500];
int L_at[500];
int leaf[500];
int dst[500][500];
int cur[500];
int pre[500];

bool check()
{

}

int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		cin >> L_at[i];
		cur[i] = 1;
	}
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= L_at[i]; j++)
		{
			cin >> at_dep[i][j];
			dep[at_dep[i][j]] = i;
		}
	for (int i = 1; i <= k; i++)
		cin >> leaf[i];

	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= k; j++)
			cin >> dst[i][j];



	for(int i=2;i<=k;i++)
		for (int d = min(dep[leaf[i]], dep[leaf[i - 1]]) - 1; d; d--)
		{
			if (check())
			{


				break;
			}
			else
			{
				cur[d]++;
			}

		}


}
