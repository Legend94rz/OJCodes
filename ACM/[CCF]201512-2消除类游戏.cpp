#include <iostream>
using namespace std;
const int N=40;
int map[N][N];
int n,m;
bool flag[N][N];
void solve(int x,int y)
{
	if(map[x][y]==map[x+1][y] && map[x][y]==map[x+2][y])
		for(int i=x;i<n&&map[i][y]==map[x][y];i++)
		{
			flag[i][y]=true;
		}
	if(map[x][y]==map[x][y+1] && map[x][y]==map[x][y+2])
	{
		for (int i = y; i < m && map[x][y]==map[x][i]; i++)
		{
			flag[x][i]=true;
		}
	}
}
int main()
{
	cin>>n>>m;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			cin>>map[i][j];
		}
	}
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			solve(i,j);
		}
	}
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			if(flag[i][j])
				cout<<0<<' ';
			else
				cout<<map[i][j]<<' ';
		}
		cout<<endl;
	}
	//system("pause");
}
