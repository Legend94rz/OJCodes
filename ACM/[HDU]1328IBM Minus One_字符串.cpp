#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int n,j;
string s;
int main()
{
	cin>>n;
	while ( n-- )
	{
		cin>>s;j++;
		printf("String #%d\n",j);
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='Z')
				cout<<'A';
			else
				cout<<(char)(s[i]+1);
		}
		cout << endl;
		cout<<endl;
	}
}