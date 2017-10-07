#include <iostream>
using namespace std;
int n;
int main()
{
	while ( cin>>n,n )
	{
		int res=1;
		for ( int i = 1; i <= n; i++ )
		{
			res=(res*(n%9))%9;
		}
		if(res==0)res=9;
		cout<<res<<endl;
	}
}