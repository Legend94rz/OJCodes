#include <iostream>
#include <cmath>
using namespace std;
int a, b, c, d, e, f;
const int u[]={0,5,3,1};
int main()
{
	for (;;)
	{
		cin >> a >> b >> c >> d >> e >> f;
		if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0)break;
		int n = f+e+d+(c+3)/4;
		int y = d*5+u[c%4];
		if(y<b)
			n+=(b-y+8)/9;
		int x = 36*n - 36*f - 25*e - 16*d - 9*c - 4*b;
		if(x<a)
			n+=(a-x+35)/36;
		cout<<n<<endl;
	}
}
