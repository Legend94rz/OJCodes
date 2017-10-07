#include <iostream>
#include <string>
using namespace std;
int n;
char c,cn;
char word;
void Move()
{
	c=cin.get();
	cn=cin.peek();
}
char Next()
{
	Move();
	if(c=='#')return ' ';
	if(c=='-')return 0;
	if(c=='\n')return c;
	if(c>='0' && c<='9')
		if(cn>='0' && cn<='9')
		{
			char t = ('A' + (c - '0') * 10 + (cn - '0') - 1);
			Move();
			return t;
		}
	return (c-'0'+'A'-1);
}
int main()
{
	cin>>n;cin.get();
	while ( n )
	{
		word=Next();
		if(word)cout<<word;
		if(word=='\n')
			n--;
	}
	//system("pause");
}