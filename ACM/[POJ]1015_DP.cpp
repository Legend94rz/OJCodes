#include <cstdio>
#include <cstring>
int f[202][22][802],path[202][22][802];
int n, m, offset,cnt;
int d[202], p[202], sub[202], sum[202];
void print(int i,int j,int k)
{
	if(j==0)
		return ;
	if(path[i][j][k]==1)
	{
		print(i-1,j,k);
	}
	else
	{
		print(i-1,j-1,k-sub[i]);
		printf(" %d",i);
	}
}
int main()
{
	while(scanf("%d %d", &n, &m),n+m)
	{
		cnt++;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d %d",&p[i],&d[i]);
			sub[i] = d[i] - p[i];
			sum[i] = d[i] + p[i];
		}
		memset(f, -0x3f3f3f3f, sizeof(f));
		memset(path,0,sizeof(path));
		offset = 20 * m;
		f[0][0][offset]=0;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= m; j++)
				for (int k = 0; k <= 2 * offset; k++)
				{
					f[i][j][k] = f[i - 1][j][k];
					path[i][j][k] = 1;
					if (j>0 && k-sub[i]>=0 && k-sub[i]<=2*offset && f[i][j][k] < f[i - 1][j - 1][k - sub[i]] + sum[i])
					{
						f[i][j][k] = f[i - 1][j - 1][k - sub[i]] + sum[i];
						path[i][j][k] = 2;
					}
				}
		int minDiff=0, maxSum;
		for (int delta = 0; delta <= offset; delta++)
		{
			int t1 = f[n][m][offset + delta];
			int t2 = f[n][m][offset - delta];
			if (t1 >= 0 || t2 >= 0)
			{
				printf("Jury #%d\n",cnt);
				if (t1 > t2)
				{
					minDiff = delta;
					maxSum = t1;
				}
				else
				{
					minDiff = -delta;
					maxSum = t2;
				}
				printf("Best jury has value %d for prosecution and value %d for defence:\n",(maxSum-minDiff)/2,(maxSum+minDiff)/2);
				break;
			}
		}
		print(n,m,minDiff+offset);
		printf("\n\n");
	}
}
