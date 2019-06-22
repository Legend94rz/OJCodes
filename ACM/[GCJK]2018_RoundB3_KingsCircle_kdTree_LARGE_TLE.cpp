#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string.h>
using namespace std;
typedef long long Int;
struct Point
{
	Int x, y;
};
struct Node
{
	Point v;
	int left, right;
};


int T, N, M;
Int A, B, C, D, E, F;
Point p[500010];
Node tree[500010];
int np;

bool lessX(const Point& a, const Point& b) { return a.x < b.x; }
bool lessY(const Point& a, const Point& b) { return a.y < b.y; }

int make_tree(int l, int r, int depth)
{
	if (l >= r)return -1;
	int mid = (l + r) / 2;
	if (depth % 2 == 0)
		sort(p + l, p + r, lessX);
	else
		sort(p + l, p + r, lessY);
	int t = np++;
	tree[t].v = p[mid];
	tree[t].left = make_tree(l, mid, depth + 1);
	tree[t].right = make_tree(mid + 1, r, depth + 1);
	return t;
}

void find(int r, Int sx, Int tx, Int sy, Int ty, int depth, Int& ans)
{
	if (r < 0 || tx < sx || ty < sy) return;
	Point o = tree[r].v;
	//Point o;
	//o.x = p[tree[r].v].x;
	//o.y = p[tree[r].v].y;
	if (o.x >= sx && o.x <= tx && o.y >= sy && o.y <= ty)
		ans += 1;
	if (depth % 2 == 0)
	{
		if (o.x >= sx)
			find(tree[r].left, sx, tx, sy, ty, depth + 1, ans);
		if (o.x <= tx)
			find(tree[r].right, sx, tx, sy, ty, depth + 1, ans);
	}
	else
	{
		if (o.y >= sy)
			find(tree[r].left, sx, tx, sy, ty, depth + 1, ans);
		if (o.y <= ty)
			find(tree[r].right, sx, tx, sy, ty, depth + 1, ans);
	}
}

int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		memset(tree, 0, sizeof(tree));
		memset(p, 0, sizeof(p));
		np = 0;
		cin >> N >> p[0].x >> p[0].y >> A >> B >> C >> D >> E >> F >> M;
		Int minx, miny, maxx, maxy;
		minx = maxx = p[0].x;
		miny = maxy = p[0].y;
		for (int i = 1; i < N; i++)
		{
			p[i].x = (A * p[i - 1].x + B * p[i - 1].y + C) % M;
			p[i].y = (D * p[i - 1].x + E * p[i - 1].y + F) % M;
			//cin >> p[i].x >> p[i].y;
			minx = min(minx, p[i].x); maxx = max(maxx, p[i].x);
			miny = min(miny, p[i].y); maxy = max(maxy, p[i].y);
		}
		int root = make_tree(0, N, 0);
		Int cannot = 0;
		for (int i = 0; i < N; i++)
		{
			Int left_upper = 0;
			Int left_lower = 0;
			Int right_upper = 0;
			Int right_lower = 0;
			find(root, minx, p[i].x - 1, miny, p[i].y - 1, 0, left_upper);
			find(root, minx, p[i].x - 1, p[i].y + 1, maxy, 0, left_lower);
			find(root, p[i].x + 1, maxx, miny, p[i].y - 1, 0, right_upper);
			find(root, p[i].x + 1, maxx, p[i].y + 1, maxy, 0, right_lower);
			cannot += left_upper * right_lower + left_lower * right_upper;
		}
		Int all = (N * (N - 1) * (N - 2)) / 6;
		printf("Case #%d: %lld\n", t, all - cannot);
	}
}
