#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

map<string,string> table;
char c=' ',cn;
string s,t;
void move()
{
	c=cin.get();
	cn=cin.peek();
}
string GetNext()
{
	move();
	while(c>'z'||c<'a')
	{
		if ( c == 'E' )return "END";
		cout<<c;
		move();
	}
	string r;r+=c;
	while(cn>='a'&&cn<='z')
	{
		move();
		r+=c;
	}
	return r;
}
int main()
{
	getline(cin,s);
	while ( 1 )
	{
		cin>>s;
		if(s=="END")break;
		cin>>t;
		table.insert(make_pair(t,s));
	}
	getline(cin, s);
	getline(cin, s);
	while (1)
	{
		t=GetNext();
		if(t=="END")break;
		if(table.find(t)==table.end())
			cout<<t;
		else
			cout<<table[t];
	}
	//system("pause");
}
