#include <iostream>
#include <string>
using namespace std;
int n;
string s;
char c;
int main()
{
	cin>>n;cin.get();
	while ( n-- )
	{
		for(;;)
		{
			s[0]='\0';
			while ( cin.peek() == ' ' )cout << (char)cin.get();
			cin>>s;
			for(int i=s.length()-1;i>=0;i--)
				cout<<s[i];
			while(cin.peek()==' ')cout<<(char)cin.get();
			if(cin.peek()=='\n'){cin.get();break;}
		}
		cout<<endl;
	}
	//system("pause");
}
