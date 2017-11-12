/*
ID: rz109291
PROG: starry
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct desc
{
	int l, r, t, b, cnt, no;
	char c;
	int w()const { return r - l; }
	int h()const { return b - t; }
};
struct point
{
	int x, y;
	point() {}
	point(int x, int y)
	{
		this->x = x; this->y = y;
	}
};
const int dx[] = { -1,-1,-1,0,0,1,1,1 };
const int dy[] = { -1,0,1,-1,1,-1,0,1 };
const int P = 8;
int W, H;
int map[200][200];
desc G[1001];
bool vis[120][120];

desc bfs(int x, int y, int no)
{
	point q[15000];
	desc res;
	int l = 0, r = 1;
	q[r] = point(x, y);
	vis[x][y] = true;
	res.b = res.t = x;
	res.l = res.r = y;
	res.c = '*';
	res.cnt = 1;
	res.no = map[x][y] = no;
	while (l != r)
	{
		point k = q[++l];
		for (int i = 0; i < P; i++)
		{
			int tx = k.x + dx[i];
			int ty = k.y + dy[i];
			if (!vis[tx][ty] && tx >= 0 && tx < H && ty >= 0 && ty < W && map[tx][ty] == '1')
			{
				q[++r] = point(tx, ty);
				vis[tx][ty] = true;
				res.b = max(res.b, tx);
				res.t = min(res.t, tx);
				res.l = min(res.l, ty);
				res.r = max(res.r, ty);
				map[tx][ty] = no;
				res.cnt++;
			}
		}
	}
	return res;
}
bool check(const desc& a, const point& b, int ox, int oy,int bno)
{
	for (int ia = a.t, ib = b.x; ia <= a.b; ia++, ib += ox)
	{
		for (int ja = a.l, jb = b.y; ja <= a.r; ja++, jb += oy)
		{
			if ( !(map[ia][ja] == a.no && map[ib][jb] == bno || map[ia][ja] != a.no && map[ib][jb] != bno))
				return false;
		}
	}
	return true;
}
bool checkt(const desc& a, const point& b, int ox, int oy, int bno)
{
	for (int ia = a.t, jb = b.y; ia <= a.b; ia++, jb += oy)
	{
		for (int ja = a.l, ib = b.x; ja <= a.r; ja++, ib += ox)
		{
			if (!(map[ia][ja] == a.no && map[ib][jb] == bno || map[ia][ja] != a.no && map[ib][jb] != bno))
				return false;
		}
	}
	return true;
}

bool match(const desc& a, const desc& b)
{
	if (a.cnt != b.cnt)return false;
	if (a.w() == b.w() && a.h() == b.h())
	{
		if (check(a, point(b.t, b.l), 1, 1,b.no))
			return true;
		if (check(a, point(b.t, b.r), 1, -1, b.no))
			return true;
		if (check(a, point(b.b, b.l), -1, 1, b.no))
			return true;
		if (check(a, point(b.b, b.r), -1, -1, b.no))
			return true;
	}
	if (a.w() == b.h() && a.h() == b.w())
	{
		if (checkt(a, point(b.t, b.l), 1, 1, b.no))
			return true;
		if (checkt(a, point(b.t, b.r), 1, -1, b.no))
			return true;
		if (checkt(a, point(b.b, b.l), -1, 1, b.no))
			return true;
		if (checkt(a, point(b.b, b.r), -1, -1, b.no))
			return true;
	}
	return false;
}

int main()
{
	freopen("starry.in", "r", stdin); freopen("starry.out", "w", stdout);
	char t;
	cin >> W >> H;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> t;
			map[i][j] = t;
		}
	}
	int S = 500;
	int L = S;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (map[i][j] == '1' && !vis[i][j])
			{
				G[L] = bfs(i, j, L);
				L++;
			}
		}
	}
	char z = 'a' - 1;
	for (int i = S; i < L; i++)
	{
		if (G[i].c == '*')
		{
			G[i].c = ++z;
			for (int j = 0; j < L; j++)
			{
				if (G[j].c == '*')
				{
					if (match(G[i], G[j]))
					{
						G[j].c = z;
					}
				}
			}
		}
	}
	//for (int i = S; i < L; i++)
	//{
	//	printf("%d: %d, %d || %d, %d || %c, %d\n", i, G[i].l, G[i].r, G[i].t, G[i].b, G[i].c, G[i].cnt);
	//}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (map[i][j] != '0')
				cout << G[map[i][j]].c;
			else
				cout << '0';
		}
		cout << endl;
	}
	fclose(stdin); fclose(stdout);
}