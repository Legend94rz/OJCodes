#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int N, K;
vector<int> h;
int x;

class greater_class {
public:
	bool operator()(int a, int b)
	{
		return a > b;
	}
};

int main()
{
	cin >> N >> K;
	for (size_t i = 0; i < N; i++)
	{
		cin >> x;
		h.push_back(x);
	}
	make_heap(h.begin(), h.end(), greater_class());

	int S = 0;
	while (K>0)
	{
		for (; h.size() > 0 && h.front()==S;)
		{
			pop_heap(h.begin(), h.end(), greater_class());
			h.pop_back();
		}
		if (h.size() > 0)
		{
			int m = h.front();
			pop_heap(h.begin(), h.end(), greater_class());
			h.pop_back();
			cout << m - S << endl;
			S = m;
		}
		else
			cout << 0 << endl;
		K -= 1;
	}
}
