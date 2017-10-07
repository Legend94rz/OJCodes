#include <iostream>
#include <string>
using namespace std;
string s;
int main()
{
	while ( getline(cin,s) )
	{
		for(int i=0;i<s.length();i++)
		{
			cout<<(char)tolower(s[i]);
		}
		cout<<endl;
	}
	//system("pause");
}
