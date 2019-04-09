#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N, K;

int main()
{
	cin >> N >> K;
	int ans = 0;
	while (K > 0)
	{
		if (N % 2 == 1)
		{
			N -= 1;
		}
		else
		{
			K -= 1;
			N /= 2;
		}
		ans += 1;
	}
	ans += N;
	cout << ans << endl;
}
