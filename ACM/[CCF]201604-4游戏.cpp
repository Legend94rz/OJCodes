#include <iostream>
using namespace std;
struct desc
{
	int x, y;
	int step;
};
const int N = 105;
int st[N][N], ed[N][N];
const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };
int n, m, t;
desc q[N*N*N];
int l, r;
bool vis[N][N][2*N];
void bfs()
{
	l = -1;
	r = 0;
	q[r].x = 1;
	q[r].y = 1; vis[1][1][0] = true;
	q[r].step=0;
	while (l != r)
	{
		l++;if(l>=100000) l=0;
		desc k = q[l];
		for (int i = 0; i < 4; i++)
		{
			int tx = k.x + dx[i], ty = k.y + dy[i];
			bool danger = (st[tx][ty] <= k.step + 1) && (k.step + 1 <= ed[tx][ty]);
			if (tx > 0 && ty > 0 && tx <= n && ty <= m  && !danger && !vis[tx][ty][k.step+1])
			{
				r++;if(r>=100000)r=0;
				q[r].x = tx;
				q[r].y = ty;
				q[r].step = k.step+1;
				vis[tx][ty][k.step+1]=true;
				//printf("(%d,%d)\n",tx,ty);
				if(tx==n && ty==m)
				{
					cout<<q[r].step<<endl;
					return;
				}
			}
		}
		//cout<<"===="<<endl;
	}
}
int main()
{
	int r, c, a, b;
	cin >> n >> m >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> r >> c >> a >> b;
		st[r][c] = a;
		ed[r][c] = b;
	}
	bfs();
	//system("pause");
}