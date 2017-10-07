#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int T, m, n, x, y;
char c;
//opp[x]表示以x为根的集合的对立集合的根是opp[x]
//另一种方法: opp[x]表示x点的对立集合的根是opp[x]所在的集合的根
int f[100001],opp[100001];
int getf(int x)
{
	int c,t;
	t=x;
	while(f[x]!=x)x=f[x];
	while(f[t]!=x)
	{
		c=f[t];
		f[t]=x;
		t=c;
	}
	return x;
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&m);
		for (int i = 0; i <= n; i++)
		{
			f[i] = i;opp[i] = 0;
		}
		while (m--)
		{
			scanf("\n%c %d %d",&c,&x,&y);
			int fx = getf(x);
			int fy = getf(y);
			if (c == 'D')
			{
				if(!opp[fx] && !opp[fy])
				{
					opp[fx] = fy;
					opp[fy] = fx;
				}
				else if(!opp[fx])
				{
					f[fx] = opp[fy];
					opp[fx] = fy;
				}
				else if(!opp[fy])
				{
					f[fy]= opp[fx];
					opp[fy] = fx;
				}
				else
				{
					f[fx] = opp[fy];
					f[fy] = opp[fx];
					opp[opp[fy]] = opp[fx];
					opp[opp[fx]] = opp[fy];
				}
			}
			else
			{
				if(fx==fy)
					printf("In the same gang.\n");
				else if(opp[fx] == fy && opp[fy]==fx && opp[fx] && opp[fy])
					printf("In different gangs.\n");
				else
					printf("Not sure yet.\n");
			}

		}
	}
	//system("pause");
}
