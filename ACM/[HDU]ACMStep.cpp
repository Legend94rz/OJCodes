#include <iostream>
using namespace std;
int a, b;
int s, t;
int main()
{
	while ( (a=cin.get())>0 )
	{
		cin.get();
		b=cin.get();cin.get();
		s = a-'0'; t = b-'0';
		if ( a >= 'a'&& a <= 'z' )s = a - 'a' + 10;
		if ( a >= 'A' && a <= 'Z' )s = a - 'A' + 10;
		if ( b >= 'a'&& b <= 'z' )t = b - 'a' + 10;
		if ( b >= 'A' && b <= 'Z' )t = b - 'A' + 10;
		cout << s + t << endl;
	}
}