#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct rec
{
	string s;
	int pair;
};
int n,m,N;
rec r[101];
int main()
{
	cin>>N;
	while(N--)
	{
		cin>>n>>m;
		for(int i=0;i<m;i++)
		{
			cin>>r[i].s;
			for(int j=0;j<r[i].s.length();j++)
			{
				for(int k=j+1;k<r[i].s.length();k++)
					if( r[i].s[j]>r[i].s[k])
						r[i].pair++;
			}
		}
		while ( 1 )
		{
			int flag = 0; rec t;
			for ( int i = 1; i<m; i++ )
			if ( r[i].pair<r[i - 1].pair )
			{
				t = r[i]; r[i] = r[i - 1]; r[i - 1] = t;
				flag = 1;
			}
			if ( !flag )break;
		}
		for ( int i = 0; i<m; i++ )
			cout << r[i].s << endl;
	}
	//system("pause");
}
