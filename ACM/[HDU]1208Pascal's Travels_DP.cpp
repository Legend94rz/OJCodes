#include <iostream>
#include <string.h>
using namespace std;
__int64 f[100][100];
__int64 a[100][100];
int n;
int main()
{
	while(cin>>n,n!=-1)
	{
		char c;
		memset(f,0,sizeof(f));
		for ( int i = 1; i <= n; i++ )
			for ( int j = 1; j <= n; j++ )
			{
				{
					cin>>c;
					a[i][j]=c-'0';
				}
			}
		f[1][1]=1;
		for ( int i = 1; i <= n; i++ )
		{
			for ( int j = 1; j <= n; j++ )
			if(a[i][j]>0)
			{
				//if(i==1 && j==1)continue;
				f[a[i][j]+i][j]+=f[i][j];
				f[i][a[i][j]+j]+=f[i][j];
			}
		}
		cout<<f[n][n]<<endl;
	}
	//system("pause");
}