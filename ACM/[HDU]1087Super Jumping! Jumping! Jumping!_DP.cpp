#include <iostream>
#include <string.h>
using namespace std;
__int64 f[1011];
int n;
__int64 a[1011];
__int64 max(__int64 a,__int64 b)
{
	if(a>b)return a;
	return b;
}
int main()
{
	while(cin>>n,n)
	{
		memset(f,0,sizeof(f));
		a[0]=0;a[n+1]=LONG_MAX;
		for ( int i = 1; i <= n; i++ )
		{
			cin>>a[i];
		}
		f[1]=a[1];
		for ( int i = 2; i <=n; i++ )
		{
			f[i]=a[i];
			for ( int j = 1; j < i; j++ )
			{
				if ( a[j]<a[i] )
				{
					f[i]=max(f[i],f[j]+a[i]);
				}
			}
		}
		__int64 t=0;
		for ( int i = 1; i <= n; i++ )
		{
			t=max(f[i],t);
		}
		cout<<t<<endl;
	}
	//system("pause");
}
