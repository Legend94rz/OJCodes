#include <iostream>
#include <string.h>
using namespace std;

typedef long long i64;
int T;

i64 getPrev(i64 x)
{
	int nums[20], L;
	memset(nums, 0, sizeof(nums)); L = 0;
	while (x)
	{
		nums[L++] = x % 10;
		x /= 10;
	}
	for (int i = L - 1; i >= 0; i--)
	{
		if (nums[i] % 2)
		{
			nums[i]++;
			if (nums[i] == 10)
			{
				nums[i] = 0;
				int j = i + 1;
				while (j < L && nums[j] == 8)
					nums[j++] = 0;
				nums[j] += 2;
				if (j == L)
					L++;
			}
			for (int j = i - 1; j >= 0; j--)
				nums[j] = 0;
			break;
		}
	}
	i64 a = 0;
	for (int i = L - 1; i >= 0; i--)
			a = a * 10 + nums[i];
	return a;
}

i64 getNext(i64 x)
{
	int nums[20], L;
	memset(nums, 0, sizeof(nums)); L = 0;
	while (x)
	{
		nums[L++] = x % 10;
		x /= 10;
	}
	for (int i = L - 1; i >= 0; i--)
	{
		if (nums[i] % 2)
		{
			nums[i]--;
			for (int j = i - 1; j >= 0; j--)
				nums[j] = 8;
			break;
		}
	}

	i64 a = 0;
	for (int i = L-1; i >=0; i--)
		a = a * 10 + nums[i];
	return a;
}

int main()
{
	i64 x;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> x;
		i64 pre = getPrev(x);
		i64 nxt = getNext(x);
		i64 ans = 0;
		if (pre - x < x - nxt)
			ans = pre-x;
		else
			ans = x-nxt;
		printf("Case #%d: %lld\n", t, ans);
	}
}
