#include <iostream>
#include <string.h>
using namespace std;
int T,n,s,t;
int Con[400];
int main()
{
	cin>>T;
	while ( T-- )
	{
		cin>>n;
		memset(Con,0,sizeof(Con));
		for ( int i = 0; i < n; i++ )
		{
			cin>>s>>t;
			if(s%2)s+=1;
			if(t%2)t+=1;
			if(s>t)s^=t^=s^=t;
			for ( int j = s>>1; j <= t>>1; j++ )
			{
				Con[j]++;
			}
		}
		int max=0;
		for(int i=0;i<=200;i++)
		{
			if ( Con[i]>max )
			{
				max=Con[i];
			}
		}
		cout<<max*10<<endl;
	}
	//system("pause");
}
