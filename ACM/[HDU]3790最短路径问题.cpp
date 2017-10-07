#include <stdio.h>
#include <string.h>
const int N = 100001;
int n,m;
int head[N],ed[N],Next[N],len[N],cost[N];
int a,b,d,p,tot,S,T;
int dis[N],cst[N];
int q[N];
bool vis[N];
int l,r;
void add(int a,int b,int d,int p)
{
	tot++;
	ed[tot]=b;
	len[tot]=d;
	cost[tot]=p;
	Next[tot]=head[a];
	head[a]=tot;
}
void spfa(int s,int t)
{
	l=-1;r=0;
	q[r] = s;vis[s]=true;
	memset(dis,0x3f3f3f3f,sizeof(dis));dis[s]=0;
	memset(cst,0x3f3f3f3f,sizeof(cst));cst[s]=0;
	while(l!=r)
	{
		l++;if(l>=N)l=0;
		int k=q[l];
		int ege=head[k];
		while(ege!=0)
		{
			int b=ed[ege];
			if(dis[k]+len[ege]<dis[b])
			{
				dis[b] = dis[k]+len[ege];
				cst[b] = cst[k]+cost[ege];
				if(!vis[b])
				{
					r++;if(r>=N)r=0;
					vis[b]=true;
					q[r]=b;
				}
			}
			else if(dis[k]+len[ege]==dis[b] && cst[k]+cost[ege]<cst[b])
			{
				cst[b] = cst[k]+cost[ege];
			}
			ege=Next[ege];
		}
		vis[k] = false;
	}
	printf("%d %d\n",dis[t],cst[t]);
}
int main()
{
	for(;;)
	{
		scanf("%d%d",&n,&m);
		if(n==m && n==0)break;
		memset(head,0,sizeof(head));
		tot=0;

		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d%d",&a,&b,&d,&p);
			add(a,b,d,p);
			add(b,a,d,p);
		}
		scanf("%d%d",&S,&T);
		spfa(S,T);
	}
	//system("pause");
}
