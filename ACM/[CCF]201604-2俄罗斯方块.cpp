#include <iostream>
#include <string.h>
using namespace std;
int m[20][11], ans[20][11], temp[20][11];
int block[5][5];
int s;
bool check(int step)
{
	memcpy(ans, m, sizeof(m));
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			ans[step + i][s + j - 1] += block[i][j];
			if (ans[step + i][s + j - 1] > 1)
				return false;
		}
	}
	memcpy(temp, ans, sizeof(ans));
	return true;
}
int main()
{
	for (int i = 1; i <= 15; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			cin >> m[i][j];
		}
	}
	for (int i = 1; i <= 10; i++)
	{
		m[16][i] = 1;
	}
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			cin >> block[i][j];
		}
	}
	cin >> s;
	for (int step = 0; step <= 16; step++)
	{
		if (!check(step))
		{
			for (int i = 1; i <= 15; i++)
			{
				for (int j = 1; j <= 10; j++)
				{
					cout << temp[i][j] << ' ';
				}
				cout << endl;
			}
			//system("pause");
			return 0;
		}
	}
}