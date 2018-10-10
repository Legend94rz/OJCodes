/*
ID: rz109291
PROG: hidden
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int L;
string s,t;
bool same;

int cmp(int I, int J)
{
	for (int i = 0; i < L; i++)
	{
		if (s[I + i] < s[J + i])
			return i;
		if (s[I + i] > s[J + i])
			return -1;		//找到一个更小的
	}
	return -2;		//相等
}

int main()
{
	freopen("hidden.in", "r", stdin); freopen("hidden.out", "w", stdout);
	cin >> L;
	for (;;)
	{
		cin >> t;
		if (cin.eof())break;
		s += t;
	}
	//这个稍微有点骗分，同种字符会超时，肯定也会有其他构造数据会超时。正解可能是 周源《最小表示思想的应用》。
	same = true;
	for (size_t i = 1; i < s.length(); i++)
	{
		if (s[i] != s[0])
		{
			same = false;
			break;
		}
	}
	if (same)
	{
		cout << 0 << endl;
		fclose(stdin); fclose(stdout);
		return 0;
	}

	s += s;

	int I = 0, J = 1;

	while (J < L)
	{
		int k = cmp(I, J);
		if (k == -1)
		{
			I = J;
		}
		if (k > 0)
		{
			J = J + k;
		}
		if (k == -2||k==0||k==-1)
			J++;
	}
	cout << I << endl;

	fclose(stdin); fclose(stdout);
}