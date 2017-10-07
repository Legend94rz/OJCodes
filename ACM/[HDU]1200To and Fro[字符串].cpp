#include <iostream>
#include <string>
#include <string.h>
using namespace std;
char ch[1001][1001];
int n;
string s;
int main()
{
	while ( cin >> n && n )
	{
		cin >> s;
		int x = 0, y = 0, c = 1;
		for ( int i = 0; i < s.length(); i++ )
		{
			ch[x][y] = s[i];
			y += c;
			if ( y >= n || y < 0 ){ x++;if(c>0)y=n-1; else y=0; c = c*-1; }
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<x;j++)
				cout<<ch[j][i];
		cout<<endl;
	}
	system("pause");
}
