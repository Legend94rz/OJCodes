#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
int n;
string scur;
vector<string> cur;
string input[20];

void parseCur(string& path, vector<string>& output)
{
	int s = path.find('/'),t=0;
	if(s!=0)
	{
		output.push_back(path.substr(0,s));
	}
	while(t!=-1 && s<path.length())
	{
		t = path.find('/', s+1);
		output.push_back(path.substr(s+1,t-s-1));
		s=t;
	}
}
string predeal(string s)
{
	string t;bool flag=false;
	for (size_t i = 0; i < s.length(); i++)
	{
		if(s[i]=='/')
		{
			if(!flag)t+=s[i];
			flag = true;
		}
		else
		{
			t+=s[i];flag=false;
		}
	}
	if(t.length()>1 && t[t.length()-1]=='/')
		t.erase(t.length()-1);
	return t;
}
int main()
{
	cin>>n;
	cin>>scur;
	getchar();
	parseCur(scur,cur);
	for (size_t i = 0; i < n; i++)
	{
		getline(cin,input[i]);
		input[i] = predeal(input[i]);
	}
	for (size_t i = 0; i < n; i++)
	{
		stack<string> output;
		vector<string> temp;
		parseCur(input[i],temp);
		if(input[i].length()==0)
		{
			cout<<scur<<endl;
		}
		else
		{
			if(input[i][0]!='/')
			{
				for (size_t i = 0; i < cur.size(); i++)
				{
					output.push(cur[i]);
				}
			}
			for (size_t i = 0; i < temp.size(); i++)
			{
				if(temp[i]=="..")
				{
					if(!output.empty())
						output.pop();
				}
				else if(temp[i]==".")
				{
				
				}
				else
				{
					output.push(temp[i]);
				}
			}
			vector<string> ans;
			while(!output.empty())
			{
				ans.push_back(output.top());
				output.pop();
			}
			if(ans.size()>0)
			{
				for (int i = ans.size() - 1; i >= 0; i--)
				{
					cout<<'/'<<ans[i];
				}cout<<endl;
			}
			else
			{
				cout<<'/\n';
			}
		}

	}
	//system("pause");
}