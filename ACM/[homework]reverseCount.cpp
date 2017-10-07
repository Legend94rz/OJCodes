#include <iostream>
using namespace std;

int a[10000];
int n;
int ans;

void mergesort(int a[], int l, int r)
{
	if (l == r)return;
	int mid = (l + r) >> 1;
	mergesort(a, l, mid);
	mergesort(a, mid + 1, r);
	int* c = new int[r - l + 1];
	int i = l, j = mid + 1,k=0;
	for (;i<=mid && j<=r;)
	{
		if (a[i] > a[j])
		{
			ans += mid - i + 1;
			c[k] = a[j++];
		}
		else
		{
			c[k] = a[i++];
		}
		k++;
	}
	while (i <= mid)
		c[k++] = a[i++];
	while (j <= r)
		c[k++] = a[j++];
	memcpy(&a[l], c, (r - l + 1) * sizeof(int));
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	mergesort(a, 0, n - 1);
	cout << ans << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
	system("pause");

}