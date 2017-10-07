#include <iostream>
using namespace std;
int n;
int main()
{
	for(;;)
	{
		int s=0;
		cin>>n;
		if(n==0)break;
		while(n!=1)
		{
			if(n%2)n=(3*n+1)/2;else n/=2;
			s++;
		}
		cout<<s<<endl;
	}
}