#include <iostream>
#include <string>

using namespace std;
int n,k;
int i;
string s;
int main()
{
	cin>>n;i=1;
	while ( n-- )
	{
		cin>>k;
		cin>>s;
		s.erase(s.begin()+k-1);
		cout<<i<<' '<<s<<endl;
		i++;
	}
	//system("pause");
}
