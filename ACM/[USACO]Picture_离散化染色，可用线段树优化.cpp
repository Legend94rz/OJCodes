/*
ID: rz109291
PROG: picture
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

class Line
{
public:
	int type;//1 - Ê¼±ß; -1 - ÖÕ±ß
	int s, t;
	int hv;
	Line() {}
	Line(int s, int t, int hv, int type)
	{
		this->s = s; this->t = t; this->hv = hv; this->type = type;
	}
	bool operator<(const Line& b)
	{
		//assume this and b is all hori or vert
		if (this->hv < b.hv)return true;
		if (this->hv == b.hv && this->type == 1 && b.type == -1)
			return true;
		return false;
	}
};
int N;
vector<Line> hori, vert;
int flag[30000];
const int OFFSET = 10000;

int perimeter(vector<Line>& segs)
{
	int cnt = 0;
	sort(segs.begin(), segs.end());
	memset(flag, 0, sizeof(flag));
	for (int i = 0; i < segs.size(); i++)
	{
		Line& l = segs[i];
		for (int j = l.s; j < l.t; j++)
		{
			flag[j + OFFSET] += l.type;
			if (l.type == 1 && flag[j + OFFSET] == 1 || l.type == -1 && flag[j + OFFSET] == 0)
				cnt++;
		}
	}
	return cnt;
}

int main()
{
	freopen("picture.in", "r", stdin); freopen("picture.out", "w", stdout);
	cin >> N;
	int a, b, c, d;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b >> c >> d;
		hori.push_back(Line(a, c, b, 1));
		hori.push_back(Line(a, c, d, -1));
		vert.push_back(Line(b, d, a, 1));
		vert.push_back(Line(b, d, c, -1));
	}

	cout << perimeter(hori)+perimeter(vert) << endl;

	fclose(stdin); fclose(stdout);
}
