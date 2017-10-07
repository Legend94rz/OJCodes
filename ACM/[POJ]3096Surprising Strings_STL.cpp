#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s;
bool check(string& s)
{
	for (size_t i = 1; i < s.length(); i++)
	{
		vector<string> v;
		for (size_t j = 0; j < s.length()-i; j++)
		{
			string t= s.substr(j, 1) + s.substr(j + i, 1);
			v.push_back(t);
			for (size_t k = 0; k < v.size()-1; k++)
			{
				if(v[k]==t)
					return false;
			}
		}
	}
	return true;
}
int main()
{
	while(1)
	{
		cin>>s;
		if(s=="*")break;
		if(check(s))
		{
			cout<<s<<" is surprising."<<endl;
		}
		else
			cout<<s<<" is NOT surprising."<<endl;
	}
}