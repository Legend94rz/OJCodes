#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n;
string s;
int main()
{
	cin>>n;cin.get();
	while(n--)
	{
		s="";
		getline(cin,s);
		reverse(s.begin(),s.end());
		cout<<s<<endl;
	}
	//system("pause");
}
