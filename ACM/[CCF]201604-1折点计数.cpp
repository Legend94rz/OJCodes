#include <iostream>
using namespace std;
int n;
int a[2000];
int main()
{
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	int ans=0;
	for (size_t i = 1; i < n-1; i++)
	{
		if(a[i-1]<a[i] && a[i]>a[i+1])
			ans++;
		else if(a[i-1]>a[i] && a[i]<a[i+1])
			ans++;
	}
	cout<<ans<<endl;
	//system("pause");
}