#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;
string s,t;
map<string ,string> table;
int main()
{
	while ( cin >> s && s != "XXXXXX" )
	{
		t=s;
		sort(s.begin(),s.end());
		//cout<<"Sort:"<<s<<endl;
		table[t]=s;
	}
	while ( cin>>s && s!="XXXXXX" )
	{
		int flag=0;
		sort(s.begin(),s.end());
		for(map<string,string>::iterator i=table.begin();i!=table.end();i++)
		{
			if(i->second==s)
			{
				flag=1;
				cout<<i->first<<endl;
			}
		}
		if ( !flag )cout << "NOT A VALID WORD" << endl;
		cout<<"******"<<endl;
	}
	//system("pause");
}
