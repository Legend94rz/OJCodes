/*
ID: rz109291
PROG: lgame
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class A
{
public:
	string s;
	int sco;
	A() {}
	A(string s, int sco)
	{
		this->s = s;
		this->sco = sco;
	}
};
string dict[40100];
int f[40100];

string origin;

vector<A> ans;
int S[256];
void init()
{
	S['e'] = S['i'] = S['s'] = 1;
	S['r'] = S['t'] = S['a'] = S['n'] = 2;
	S['o'] = S['l'] = 3;
	S['u'] = S['d'] = S['c'] = 4;
	S['y'] = S['p'] = S['g'] = S['h'] = S['b'] = S['m'] = 5;
	S['w'] = S['f'] = S['k'] = S['v'] = 6;
	S['q'] = S['j'] = S['z'] = S['x'] = 7;
}
int calc(string s, string t)
{
	int score = 0;
	bool* used = new bool[t.length()] {0};
	if (s.length() > t.length())return -1;
	for (size_t i = 0; i < s.length(); i++)
	{
		bool find = false;
		for (size_t j = 0; j < t.length(); j++)
		{
			if (!used[j] && t[j] == s[i])
			{
				used[j] = true;
				find = true;
				score += S[s[i]];
				break;
			}
		}
		if (!find)
			return -1;
	}
	return score;
}
bool cmp(const A& a, const A& b)
{
	if (b.sco < a.sco)
		return true;
	else if (b.sco == a.sco)
		return a.s < b.s;
	return false;
}
int main()
{
	ifstream fin("lgame.dict");
	int n = 0;
	for (int i = 0;; i++)
	{
		fin >> dict[i];
		if (dict[i] == ".")
			break;
		n++;
	}
	fin.close();
	freopen("lgame.in", "r", stdin); freopen("lgame.out", "w", stdout);
	init();
	cin >> origin;
	for (int i = 0; i < n; i++)
	{
		f[i] = calc(dict[i], origin);
		if (f[i] > 0)
			ans.push_back(A(dict[i], f[i]));
	}
	for (int i = 1; i < n; i++)
	{
		if (f[i] > 0)
			for (int j = 0; j < i; j++)
			{
				if (f[j] > 0)
				{
					int tmp = calc(dict[i] + dict[j], origin);
					if (tmp > 0)
						if (dict[i] < dict[j])
							ans.push_back(A(dict[i] + " " + dict[j], tmp));
						else
							ans.push_back(A(dict[j] + " " + dict[i], tmp));
				}
			}
	}


	sort(ans.begin(), ans.end(), cmp);
	if (ans.size() > 0)
	{
		cout << ans[0].sco << endl;
		cout << ans[0].s << endl;
		for (size_t i = 1; i < ans.size() && ans[i].sco == ans[i - 1].sco; i++)
		{
			cout << ans[i].s << endl;
		}
	}
	else
		cout << 0 << endl;
	fclose(stdin); fclose(stdout);
}
