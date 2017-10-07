#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct record
{
	string s;
	int n;
	record(string& s)
	{
		this->s = s;n=0;
		int A=0,C=0,G=0,T=0;
		for (int i = s.length()-1; i >=0; i--)
		{
			switch (s[i])
			{
				case 'A':A++;break;
				case 'C':C++;n+=A;break;
				case 'G':G++;n+=A+C;break;
				case 'T':T++;n+=A+C+G;break;
			}
		}
	}
};
vector<record> v;
int n,m;
string s;
int cmp(const record& a,const record& b)
{
	return a.n<b.n;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>s;
		v.push_back(record(s));
	}
	sort(v.begin(),v.end(),cmp);
	for (size_t i = 0; i < v.size(); i++)
	{
		cout<<v[i].s<<endl;
	}
}
