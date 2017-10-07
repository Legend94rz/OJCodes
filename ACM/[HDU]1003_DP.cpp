#include <iostream>
#include <string.h>
using namespace std;
int n,m,t;
int a[100001];
int main()
{
	cin>>n;
	while ( n-- )
	{
		cin>>m;t++;
		for ( int i = 1; i <= m; i++ )
		{
			cin>>a[i];
		}
		int s=0;int l,r,ans=-0x3f3f3f3f,tmp=1;
		for ( int i = 1; i <= m; i++ )
		{
			s=s+a[i];
			if(s>ans)
			{
				r=i;
				l=tmp;
				ans=s;
			}
			if(s<0)
			{
				s=0;
				tmp=i+1;
			}
		}
		cout<<"Case "<<t<<':'<<endl;
		cout<<ans<<' '<<l<<' '<<r<<endl;
		if(n)
			cout<<endl;
	}
	//system("pause");
}
