#include <iostream>
using namespace std;
int n;
int A[200][200];
int a[20000], b[20000], e[20000], f[20000];
int s, t, tot;
int x, y, z;
int mst;
int getf(int x)
{
	int c = x, t;
	while ( f[x] != x )x = f[x];
	while ( c != x )
	{
		t = f[c];
		f[c] = x;
		c = t;
	}
	return x;
}
void qsort(int s, int t)
{
	int i = s, j = t, u, k = e[(s + t) >> 1];
	while ( i <= j )
	{
		while ( e[i]<k )i++;
		while ( e[j]>k )j--;
		if ( i <= j )
		{
			u = a[i]; a[i] = a[j]; a[j] = u;
			u = b[i]; b[i] = b[j]; b[j] = u;
			u = e[i]; e[i] = e[j]; e[j] = u;
			i++; j--;
		}
	}
	if ( i < t )qsort(i, t);
	if ( s < j )qsort(s, j);
}
int main()
{
	while ( cin >> n )
	{
		tot=0;mst=0;
		for ( int i = 1; i <= n; i++ )
		{
			for ( int j = 1; j <= n; j++ )
			{
				cin >> A[i][j];
				if ( i > j )
				{
					a[tot] = i; b[tot] = j; e[tot] = A[i][j];
					tot++;
				}
			}
		}
		for ( int i = 0; i <= n; i++ )f[i] = i;
		qsort(0, tot - 1);
		cin >> n;
		int fx, fy;
		while ( n-- )
		{
			cin >> x >> y;
			fx = getf(x); fy = getf(y);
			f[fx] = fy;
			//mst+=A[x-1][y-1];
		}
		for ( int i = 0; i < tot; i++ )
		{
			fx = getf(a[i]); fy = getf(b[i]);
			if ( fx != fy )
			{
				f[fx] = fy;
				mst += A[a[i]][b[i]];
			}
		}
		cout << mst << endl;
	}
	//system("pause");
}
