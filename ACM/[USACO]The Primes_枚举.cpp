/*
ID: rz109291
PROG: prime3
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <memory.h>
#include <vector>
using namespace std;

int a[6][6], S, Q;

vector<int> P;
vector<int> PSE[10][10];

vector<int> PStQ;
vector<int> PNoEven;
bool prim[100000];
int Results[500][6][6], cnt;


bool isPrime(int x)
{
	for (int i = 2; i <= sqrt(x) + 1; i++)
	{
		if (x%i == 0)
			return false;
	}
	return true;
}

void Init()
{
	for (int i = 10001; i < 100000; i++)
	{
		int s = 0, x = i;
		bool noEven = true;
		bool has0 = false;
		while (x > 0)
		{
			int t = x % 10;
			s += t;
			x /= 10;
			if ((t & 1)==0 || t==5)
				noEven = false;
			if (t == 0)
				has0 = true;
		}
		if (s == S && isPrime(i))
		{
			P.push_back(i);
			prim[i] = true;
			if (i / 10000 == Q && !has0)
				PStQ.push_back(i);
			if (noEven)
				PNoEven.push_back(i);
			PSE[i / 10000][i % 10].push_back(i);
		}
	}
}

bool check(int x, int axis)
{
	int num = 0;
	for (int i = 0; i < 5; i++)
	{
		int t = axis == 0 ? a[x][i] : a[i][x];
		num = 10 * num + t;
	}
	return prim[num];
}

bool CMP(int x, int y)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (Results[x][i][j] > Results[y][i][j])
				return true;
			else if (Results[x][i][j] < Results[y][i][j])
				return false;
		}
	}
	return false;
}

int main()
{
	//freopen("prime3.in", "r", stdin); freopen("prime3.out", "w", stdout);
	cin >> S >> Q;
	Init();
	for (int i1 = 0; i1 < PStQ.size(); i1++)
	{
		int a1 = PStQ[i1];
		for (int i = 0, u=10000; i < 5; i++, u/=10)
		{
			a[0][i] = a1 / u % 10;
		}

		for (int i2 = 0; i2 < PStQ.size(); i2++)
		{
			int a2 = PStQ[i2];
			for (int i = 1, u = 1000; i < 5; i++, u /= 10)
			{
				a[i][0] = a2 / u % 10;
			}
			for (int i3 = 0; i3 < PNoEven.size(); i3++)
			{
				int a3 = PNoEven[i3];
				if (a3 / 10000 == a[4][0])
				{
					for (int i = 1, u = 1000; i < 5; i++, u /= 10)
					{
						a[4][i] = a3 / u % 10;
					}

					for (int i4 = 0; i4 < PNoEven.size(); i4++)
					{
						int a4 = PNoEven[i4];
						if ((a4 / 10000 == a[0][4]) && (a4 % 10 == a[4][4]))
						{
							for (int i = 1, u = 1000; i < 4; i++, u /= 10)
							{
								a[i][4] = a4 / u % 10;
							}

							for (int i5 = 0; i5 < PSE[Q][a[4][4]].size(); i5++)	//Ö÷¶Ô½Ç
							{
								int a5 = PSE[Q][a[4][4]][i5];
								a[1][1] = a5 / 1000 % 10; a[2][2] = a5 / 100 % 10; a[3][3] = a5 / 10 % 10;

								for (a[1][2] = 0; a[1][2] <= 9; a[1][2]++)
								{
									a[1][3] = S - a[1][0] - a[1][1] - a[1][2] - a[1][4];
									if (a[1][3] < 0 || a[1][3]>9) continue;

									a[3][2] = S - a[0][2] - a[1][2] - a[2][2] - a[4][2];
									if (a[3][2] < 0 || a[3][2]>9) continue;

									a[2][3] = S - a[0][3] - a[1][3] - a[3][3] - a[4][3];
									if (a[2][3] < 0 || a[2][3]>9) continue;

									a[2][1] = S - a[2][0] - a[2][2] - a[2][3] - a[2][4];
									if (a[2][1] < 0 || a[2][1]>9) continue;

									a[3][1] = S - a[0][1] - a[1][1] - a[2][1] - a[4][1];
									if (a[3][1] < 0 || a[3][1]>9 || a[3][1] != S - a[3][0] - a[3][2] - a[3][3] - a[3][4]) continue;

									if (!prim[a[4][0] * 10000 + a[3][1] * 1000 + a[2][2] * 100 + a[1][3] * 10 + a[0][4]])
										continue;

									if (check(1, 0) && check(2, 0) && check(3, 0) && check(1, 1) && check(2, 1) && check(3, 1))
									{
										memcpy(Results[cnt], a, sizeof(a));
										cnt++;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	int tmp[6][6];
	for (bool f=true;f;)
	{
		f = false;
		for (int i = 1; i < cnt; i++)
		{
			if (CMP(i - 1, i))
			{
				f = true;
				memcpy(tmp, Results[i - 1], sizeof(tmp));
				memcpy(Results[i - 1], Results[i], sizeof(tmp));
				memcpy(Results[i], tmp, sizeof(tmp));
			}
		}
	}
	
	
	if (cnt>0)
		for (int k = 0; k < cnt; k++)
		{
			if (k > 0)
				cout << endl;
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					cout << Results[k][i][j];
				}
				cout << endl;
			}
		}
	else
		cout << "NONE" << endl;
	fclose(stdin); fclose(stdout);
}