#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
string s;
bool isvowel(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
int main()
{
	while ( 1 )
	{
		cin>>s;
		if ( s=="end" )break;
		int f1, f2, f3;
		f1 = 0; f2 = 1; f3 = 1;
		for ( int i = 0; i < s.length(); i++ )
		{
			if ( isvowel(s[i]) )
			{
				f1 = 1;
				break;
			}
		}
		for ( int i = 2; i <s.length(); i++ )
		{
			if ( isvowel(s[i]) && isvowel(s[i - 1]) && isvowel(s[i - 2]) ){ f2 = 0; break; }
			if( !isvowel(s[i])&& !isvowel(s[i-1])&& !isvowel(s[i-2]) ){f2=0;break;}
		}
		for ( int i = 1; i <s.length(); i++ )
		{
			if (s[i]==s[i-1] && s[i] != 'e'&&s[i] != 'o' ){ f3 = 0; break; }
		}
		if ( f1&& f2&& f3 )
		{
			printf("<%s> is acceptable.\n", s.c_str());
		}
		else
			printf("<%s> is not acceptable.\n", s.c_str());
	}
}
