#include <iostream>
using namespace std;
int n,s,r;

int main()
{
	cin>>n;
	while(n>0)
	{
		s+=n%10;
		n/=10;
	}
	cout<<s<<endl;
}
