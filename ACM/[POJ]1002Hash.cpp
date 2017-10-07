#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int Hash(string ori)
{
	string norm;
	for (size_t i = 0; i < ori.length(); i++)
	{
		switch (ori[i])
		{
		case 'A':case 'B':case 'C':norm += '2'; break;
		case 'D':case 'E':case 'F':norm += '3'; break;
		case 'G':case 'H':case 'I':norm += '4'; break;
		case 'J':case 'K':case 'L':norm += '5'; break;
		case 'M':case 'N':case 'O':norm += '6'; break;
		case 'P':case 'R':case 'S':norm += '7'; break;
		case 'T':case 'U':case 'V':norm += '8'; break;
		case 'W':case 'X':case 'Y':norm += '9'; break;
		case '-':break;
		default:norm += ori[i]; break;
		}
	}
	int t1 = atol(norm.substr(0,3).c_str());
	int t2 = atol(norm.substr(3).c_str());
	return t1*10000+t2;
}
int n;
vector<int> a;
int main()
{
	scanf("%d", &n);
	char buf[500];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", buf);
		a.push_back(Hash(buf));
	}
	a.push_back(1<<30);
	sort(a.begin(), a.end());
	int now = a[0];
	int count = 0;
	bool flag = true;
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] == now)
			count++;
		else
		{
			if (count > 1)
			{
				flag = false;
				printf("%03d-%04d %d\n", now/10000,now%10000, count);
			}
			count = 1; now = a[i];
		}
	}
	if (flag)
		printf("No duplicates.\n");
}
