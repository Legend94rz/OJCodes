/*
ID: rz109291
LANG: C++
PROG: window
*/

#include <iostream>
#include <memory.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

char op;
struct Rect
{
	int x, y, X, Y;
	char id;
};
vector<Rect> rects;

int find(char id)
{
	for (size_t i = 0; i < rects.size(); i++)
	{
		if (rects[i].id==id)
		{
			return i;
		}
	}
	return -1;
}
double dfs(int s, int x, int y, int X, int Y)
{
	if (x == X || y == Y)return 0;
	if ( !(x<X && y>Y) ) return 0;
	if (s >= rects.size()-1)
		return 0;
	Rect r = rects[s + 1], isct;
	isct.x = max(x, r.x);isct.y = min(y, r.y);isct.X = min(X, r.X);isct.Y = max(Y, r.Y);
	if ((isct.X - isct.x)>0 && (isct.y - isct.Y) > 0)
	{
		double U = 0, L = 0, R = 0, D = 0;
		if (x < isct.x)
			L = dfs(s + 1, x, isct.y, isct.x, Y);
		if (y > isct.y)
			D = dfs(s + 1, x, y, isct.X, isct.y);
		if (X > isct.X)
			R = dfs(s + 1, isct.X, y, X, isct.Y);
		if (Y < isct.Y)
			U = dfs(s + 1, isct.x, isct.Y, X, Y);
		return (isct.X - isct.x)*(isct.y - isct.Y) + L + U + R + D;
	}
	else
		return dfs(s + 1, x, y, X, Y);
}

int main()
{
	freopen("window.in", "r", stdin); freopen("window.out", "w", stdout);
	Rect r;
	int old;
	double invad;
	int x, y, X, Y;
	while ( scanf("%c", &op)!=EOF  )
	{
		switch (op)
		{
		case 'w':
			scanf("(%c,%d,%d,%d,%d)\n", &r.id, &x, &y, &X, &Y);
			r.x = min(x, X); r.y = max(y, Y); r.X = max(x, X); r.Y = min(y, Y);
			rects.push_back(r);
			break;
		case 't':
			scanf("(%c)\n", &r.id);
			old = find(r.id);
			r = rects[old];
			rects.erase(rects.begin() + old);
			rects.push_back(r);
			break;
		case 'b':
			scanf("(%c)\n", &r.id);
			old = find(r.id);
			r = rects[old];
			rects.erase(rects.begin() + old);
			rects.insert(rects.begin(), r);
			break;
		case 'd':
			scanf("(%c)\n", &r.id);
			old = find(r.id);
			rects.erase(rects.begin() + old);
			break;
		case 's':
			scanf("(%c)\n", &r.id);
			old = find(r.id);
			r = rects[old];
			invad = dfs(old, r.x, r.y, r.X, r.Y);
			printf("%.3lf\n", (1.0 - invad / ((r.X-r.x)*(r.y-r.Y)))*100 );
			break;
		}
	}
	fclose(stdin); fclose(stdout);
}