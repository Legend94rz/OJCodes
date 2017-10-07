#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
char buf[256];
vector<string> q;
string deal(string s)
{
	int cnt[10] = { 0 };
	string t;
	char sz[16] = { 0 };
	for (size_t i = 0; i < s.length(); i++)
	{
		cnt[s[i] - '0']++;
	}

	for (int i = 0; i < 10; i++)
		if (cnt[i] > 0)
		{
			_ltoa(cnt[i], sz, 10);
			t += sz;
			_ltoa(i, sz, 10);
			t += sz;
		}
	return t;
}
int find(const string& s)
{
	for (size_t i = 0; i < q.size(); i++)
	{
		if (q[i] == s)
			return i;
	}
	return -1;
}
int main()
{
	for (;;)
	{
		memset(buf,0,sizeof(buf));
		scanf("%s", buf);
		string s(buf);
		if (s == "-1")break;
		q.clear();
		q.push_back(s);
		bool selfInv = false;
		for (int i = 0; i < 15; i++)
		{
			s = deal(s);
			int p = find(s);
			if (p < 0)
				q.push_back(s);
			else if (p == (int)q.size() - 1)
			{
				if (q.size() == 1)
				{//self-inv
					printf("%s is self-inventorying\n", buf);
				}
				else
				{//self-inv after
					printf("%s is self-inventorying after %d steps\n", buf, q.size()-1);
				}
			}
			else
			{//inv loop
				printf("%s enters an inventory loop of length %d\n", buf, q.size() - p);
			}
			if (p >= 0)
			{
				selfInv = true;
				break;
			}
		}
		if (!selfInv)
		{
			printf("%s can not be classified after 15 iterations\n", buf);
		}
	}
}