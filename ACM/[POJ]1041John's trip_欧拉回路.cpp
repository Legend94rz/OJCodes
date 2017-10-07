#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
const int N = 10001;
const int M = 200001;
struct Desc {
	struct Edge
	{
		int b, id;
		Edge(int b, int id)
		{
			this->b = b;
			this->id = id;
		}
	};
	vector<Edge> outs;
};
vector<Desc> G;
int n, m;
int a, b, c, st;
int vis[M];
int d[N];
int cnt;
stack<int> ans;
void add(int a, int b, int id)
{
	G[a].outs.push_back(Desc::Edge(b, id));
	d[a]++;
}

void dfs(int x)
{
	for (size_t i = 0; i < G[x].outs.size(); i++)
	{
		if (!vis[G[x].outs[i].id])
		{
			vis[G[x].outs[i].id] = true;
			dfs(G[x].outs[i].b);
			ans.push(G[x].outs[i].id);
		}
	}
}
int cmp(const Desc::Edge& a, const Desc::Edge& b)
{
	return a.id < b.id;
}
int main()
{
	for (;;)
	{
		G.clear();
		G.resize(N);
		cnt = m = n = 0; st = -1;
		memset(d, 0, sizeof(d));
		for (;;)
		{
			cin >> a >> b;
			if (a == b && b == 0)break;
			if (a > n) n = a;
			if (b > n) n = b;
			cin >> c;
			if (st == -1)
				st = a < b ? a : b;
			m++;
			add(a, b, c); add(b, a, c);
		}
		if (n == 0)break;
		int c = 0;
		for (int i = 1; i <= n; i++)
		{
			if (d[i] % 2)
			{
				c++;
				break;
			}
		}
		if (c != 0)
		{
			cout << "Round trip does not exist." << endl;
			continue;
		}
		//²»ÅÅÐòÒ²¶Ô
		//for (int i = 1; i <= n; i++)
		//{
		//	sort(G[i].outs.begin(), G[i].outs.end(), cmp);
		//}
		while (!ans.empty())ans.pop();
		memset(vis, 0, sizeof(vis));
		dfs(st);
		bool flag = true;
		while (!ans.empty())
		{
			flag ? cout << ans.top() : cout << ' ' << ans.top();
			flag = false;
			ans.pop();
		}cout << endl;
	}
	//system("pause");
}
