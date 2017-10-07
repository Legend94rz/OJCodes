#include <iostream>
using namespace std;
int s[200];
int f[200][200];
int oud[200],ind[200];
int head[200],ed[200],Next[200];
int tot;
int n,m;
int x,y,root;
int min(int a,int b)
{
	if(a<b)return a;
	return b;
}
void add(int x,int y)
{
	tot++;
	ind[y]++;
	oud[x]++;
	ed[tot]=y;
	Next[tot]=head[x];
	head[x]=tot;
}
int calcSi(int root)
{
	int k,b,ege;
	ege=head[root];
	while(ege)
	{
		s[root]+=calcSi(ed[ege]);
		ege=Next[ege];
	}
	s[root]+=1;
	return s[root];
}
void solve(int r)
{
	int ege=head[r],b;
	while ( ege )
	{
		b=ed[ege];
		solve(b);
		for ( int j = s[r]; j >= 1; j-- )
			for ( int k = 1; k < j && k<=s[b]; k++ )
				f[r][j]=min(f[r][j],f[r][j-k]+f[b][k]-1);
		ege=Next[ege];
	}
}
int main()
{
	cin>>n>>m;
	for ( int i = 1; i <= n-1; i++ )
	{
		cin>>x>>y;
		add(x,y);
	}
	for(int i=1;i<=n;i++)if(ind[i]==0){root=i;break;}	
	s[root]=calcSi(root);
	memset(f,0x6f,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		f[i][1] = oud[i];
	}
	solve(root);
	int ans=0x7f7f7f7f;
	for ( int i = 1; i <= n; i++ )
		if(s[i]>=m)
		{
			ans=min(ans,f[i][m]+(i!=root));
		}
	cout<<ans<<endl;
	//system("pause");
}
