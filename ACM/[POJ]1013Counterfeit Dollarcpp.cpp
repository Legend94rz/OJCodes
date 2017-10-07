#include <iostream>
#include <string>
using namespace std;
int T;
int flag[30];
string L[3], R[3], result[3];
char* ans[] = { "light","heavy" };
bool check(int c, int x)
{
	int h[30];
	memset(h, 0, sizeof(h));
	h[c] = x;
	for (int k = 0; k < 3; k++)
	{
		int s1 = 0, s2 = 0;
		for (int i = 0; i < L[k].length(); i++)
		{
			s1+=h[L[k][i]-'A'];
		}
		for(int i=0;i<R[k].length();i++)
		{
			s2+=h[R[k][i]-'A'];
		}
		if(s1<s2 && result[k] != "down" || s1 == s2 &&result[k] != "even"|| s1>s2&&result[k] != "up")
			return false;
	}
	return true;
}
int main()
{
	cin >> T;
	while (T--)
	{
		for (int i = 0; i < 3; i++)
			cin >> L[i] >> R[i] >> result[i];
		for (int i = -1; i <= 1; i += 2)
			for (char c = 'A'; c <= 'L'; c++)
			{
				if (check(c - 'A', i))
					printf("%c is the counterfeit coin and it is %s.\n", c, ans[(i + 1) / 2]);
			}
	}
}
