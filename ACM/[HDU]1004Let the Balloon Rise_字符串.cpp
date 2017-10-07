#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
vector<string> a;
int n;
string t;
int main()
{
	for(;;)
	{
		cin>>n;
		if(n==0)break;
		a.clear();
		for(int i=0;i<n;i++)
		{
			cin>>t;
			a.push_back(t);
		}
		sort(a.begin(),a.end());
		int M = 0;string ans;
		for(int i=0;i<a.size();)
		{
			int count=0;
			while(i+count<a.size() && a[i]==a[i+count])
			{
				count++;
			}
			if(count>M)
			{
				M=count;
				ans = a[i];
			}
			i += count;
		}
		cout<<ans<<endl;
	}
}