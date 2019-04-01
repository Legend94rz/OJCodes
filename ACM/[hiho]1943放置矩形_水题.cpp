#include <iostream>
#include <map>
#include <tuple>
using namespace std;

int x[100011], y[100011];
int N;
map<tuple<int, int>, bool> h;


int main()
{
	cin >> N;
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> x[i] >> y[i];
		if (h.find(make_tuple(x[i], y[i])) != h.end() || h.find(make_tuple(x[i]+1, y[i]))!=h.end())
			continue;
		ans++;
		//cout << make_tuple(x[i], y[i]) << endl;
		h[make_tuple(x[i], y[i])] = true;
		h[make_tuple(x[i] + 1, y[i])] = true;
	}
	cout << ans << endl;

}