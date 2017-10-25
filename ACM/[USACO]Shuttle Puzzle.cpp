/*
ID: rz109291
PROG: shuttle
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;
struct CHECKRES
{
	bool flag;
	int targetState;
	short pos;
};
short dx[] = { -2,-1,1,2 };
short N;
int Final;
deque<short> path;
short getBit(int x, short p)
{
	return (short)((x & (1 << p)) >> p);
}
int setBit(int x, short p, bool s)
{
	if (s)
		return x | (1 << p);
	return x & (~(1 << p));
}
CHECKRES check(int oriState, short p, int i)
{
	CHECKRES res;
	if (p + dx[i] < 0 || p + dx[i]>2 * N)
	{
		res.flag = false;
		return res;
	}
	if (abs(dx[i]) == 2)
	{
		if (!(getBit(oriState,p+dx[i]) ^ getBit( oriState,p+dx[i]/2 )))//wrong
		{
			res.flag = false;
			return res;
		}
	}
	short tmp = getBit(oriState, p + dx[i]);
	int targetState = setBit(setBit(oriState, p, (bool)(tmp & 1)), p + dx[i], 0);
	if (targetState > oriState)
	{
		res.flag = false;
		return res;
	}
	res.flag = true;
	res.pos = p + dx[i];
	res.targetState = targetState;
	return res;
}
bool dfs(int state, deque<short>& ans)
{
	if (state == Final)
	{
		cout << ans[1];
		for (int i = 2; i < ans.size(); i++)
		{
			cout << ' ' << ans[i];
		}cout << endl;
		return true;
	}
	for (int i = 0; i < 4; i++)
	{
		CHECKRES res = check(state, ans.back(), i);
		if (res.flag)
		{
			ans.push_back(res.pos);
			if ( dfs(res.targetState, ans) )
				return true;
			ans.pop_back();
		}
	}
	return false;
}
int main()
{
	//freopen("shuttle.in","r",stdin);freopen("shuttle.out","w",stdout);
	cin>>N;
	Final = (1 << N) - 1;
	path.push_back(N + 1);
	dfs( ((1 << N) - 1) << (N + 1) , path );
	fclose(stdin);fclose(stdout);
}