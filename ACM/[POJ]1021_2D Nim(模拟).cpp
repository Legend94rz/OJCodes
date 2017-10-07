#include <iostream>
using namespace std;
const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };
struct Rect
{
	int x, y;
	int w, h;
	inline int area()
	{
		return w*h;
	}
};
int T;
int w, h, n;
Rect d[2][6000];
int vis[2][101][101];
bool map[2][101][101];
int color[2];
int minX, minY, maxX, maxY;
void dfs(int I, int x, int y)
{
	if (!vis[I][x][y])
	{
		if (x > maxX)maxX = x;
		if (x < minX)minX = x;
		if (y > maxY)maxY = y;
		if (y < minY)minY = y;
		vis[I][x][y] = 1 + color[I];
		for (size_t i = 0; i < 4; i++)
		{
			int tx = x + dx[i], ty = y + dy[i];
			if (map[I][tx][ty] && (tx >= 0 && tx < h && ty >= 0 && ty < w))
				dfs(I, x + dx[i], y + dy[i]);
		}
	}
}
bool findAmatch(int c1)
{
	for (int c2 = 0; c2 < color[1]; c2++)
	{
		if (d[0][c1].area() == d[1][c2].area())
		{
			int X = d[0][c1].x;
			int Y = d[0][c1].y;
			int W = d[0][c1].w;
			int H = d[0][c1].h;
			int N = d[1][c2].h;
			int M = d[1][c2].w;
			int ii, jj;
			for (int reflect = 0; reflect <= 1; reflect++)
				for (int rotate = 0; rotate < 4; rotate++)
					if (rotate % 2 == 0 && W == M && H == N || rotate % 2 == 1 && W == N && H == M)
					{
						bool same = true;
						ii = ((reflect ? (rotate == 0 || rotate == 3) : (rotate <= 1)) ? 0 : N-1);
						jj = ((reflect ? (rotate <= 1) : (rotate == 1 || rotate == 2)) ? M-1 : 0);
						ii += d[1][c2].x; jj += d[1][c2].y;
						int ti = ii, tj = jj;
						for (int i = 0; i < H; i++)
						{
							if(rotate%2==0)jj=tj;
							if(rotate%2==1)ii=ti;
							for (int j = 0; j < W; j++)
							{
								if (map[0][X + i][Y + j] != map[1][ii][jj])
								{
									same = false;
									goto Next;
								}
								if (rotate % 2 == 0)jj += (1 - 2 * reflect)*(1 - rotate);
								if (rotate % 2 == 1)ii += (1 - 2 * reflect)*(2 - rotate);
							}
							if (rotate % 2 == 0)ii += (1 - rotate);
							if (rotate % 2 == 1)jj += (rotate - 2);
						}
					Next:
						if (same)
							return true;
					}
		}
	}
	return false;
}
bool check()
{
	if (color[0] != color[1])
		return false;
	for (int c1 = 0; c1 < color[0]; c1++)
	{
		if (!findAmatch(c1))
		{
			return false;
		}
	}
	return true;
}
int main()
{
	cin >> T;
	while (T--)
	{
		int x, y;
		cin >> w >> h >> n;
		memset(map, 0, sizeof(map));
		memset(d, 0, sizeof(d));
		memset(vis, 0, sizeof(vis));
		for (int k = 0; k < 2; k++)
			for (int i = 0; i < n; i++)
			{
				cin >> x >> y;
				map[k][y][x] = true;
			}
		for (int k = 0; k < 2; k++)
		{
			color[k] = 0;
			for (int i = 0; i < h; i++)
				for (int j = 0; j < w; j++)
					if (vis[k][i][j] == 0 && map[k][i][j])
					{
						minX = minY = 1 << 30;
						maxX = maxY = 0;
						dfs(k, i, j);
						d[k][color[k]].x = minX;
						d[k][color[k]].y = minY;
						d[k][color[k]].w = maxY - minY + 1;
						d[k][color[k]].h = maxX - minX + 1;
						color[k]++;
					}
		}
		if (check())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
