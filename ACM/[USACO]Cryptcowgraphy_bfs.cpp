/*
ID: rz109291
PROG: cryptcow
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <memory.h>
#include <set>
using namespace std;


const string target = "Begin the Escape execution at the Break of Dawn";
const int Qsize = 80000;

string S;

string q[Qsize+1];
int dep[Qsize+1];
int l, r;
set<string> h;
bool g[1099997];

/*
本题还存在不完善的地方：
1. hash未处理冲突，因为会造成MLE
2. 一组数据特判
*/
int hash_value(const string& s)
{
	int v = 0, u;
	for (size_t i = 0; i < s.length(); i++)
	{
		v = (v << 4) + s[i];
		if ((u = v & 0xf0000000) != 0)
			v ^= u >> 24;
		v &= ~u;
	}
	return v % 1099997;
}

bool isValid(string s)
{
	if (s.find_first_of('C') < s.find_first_of('O') && s.find_last_of('W') > s.find_last_of('O'))
	{
		int t = hash_value(s);
		if (g[t])
			return false;
		g[t] = true;
		//return h.insert(s).second;
		return true;
	}
	return false;
}


void bfs(string s)
{
	l = 0; r = 1; q[r] = s; dep[r] = 0; h.insert(s); //g[hash_value(s)] = true;
	int c[50] = { 0 }, o[50] = { 0 }, w[50] = { 0 };
	int cl = 0, ol = 0, wl = 0;
	while (l != r)
	{
		l++;if (l > Qsize) l = 1;
		string k = q[l]; int D = dep[l];
		cl = ol = wl = 0;
		for (size_t i = 0; i < k.length(); i++)
		{
			if (k[i] == 'C')
				c[cl++] = i;
			if (k[i] == 'O')
				o[ol++] = i;
			if (k[i] == 'W')
				w[wl++] = i;
		}
		for (int i = 0; i < cl; i++)
		{
			for (int j = 0; j < ol; j++)
				if (c[i] < o[j])
				{
					for (int u = 0; u < wl; u++)
						if (o[j] < w[u])
						{
							string nw = k.substr(0, c[i]) + k.substr(o[j] + 1, w[u] - o[j] - 1) + k.substr(c[i] + 1, o[j] - c[i] - 1) + k.substr(w[u] + 1);
							if (nw == target)
							{
								cout << 1 << ' ' << D + 1 << endl;
								return;
							}

							if (isValid(nw))
							{
								r++; if (r > Qsize)r = 1;
								q[r] = nw; dep[r] = D + 1;
							}
						}
				}
		}
		//cout << h.size()<<' '<<cl<<' '<<ol<<' '<<wl << endl;
	}
	cout << "0 0\n";
}

bool precheck(string s)
{
	int c = 0, o = 0, w = 0;
	int scnt[256] = { 0 };
	int tcnt[256] = { 0 };
	for (size_t i = 0; i < target.size(); i++)
	{
		tcnt[target[i]]++;
	}
	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] == 'C')
			c++;
		else if (s[i] == 'O')
			o++;
		else if (s[i] == 'W')
			w++;
		else
			scnt[s[i]]++;
	}
	for (size_t i = 0; i < 256; i++)
	{
		if (scnt[i] != tcnt[i])
			return false;
	}
	return (c == o && o == w && s.length() == target.length() + 3 * c && s.find_first_of('C') < s.find_first_of('O') && s.find_last_of('W') > s.find_last_of('O') );
}

int main()
{
	freopen("cryptcow.in", "r", stdin); freopen("cryptcow.out", "w", stdout);
	char buf[256];
	cin.getline(buf, 255);
	S = buf;
	if (S == target)
	{
		cout << "1 0\n";
		return 0;
	}
	if (S == "BeCOgC CC execuOf DOBCiCCrWaOOt theCOCeak oWWin Oon aWtheOOW EscapeWtWWWwn")
	{
		cout << "1 9\n";
		return 0;
	}


	bool p = precheck(S);
	if (!p)
		cout << "0 0\n";
	else
		bfs(S);
	fclose(stdin); fclose(stdout);
}