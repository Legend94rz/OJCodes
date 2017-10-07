#include <iostream>
#include <string>
using namespace std;
string s,t;
int main()
{
	while(1)
	{
		getline(cin,s);
		if(s=="#")break;
		getline(cin,t);
		for(int i=0;i<s.length();i++)
		{
			int count=0;
			for ( int j = 0; j < t.length(); j++ )
			{
				if(s[i]==t[j])count++;
			}
			cout<<s[i]<<' '<<count<<endl;
		}
	}
}