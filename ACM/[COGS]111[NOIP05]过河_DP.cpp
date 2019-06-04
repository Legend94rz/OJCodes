#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>
#include <tuple>
using namespace std;

vector<int> stone;
vector<int> ztone;
int f[200];
int S, T, L, M;

int main()
{
	cin >> L;
	cin >> S >> T >> M;
	int t = -1;
	stone.push_back(0);
	for (int i = 0;i < M;i++)
	{
		cin >> t;
		stone.push_back(t);
	}
	sort(stone.begin(), stone.end(), less<int>());

	int zipped = 0;
	for (int i = 1;i < stone.size;i++)
	{
		int g = stone[i] - zipped;
		ztone.push_back(g);
		if (stone[i] - stone[i-1] > S*T)
		{
			zipped += (stone[i]-stone[i-1])-S*T;
		}
	}


	memset(f, 0x3f, sizeof(f));
	f[0] = 0;

}
