#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <limits>
using namespace std;
int pre[1000001],f[1000001],a[1000001];
int n,m;
int max(int a,int b)
{
	if(a>b)return a;
	return b;
}
int main()
{
	while ( scanf("%d%d",&m,&n)!=EOF )
	{
		for ( int i = 1; i <= n; i++ )
		{
			scanf("%d", &a[i]);
		}
		memset(pre, 0, sizeof(pre));
		memset(f, 0, sizeof(f));
		int maxx;
		for ( int i = 1; i <= m; i++ )
		{
			maxx=INT_MIN;
			for ( int j = i; j <= n; j++ )
			{
				f[j]=max(pre[j-1],f[j-1])+a[j];
				pre[j-1]=maxx;
				maxx=max(maxx,f[j]);
			}
		}
		cout<<maxx<<endl;
	}
	//system("pause");
}