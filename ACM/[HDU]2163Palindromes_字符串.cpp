#include <iostream>
#include <string>
using namespace std;
string s;
bool isPalindromes(const string& s)
{
	int n=s.length();
	for ( int i = 0; i < n / 2; i++ )
	{
		if (s[i]!=s[n-i-1])return false;
	}
	return true;
}
int i;
int main()
{
	while ( cin>>s,s!="STOP" )
	{
		i++;
		cout<<'#'<<i<<": ";
		if(isPalindromes(s))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}