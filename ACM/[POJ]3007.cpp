#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int n;
string s,a,b,ra,rb;
vector<string> v(600);
int main()
{
	cin>>n;
	while(n--)
	{
		v.clear();
		cin>>s;
		v.push_back(s);
		for (size_t i = 1; i < s.length(); i++)
		{
			a=s.substr(0,i);
			b=s.substr(i);
			ra=a;
			reverse(ra.begin(),ra.end());
			rb=b;
			reverse(rb.begin(),rb.end());
			v.push_back(a+rb);
			v.push_back(ra+b);
			v.push_back(ra+rb);
			v.push_back(b+a);
			v.push_back(b+ra);
			v.push_back(rb+a);
			v.push_back(rb+ra);
		}
		sort(v.begin(),v.end());
		vector<string>::iterator it = unique(v.begin(),v.end());
		v.erase(it,v.end());
		cout<<v.size()<<endl;
	}
}