#include <iostream>
#include <string.h>
using namespace std;
int n,m,K,s;
int a,b;
int c[201],e[201];
int f[201][201];
int max(int a,int b)
{
	if(a>b)return a;
	return b;
}
int main()
{
	while(cin>>n>>m>>K>>s)
	{
		memset(f,0,sizeof(f));
		for ( int i = 1; i <= K; i++ )
		{
			cin>>e[i]>>c[i];
		}
		for ( int i = 1; i <= K; i++ )
		{
			for ( int j = 1; j <= s; j++ )
			{
				for ( int k = c[i]; k <= m; k++ )
				{
					f[j][k]=max(f[j][k],f[j-1][k-c[i]]+e[i]);
				}
			}
		}
		int k;
		for ( k = 0; k <= m; k++ )
			if(f[s][k]>=n)
				break;
		if(k>m || f[s][k]<n)
			cout<<-1<<endl;
		else
			cout<<m-k<<endl;
	}
	//system("pause");
}
