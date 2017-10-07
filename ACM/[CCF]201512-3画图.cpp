#include <iostream>
#include <string.h>
using namespace std;
const int N = 200;
int n, m, t;
char map[N][N];
void line(int a, int b, int c, int d)
{
	bool hori = true;
	int l = a, h = c;
	if (a == c)//---
	{
		hori = false; l = b; h = d;
	}
	if (h < l)h ^= l ^= h ^= l;
	for (int i = l; i <= h; i++)
	{
		if (hori)
		{
			if (map[b][i] == '|')
				map[b][i] = '+';
			else if(map[b][i]!='+')
				map[b][i] = '-';
		}
		else
		{
			if (map[i][a] == '-')
				map[i][a] = '+';
			else if(map[i][a] != '+')
				map[i][a] = '|';
		}
	}
}
struct coor
{
	int x, y;
}Q[N*N];
int l, r;
bool vis[N][N];
const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };
void fill(int a, int b, char c)
{
	memset(vis, 0, sizeof(vis));
	l = -1; r = 0;
	Q[r].x = b; Q[r].y = a; vis[b][a] = true;
	while (l != r)
	{
		l++; coor k = Q[l]; map[k.x][k.y] = c;
		for (int i = 0; i < 4; i++)
		{
			int tx = k.x + dx[i];
			int ty = k.y + dy[i];
			bool isBound = map[tx][ty] == '|' || map[tx][ty] == '+' || map[tx][ty] == '-';
			if (tx >= 0 && ty >= 0 && tx < n && ty < m && !vis[tx][ty] && !isBound)
			{
				r++;
				Q[r].x = tx; Q[r].y = ty;
				vis[tx][ty] = true;
			}
		}
	}
}
int main()
{
	cin >> m >> n >> t;
	memset(map, '.', sizeof(map));
	for (int i = 0; i < t; i++)
	{
		int x, a, b, c, d;
		char p;
		cin >> x;
		if (x == 0)
		{
			cin >> a >> b >> c >> d;
			line(a, b, c, d);
		}
		else
		{
			cin >> a >> b >> p;
			fill(a, b, p);
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < m; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
	//system("pause");
}
