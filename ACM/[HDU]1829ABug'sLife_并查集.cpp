#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
const int N=2001;
int T;
int n,m;
int f[2*N],opp[2*N];
int a,b;
void init()
{
	for (int i = 0; i <= n; i++)
	{
		int o = i+N;
		f[i] = i;
		f[o] = o;
		opp[i] = o;
		opp[o] = i;
	}
}
int getf(int x)
{
	int c=x,t;
	while(x!=f[x])x=f[x];
	while(f[c]!=x)
	{
		t=f[c];
		f[c]=x;
		c=t;
	}
	return x;
}
void join(int a,int b)
{
	f[getf(a)]=getf(b);
}
int main()
{
	scanf("%d",&T);
	for(int k=1;k<=T;k++)
	{
		scanf("%d%d",&n,&m);
		init();
		bool flag=false;
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d",&a,&b);
			if(getf(a) == getf(b))
			{
				flag=true;
			}
			join(a,opp[b]);
			join(b,opp[a]);
		}
		printf("Scenario #%d:\n",k);
		if(flag)
		{
			printf("Suspicious bugs found!\n");
		}
		else
		{
			printf("No suspicious bugs found!\n");
		}
		printf("\n");
	}
	//system("pause");
}