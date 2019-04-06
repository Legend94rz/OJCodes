#include <iostream>
using namespace std;

int A[400000], sm[400000];
int N, Q, E, x;

void build_tree(int l, int r, int x)
{
	if (l == r)
	{
		A[x] = 1; sm[x] = 1; return;
	}
	int k = (l + r) >> 1;
	build_tree(l, k, x << 1);
	build_tree(k + 1, r, (x << 1) + 1);
	sm[x] = sm[x << 1] + sm[(x << 1) + 1];
}

void update(int a, int b, int l, int r, int x, int v)
{
	if (a == l && b == r)
	{
		A[x] = v;
		sm[x] = v;
		return;
	}
	int k = (a + b) >> 1;
	if (l > k)
		update(k + 1, b, l, r, (x << 1) + 1, v);
	else if (r<=k)
		update(a, k, l, r, x << 1, v);
	else
	{
		update(a, k, l, k, x << 1, v);
		update(k + 1, b, k + 1, r, x, v);
	}
	sm[x] = sm[x << 1] + sm[(x << 1) + 1];
}

int ask(int a, int b, int l, int r, int x)
{
	if (a == l && b == r)
		return sm[x];
	int k = (a + b) >> 1;
	if (r <= k)
		return ask(a, k, l, r, x << 1);
	else if (l > k)
		return ask(k + 1, b, l, r, (x << 1) + 1);
	return ask(a, k, l, k, x << 1) + ask(k + 1, b, k + 1, r, (x << 1) + 1);
}

int main()
{
	cin >> N;
	cin >> Q;
	build_tree(1, N, 1);
	int loc = 1;
	for (int i = 0; i < Q; i++)
	{

		cin >> E >> x;
		if (E == 1)
		{
			update(1, N, loc, loc, 1, 0);
			loc++;
		}
		else if (E == 2)
		{
			update(1, N, x, x, 1, 0);
		}
		else if (E == 3)
		{
			cout << ask(1, N, 1, x, 1)<<endl;
		}
	}
}