#include <iostream>
#include <string.h>
#include <string>
using namespace std;
const int N = 1000;
int Next[N], ed[N], head[N], ind[N];
int n, m, root;
int tot;
void add(int x, int y)
{
	tot++;
	ed[tot] = y; ind[y]++;
	Next[tot] = head[x];
	head[x] = tot;
}
int Find(int a, int b, int depth)
{
	int ege = head[a];
	if (a == b)
		return depth;
	while (ege)
	{
		int x = Find(ed[ege], b, depth + 1);
		if (x >= 0) return x;
		ege = Next[ege];
	}
	return -1;
}
void print(int d1, string desc)
{
	for (int j = 1; j <= d1 - 2; j++)
		cout << "great-";
	if (d1 > 1)
		cout << "grand";
	cout << desc << endl;

}
int main()
{
	for (;;)
	{
		cin >> n >> m;
		if (n == m&&n == 0)break;
		memset(head, 0, sizeof(head));
		memset(ind, 0, sizeof(ind));
		char a, b, c;
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b >> c;
			add(a, b);add(a, c);
		}
		int d1, d2;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b;
			d1 = Find(a, b, 0);
			d2 = Find(b, a, 0);
			if (d1 <= 0 && d2 <= 0)
				cout << "-\n";
			else if (d1 > 0)
				print(d1, "child");
			else
				print(d2, "parent");
		}
	}
}
