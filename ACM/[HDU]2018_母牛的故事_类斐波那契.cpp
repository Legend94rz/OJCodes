#include <iostream>
using namespace std;
int T, n;
__int64 f[100];
int main()
{
	for (;;)
	{
		cin >> n;
		if (n == 0)
			break;
		f[0] = 0; f[1] = 1; f[2] = 2; f[3] = 3; f[4] = 4;
		for (int j = 5; j <= n; j++)
		{
			f[j] = f[j - 1] + f[j - 3];
		}
		cout << f[n] << endl;
	}
}
