#include <iostream>
using namespace std;

int A[] = { 1,3,5,9 };
int B[] = { 3,7,10,11  };
int N;
int max(int x, int y)
{
	if (x > y)return x;
	return y;
}
int min(int x, int y)
{
	if (x < y)return x;
	return y;
}
int findKth(int a[], int b[], int kth)
{
	int l = max(0,kth-N), r = min(kth,N);
	int v = -1;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		bool b1 = a[mid] >= b[kth - mid - 1];
		bool b2 = (kth-mid==N && b[N-1]<=a[0]) || b[kth - mid] >= a[mid - 1];
		if (b1&&b2)
		{
			if (mid == 0)
				v = b[kth - mid - 1];
			else if (mid == N)
			{
				if (kth > N)
					v = max(a[mid - 1], b[kth - mid - 1]);
				else
					v = a[mid - 1];
			}
			else
				v = max(a[mid - 1], b[kth - mid - 1]);
			break;
		}
		if (!b1)
			l = mid + 1;
		if (!b2)
			r = mid - 1;
	}
	return v;
}
int main()
{
	N = sizeof(A) / sizeof(int);
	int x1 = findKth(A, B, N);
	int x2 = findKth(A, B, N + 1);
	cout << (x1 + x2) / 2.0 << endl;
	system("pause");
}