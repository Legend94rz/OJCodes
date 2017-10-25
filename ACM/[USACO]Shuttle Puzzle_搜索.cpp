/*
ID: rz109291
PROG: shuttle
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <deque>
#include <string>
using namespace std;
struct CHECKRES
{
	bool flag;
	string targetState;
	short pos;
};
short dx[] = { -2,-1,1,2 };
short N;
string Final;
deque<short> path;
CHECKRES check(string oriState, short p, int i)
{
	CHECKRES res;
	if (p + dx[i] < 0 || p + dx[i]>2 * N)
	{
		res.flag = false;
		return res;
	}
	if (abs(dx[i]) == 2)
	{
		if (oriState[p+dx[i]]== oriState[p+dx[i]/2])
		{
			res.flag = false;
			return res;
		}
	}
	res.targetState = oriState;
	char tmp = res.targetState[p];
	res.targetState[p] = res.targetState[p + dx[i]];
	res.targetState[p + dx[i]] = tmp;
	if (res.targetState > oriState)
	{
		res.flag = false;
		return res;
	}
	res.flag = true;
	res.pos = p + dx[i];
	return res;
}
bool dfs(string state, deque<short>& ans)
{
	if (state == Final)
	{
		cout << ans[1] + 1;
		for (int i = 2; i < ans.size(); i++)
		{
			if (i % 20 != 1)
			{
				cout << ' ' << ans[i] + 1;
			}
			else
				cout << endl << ans[i] + 1;
		}cout << endl;
		return true;
	}
	for (int i = 0; i < 4; i++)
	{
		CHECKRES res = check(state, ans.back(), i);
		if (res.flag)
		{
			ans.push_back(res.pos);
			//cout << res.targetState << endl;
			if ( dfs(res.targetState, ans) )
				return true;
			ans.pop_back();
		}
	}
	return false;
}
int main()
{
	freopen("shuttle.in","r",stdin);freopen("shuttle.out","w",stdout);
	cin>>N;
	Final = string(N, 'B') + 'V' + string(N, 'W');
	path.push_back(N);
	dfs( string(N, 'W') + 'V' + string(N, 'B'), path );
	fclose(stdin);fclose(stdout);
}