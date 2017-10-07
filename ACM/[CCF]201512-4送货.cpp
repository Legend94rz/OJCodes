#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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
stack<int> ans;
int n, m;
int tot;
int a, b;
int vis[M], d[N];
int cnt;
int cmp(const Desc::Edge& a, const Desc::Edge& b)
{
	return a.b < b.b;
}
void add(int a, int b)
{
	tot++;
	G[a].outs.push_back(Desc::Edge(b, tot));
	d[a]++;
	G[b].outs.push_back(Desc::Edge(a, tot));
	d[b]++;
}
void dfs(int x)
{
	for (int i = 0; i < G[x].outs.size(); i++)
	{
		if (!vis[G[x].outs[i].id])
		{
			vis[G[x].outs[i].id] = true;
			dfs(G[x].outs[i].b);
			ans.push(G[x].outs[i].b);
			cnt++;
		}
	}
}
int main()
{
	cin >> n >> m;
	G.resize(N);
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		add(a, b);
	}
	int c = 0, st = N;
	for (int i = 1; i <= n; i++)
	{
		if (d[i] % 2)
		{
			c++;
			if (i < st)
				st = i;
		}
	}
	if (c != 2 && c != 0)
	{
		cout << -1 << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		sort(G[i].outs.begin(), G[i].outs.end(), cmp);
	}
	if (st == N)
		st = 1;
	dfs(st);
	if(cnt!=m)
	{
		cout<<-1<<endl;
		return 0;
	}
	ans.push(st);
	while (!ans.empty())
	{
		cout << ans.top() << ' ';
		ans.pop();
	}
	cout << endl;
	//system("pause");
}
