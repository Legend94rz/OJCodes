#include <iostream>
#include <string>
using namespace std;
int n;
string s;
int main()
{
	cin>>n;
	while ( n-- )
	{
		cin>>s;int count=0;
		for ( int i = 0; i < s.length(); i++ )
		{
			if(isdigit(s[i]))count++;
		}
		cout<<count<<endl;
	}
}