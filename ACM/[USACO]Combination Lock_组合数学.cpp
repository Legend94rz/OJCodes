/*
ID: rz019291
LANG: C++
PROG: combo
*/
#include <iostream>
#include <stdio.h>
using namespace std;
int n;
int a[3], b[3];
int c[3];
int min(int a, int b)
{
	return a < b ? a : b;
}
int max(int a, int b)
{
	return a > b ? a : b;
}
int pow(int a,int b)
{
	int s=1;
	for(int i=0;i<b;i++)
		s*=a;
	return s;
}
int calc(int a, int b)
{
	if (a > b) a ^= b ^= a ^= b;
	return min(b - a, a + n - b);
}
int main()
{
	freopen("combo.in","r",stdin);
	freopen("combo.out","w",stdout);
	cin >> n;
	cin >> a[0] >> a[1] >> a[2];
	cin >> b[0] >> b[1] >> b[2];
	for (int i = 0; i < 3; i++)
	{
		int d = calc(a[i], b[i]);
		c[i] = n > 5 ? (10 - d < n ? max(5 - d, 0) : 10 - d - n) : n;
	}
	cout << (int)(pow(min(5, n), 3)) * 2 - c[0] * c[1] * c[2] << endl;
	fclose(stdin);fclose(stdout);
	//system("pause");
}