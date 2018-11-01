/*
ID: rz109291
PROG: fence4
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct point
{
	double x, y;
};

int N;
point pt[250];
point v;
const double eps = 0.00001;
bool vis[250];
int cnt;

point pt2vec(point st, point ed)
{
	point t;
	t.x = ed.x - st.x; t.y = ed.y - st.y;
	return t;
}

bool isCross(point p1, point p2, point p3, point p4)
{
	///todo: 没有判断重合，对于特殊构造数据是不正确的。
	point vec1 = pt2vec(p1, p2);
	point vec2 = pt2vec(p1, p3);
	point vec3 = pt2vec(p1, p4);
	double t1 = (vec1.x*vec2.y - vec1.y*vec2.x);
	double t2 = (vec1.x*vec3.y - vec1.y*vec3.x);
	bool f1 = (t1 * t2  <= 0) && ( t1!=0 || t2 !=0);
	vec1 = pt2vec(p3, p4);
	vec2 = pt2vec(p3, p1);
	vec3 = pt2vec(p3, p2);
	t1 = (vec1.x*vec2.y - vec1.y*vec2.x);
	t2 = (vec1.x*vec3.y - vec1.y*vec3.x);
	bool f2 = (t1 * t2 <= 0) && (t1 != 0 || t2 != 0);
	return f1 && f2;
}

bool CanSeen(point p1, point p2, int I)
{
	if (abs(p1.x - p2.x) < eps && abs(p1.y - p2.y) < eps) return false;
	bool ok = false;
	for (int i = 0; i < N; i++)
	{
		if (i == I)continue;
		bool t1 = isCross(v, p1, pt[(i - 1 + N) % N], pt[i]);
		bool t2 = isCross(v, p2, pt[(i - 1 + N) % N], pt[i]);
		if (t1 && t2)return false;
		ok |= t1 || t2;
	}
	if (!ok)return true;
	point mid;
	mid.x = (p1.x + p2.x) / 2;
	mid.y = (p1.y + p2.y) / 2;
	return CanSeen(p1, mid,I) || CanSeen(mid, p2,I);
}

int main()
{
	freopen("fence4.in", "r", stdin); freopen("fence4.out", "w", stdout);
	cin >> N;
	cin >> v.x >> v.y;
	for (int i = 0; i < N; i++)
	{
		cin >> pt[i].x >> pt[i].y;
	}

	for (int i = 0; i < N; i++)
	{
		vis[i] = CanSeen(pt[(i - 1 + N) % N], pt[i], i);
		if (vis[i])
			cnt++;
	}

	cout << cnt << endl;
	for (int i = 0; i < N; i++)
	{
		if (vis[0] && i==N-1)
			printf("%d %d %d %d\n", (int)pt[0].x, (int)pt[0].y, (int)pt[N - 1].x, (int)pt[N - 1].y);
		if (i>0 && vis[i])
			printf("%d %d %d %d\n", (int)pt[i - 1].x, (int)pt[i - 1].y, (int)pt[i].x, (int)pt[i].y);
	}
	fclose(stdin); fclose(stdout);
}