#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string ,string> dict;
int n,m;
string s,t;
bool ok(char c)
{
	return !( c=='a' || c=='e' || c=='i' || c=='o' || c=='u' );
}
int main()
{
	cin>>n>>m;
	while(n--)
	{
		cin>>s>>t;
		dict[s]=t;
	}
	while ( m-- )
	{
		cin>>s;
		if(dict.find(s)==dict.end())
		{
			if(s[s.length()-1]=='y' && ok(s[s.length()-2]))
			{
				s.replace(s.length()-1,s.length(),"ies");
				cout<<s<<endl;
			}
			else if(s[s.length()-1]=='o' || s[s.length()-1]=='s' || s[s.length()-1]=='x' || s[s.length()-1]=='h' &&(s[s.length()-2]=='c' ||s[s.length()-2]=='s' ))
			{
				cout<<s<<"es"<<endl;
			}
			else
				cout<<s<<"s"<<endl;
		}
		else
			cout<<dict[s]<<endl;
	}
	system("pause");
}