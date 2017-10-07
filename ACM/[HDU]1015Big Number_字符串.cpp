#include <iostream>
#include <math.h>
using namespace std;
int n;
int x;
int main()
{
	cin>>n;
	while ( n-- )
	{
		cin>>x;double res=0;
		for ( int i = 1; i <= x; i++ )
		{
			res+=log10(i);
		}
		res=(int)res+1;
		cout<<(int)res<<endl;
	}
}
