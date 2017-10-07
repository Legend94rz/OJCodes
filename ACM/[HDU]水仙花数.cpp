#include <iostream>
using namespace std;
int a, b;
int n;
int A[1000];
bool OK(int x)
{
	int a = x % 10;
	int b = x / 10 % 10;
	int c = x / 100 % 10;
	if ( a*a*a + b*b*b + c*c*c == x )
		return true;
	return false;
}
int main()
{
	while ( cin >> a >> b )
	{
		n = 0;
		for ( int i = a; i <= b; i++ )
		{
			if ( OK(i) ){ A[n++] = i; }
		}
		if ( !n )
			cout << "no";
		else
		{
			cout << A[0];
			for ( int i = 1; i < n; i++ )
			{
				cout <<' '<<A[i];
			}
		}
		cout << endl;
	}
	//system("pause");
}