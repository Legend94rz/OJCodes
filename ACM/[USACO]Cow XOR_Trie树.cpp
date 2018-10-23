/*
ID: rz109291
PROG: cowxor
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


class Node
{
public:
	Node* ch[2];
	int rank;
	Node()
	{
		ch[0] = ch[1] = NULL;
		rank = 0;
	}
};
Node* root;
int N, S;
int a;
void insert(int x, int r)
{
	Node* p = root;
	for (int i = 20; i >= 0; i--)
	{
		int y = (x & (1 << i)) >> i;	//取第i位
		if (!p->ch[y])
			p->ch[y] = new Node();
		p = p->ch[y];
	}
	p->rank = r;
}

void find(int x, int* v, int* r)
{
	Node* p = root;
	*v = 0;
	for (int i = 20; i >= 0; i--)
	{
		int y = (x & (1 << i)) >> i;	//取第i位
		int ch = !y;
		if (!p->ch[ch])
			ch = y;						//优先取与第i位相异的路走
		*v = (*v << 1) + ch;
		p = p->ch[ch];
	}
	*r = p->rank;
}

//xor与自身互为相反运算，类似前缀和。计算 xor a[i..j] <===> S[j] xor S[i-1]
int main()
{
	freopen("cowxor.in", "r", stdin); freopen("cowxor.out", "w", stdout);
	cin >> N;
	S = 0;
	int ans = -1, ps = 0, pt = 0, t = 0, r = 0;
	root = new Node();
	insert(0, 0);
	for (int i = 1; i <= N; i++)
	{
		cin >> a;
		S ^= a;
		find(S, &t, &r);
		if ((t^S) > ans)
		{
			ans = t^S;
			ps = r;
			pt = i;
		}
		insert(S, i);
	}
	cout << ans << ' ' << ps + 1 << ' ' << pt << endl;
	fclose(stdin); fclose(stdout);
}
