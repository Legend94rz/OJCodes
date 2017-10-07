#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct record
{
	int gold, medal;
	double pgold, pmedal;
	int population;
	int no;
	record(int no,int gold, int medal, int population)
	{
		this->no = no;
		this->gold = gold;
		this->medal = medal;
		this->population = population;
		this->pgold = (double)gold / population;
		this->pmedal = (double)medal / population;
	}
	record() {};
};
struct Desc
{
	int rank, method;
};
int n, m;
int a, b, c;
typedef int(*pCmpFunc)(const record&, const record&);

int cmp1(const record& a, const record& b)
{
	return a.gold > b.gold;
}
int cmp2(const record& a, const record& b)
{
	return a.medal > b.medal;
}
int cmp3(const record& a, const record& b)
{
	return a.pgold > b.pgold;
}
int cmp4(const record& a, const record& b)
{
	return a.pmedal > b.pmedal;
}
pCmpFunc cmp[4] = { cmp1,cmp2,cmp3,cmp4 };
int main()
{
	for (;;)
	{
		cin >> n >> m;
		if (cin.eof())break;
		vector<record> all;
		vector<record> need;
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b >> c;
			all.push_back(record(i,a, b, c));
		}
		vector<int> index;
		for (int i = 0; i < m; i++)
		{
			cin >> a;
			need.push_back(all[a]);
			index.push_back(a);
		}
		vector<Desc> d;
		d.resize(n);
		for (int i = 0; i < d.size(); i++)
		{
			d[i].rank = 0x3f3f3f3f;
		}
		for (int K = 1; K <= 4; K++)
		{
			sort(need.begin(), need.end(), cmp[K-1]);
			vector<int> pm;
			pm.resize(m);
			pm[0] = 1;
			if (1 < d[need[0].no].rank)
			{
				d[need[0].no].rank = 1;
				d[need[0].no].method = K;
			}
			for (int i = 1; i < m; i++)
			{
				if (cmp[K - 1](need[i - 1], need[i]) == 0)
				{
					pm[i] = pm[i - 1];
				}
				else
				{
					pm[i] = i+1;
				}
				if (pm[i] < d[need[i].no].rank)
				{
					d[need[i].no].rank = pm[i];
					d[need[i].no].method = K;
				}
			}
		}
		for (int i = 0; i < index.size(); i++)
		{
			cout << d[index[i]].rank << ':' << d[index[i]].method << endl;
		}cout << endl;
	}
}