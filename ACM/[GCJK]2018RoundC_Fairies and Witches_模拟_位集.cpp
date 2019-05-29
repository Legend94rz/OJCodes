#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int T, N;
int L[20][20];
vector<vector<int>> C[16][16];

bool is_polygon(vector<int>& lens)
{
	int tot = 0;
	int mx = 0;
	for (auto e : lens)
	{
		mx = max(mx, e);
		tot += e;
	}
	return (tot - mx) > mx;
}

bool is_used(int bits, int i)
{
	return ((bits>>i) & 1);
}

void combinations(int Lo, int Hi, const int n, const int k, vector<int>& nodes)
{
	if (nodes.size() == k)
	{
		C[n][k].push_back( vector<int>(nodes) );
		return;
	}

	for (int i = Lo;i <= Hi;i++)
	{
		nodes.push_back(i);
		combinations(i + 1, Hi + 1, n, k, nodes);
		nodes.pop_back();
	}
}

int search_pair(int mask, const vector<int>& nodes, vector<int>& lens)
{
	if (mask + 1 == 1 << nodes.size())
	{
		return is_polygon(lens);
	}
	int ans = 0;
	for (int i = 0; i < nodes.size()-1; i++)
	{
		if (!is_used(mask, i))
		{
			for (int j = i+1; j < nodes.size(); j++)
			{
				if (!is_used(mask, j) && L[nodes[i]][nodes[j]] > 0)
				{
					lens.push_back(L[nodes[i]][nodes[j]]);
					ans+=search_pair(mask | (1 << i) | (1 << j), nodes, lens);
					lens.pop_back();
				}					
			}
			break;
		}
	}
	return ans;
}

int main()
{
	for (int n = 6;n <= 15;n++)
		for (int k = 6;k <= n;k += 2)
		{
			vector<int> tmp = vector<int>();
			combinations(0, n - k, n, k, tmp);
		}


	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> L[i][j];
			}
		}


		int res = 0;
		for (int k = 6; k <= N; k+=2)
		{
			for (auto nodes : C[N][k])
			{
				vector<int> tmp = vector<int>();
				res += search_pair(0, nodes, tmp);
			}
		}
		printf("Case #%d: %d\n", t, res);
	}
}

