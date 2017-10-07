#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string t[1500];
int T, n;
struct Desc
{
	struct Edge {
		int b, id;
		string name;
		Edge(int b, int id, string name)
		{
			this->b = b;
			this->id = id;
			this->name = name;
		}
	};
	vector<Edge> outs;
};
vector<Desc> G;
int ind[30], outd[30];
int tot;
bool vis[1500];
string ans[1500];
int cnt;
void add(char a, char b, int id, string name)
{
	G[a - 'a'].outs.push_back(Desc::Edge(b - 'a', id, name));
	ind[b - 'a']++;
	outd[a - 'a']++;
}
void dfs(int x)
{
	for (size_t i = 0; i < G[x].outs.size(); i++)
	{
		if (!vis[G[x].outs[i].id])
		{
			vis[G[x].outs[i].id] = true;
			dfs(G[x].outs[i].b);
			ans[cnt++] = G[x].outs[i].name;
		}
	}
}
int cmp(const Desc::Edge& a, const Desc::Edge& b)
{
	return a.name < b.name;
}
int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n;
		G.clear();
		G.resize(30);
		tot = 0;
		memset(ind, 0, sizeof(ind));
		memset(outd, 0, sizeof(outd));
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		int mink = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> t[i];
			if (t[i][0] < t[mink][0])
				mink = i;
			add(t[i][0], t[i][t[i].length() - 1], i, t[i]);
		}
		bool f = true, hasAns = true;
		int st = -1, ed = -1;

		for (int i = 0; i < 30; i++)
			if (ind[i] != 0 || outd[i] != 0)
			{
				if (ind[i] != outd[i])
				{
					if(abs(ind[i]-outd[i])>1)
					{
						hasAns = false;break;
					}
					f = false;
					if (outd[i] - ind[i] == 1 && st == -1)
						st = i;
					else if (ind[i] - outd[i] == 1 && ed == -1)
					{
						ed = i;
					}
					else
					{
						hasAns = false; break;
					}
				}
			}

		if (!hasAns)
		{
			cout << "***" << endl;
			continue;
		}
		if (f) st = t[mink][0] - 'a';
		for (int i = 0; i < 30; i++)
			sort(G[i].outs.begin(), G[i].outs.end(), cmp);
		dfs(st);
		if (cnt != n)
		{
			cout << "***" << endl;
			continue;
		}
		while (cnt > 0)
		{
			if (cnt != n)
			{
				cout << '.' << ans[--cnt];
			}
			else
			{
				cout << ans[--cnt];
			}
		}
		cout << endl;
	}
	//system("pause");
}
