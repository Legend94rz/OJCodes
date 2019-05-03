#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int T;
int cnt[256];
int K;
string s;
int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> s;
		cin >> K;
		memset(cnt, 0, sizeof(cnt));
		int l = 0;
		long long ans = 0;
		for (int i = 0; i < s.length(); i++)
		{
			cnt[s[i]]++;
			while (cnt[s[i]] > K)
			{
				cnt[s[l]]--;
				l++;
			}
			ans += i - l + 1;
		}
		cout << ans << endl;
	}
}
