#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> valid_plant;
int row_state[15];
int x;
int f[20][1 << 15];
const int P = 100000000;

bool can_plant(int rs, int plan)
{
	return (rs&plan)==0;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0;j < m;j++)
		{
			cin >> x;
			row_state[i] += (!x) << (m-j-1);
		}

	for (int i = 0; i < (1<<m); i++)
	{
		if (!(i&(i << 1)))
			valid_plant.push_back(i);
	}

	for (int i = 0; i < valid_plant.size(); i++)
	{
		if (can_plant(row_state[0], valid_plant[i]))
			f[0][i] = 1;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < valid_plant.size(); j++)
		{
			if (can_plant(row_state[i], valid_plant[j]))
				for (int k = 0; k < valid_plant.size(); k++)
				{
					if (can_plant(row_state[i-1], valid_plant[k]) && !(valid_plant[k] & valid_plant[j]))
						f[i][j] = (f[i][j] + f[i - 1][k])%P;
				}
		}
	}

	int ans = 0;
	for (int i = 0; i < valid_plant.size(); i++)
	{
		ans = (ans + f[n - 1][i])%P;
	}
	cout << ans << endl;
}
