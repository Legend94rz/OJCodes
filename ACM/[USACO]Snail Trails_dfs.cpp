/*
ID: rz109291
PROG: snail
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
int N, B;
char map[200][200];
char x;
int y;
bool vis[200][200];
int di[] = { 0, 1, 0, -1 };
int dj[] = { 1, 0, -1, 0 };

int dfs(int I, int J, int d)
{
	if (!(I>0 && I<=N && J>0 && J<=N) || (vis[I][J] || map[I][J]=='#'))
	{
		return 0;
	}
	vis[I][J] = true;
	int ti = I + di[d], tj = J + dj[d], td = d, tm=0;
	if (!(ti > 0 && ti <= N && tj > 0 && tj <= N) || map[ti][tj] == '#')
	{
		td = (d + 1) % 4;
		tm = dfs(I + di[td], J + dj[td], td);
		td = (d + 3) % 4;
		tm = max(tm, dfs(I + di[td], J + dj[td], td));
	}
	else
		tm = dfs(I + di[d], J + dj[d], d);
	vis[I][J] = false;
	return tm + 1;
}

int main()
{
	freopen("snail.in", "r", stdin); freopen("snail.out", "w", stdout);
	memset(map, '.', sizeof(map));
	cin >> N >> B;
	for (int i = 0; i < B; i++)
	{
		cin >> x >> y;
		//cout << x << y << endl;
		map[y][x - 'A' + 1] = '#';
	}
	int tmp1 = dfs(1, 1, 0);
	int tmp2 = dfs(1, 1, 1);
	printf("%d\n", max(tmp1, tmp2));
	//printf("%d, %d\n", tmp1, tmp2);
	
	fclose(stdin); fclose(stdout);
}