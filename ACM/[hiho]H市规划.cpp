#include <iostream>
#include <cstring>
using namespace std;
int map[1002][1002];
int f[1002][1002];
int N, M;
int qx[100100], qy[100100];
bool vis[1002][1002];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

void bfs()
{
	int l = 0; int r = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (map[i][j] == 1)
			{
				r++;
				qx[r] = i; qy[r] = j;
				vis[i][j] = true; f[i][j] = 1;
			}
	while (l != r)
	{
		l++; if (l >= 100000) {
			l = 1;
		}
		int kx = qx[l];
		int ky = qy[l];
		vis[kx][ky] = false;
		for (int i = 0; i < 4; i++)
		{
			int tx = kx + dx[i]; int ty = ky + dy[i];
			if (tx > 0 && ty > 0 && tx <= N && ty <= M && f[tx][ty] > f[kx][ky] + 1)
			{
				f[tx][ty] = f[kx][ky] + 1;
				if (!vis[tx][ty])
				{
					vis[tx][ty] = true;
					r++; if (r >= 100000) {
						r = 1;
					}
					qx[r] = tx; qy[r] = ty;
				}
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	char c;
	for(int i=1;i<=N;i++)
		for (int j = 1; j <= M; j++)
		{
			cin >> c;
			map[i][j] = int(c - '0');
		}
	memset(f, 0x3f, sizeof(f));
	bfs();
	int ans = N * M * 2;
	bool has_ans = false;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (map[i][j] == 2 && ans > f[i][j])
			{
				//cout << i << ' ' << j << ' ' << f[i][j] << endl;
				ans = f[i][j];
				has_ans = true;
			}
		}
	}
	if (has_ans)
		cout << ans << endl;
	else
		cout << 0 << endl;
}