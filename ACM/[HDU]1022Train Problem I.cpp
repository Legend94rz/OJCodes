#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
int n;
int a[20];
int b[20];
string s, t;
vector<string> ans;
int main()
{
	while (true)
	{
		cin >> n;
		cin >> s;
		cin >> t;
		if(cin.eof())break;
		ans.clear();
		for (size_t i = 0; i < s.length(); i++)
		{
			a[i] = s[i] - '0';
			b[i] = t[i] - '0';
		}
		stack<int> st;
		int i=0,j=0;
		bool flag = true;
		while(i<n || j<n)
		{
			if((st.empty() || st.top()!=b[j]) && i<n)
			{
				st.push(a[i++]);
				ans.push_back("in");
			}
			else if(st.top()==b[j])
			{
				st.pop();
				j++;
				ans.push_back("out");
			}
			else
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			cout<<"Yes."<<endl;
			for(i=0;i<ans.size();i++)
				cout<<ans[i]<<endl;
		}
		else
		{
			cout<<"No."<<endl;
		}
		cout<<"FINISH"<<endl;
	}
	//system("pause");
}