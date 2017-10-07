#include <iostream>
using namespace std;
int f[3][1000];
int l[3];
int n,m;
void plus(int* a,int l1,int* b,int l2,int* res,int* l3)
{
	*l3=1l+l2+3;
	for ( int i = 0; i < *l3; i++ )
	{
		res[i]+=a[i]+b[i];
		res[i+1]=res[i]/10;
		res[i]%=10;
	}
	while(res[*l3-1]==0)*l3=*l3-1;
}
int main()
{
	cin>>n;
	while ( n-- )
	{
		cin>>m;
		memset(f[1], 0, sizeof(f[1]));
		memset(f[2], 0, sizeof(f[2]));
		
		f[1][0]=1;l[1]=1;
		f[2][0]=1;l[2]=1;
		for ( int i = 3; i <= m; i++ )
		{
			memset(f[i%3],0,sizeof(f[i%3]));l[i%3]=0;
			::plus(f[(i+2)%3],l[(i+2)%3],f[(i+1)%3],l[(i+1)%3],f[i%3],&l[i%3]);
		}
		for ( int j = l[m%3]-1; j >=0 ; j-- )
		{
			cout<<f[m%3][j];
		}
		cout<<endl;
	}
}