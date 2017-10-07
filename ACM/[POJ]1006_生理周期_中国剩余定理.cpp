#include <cstdio>
#include <cmath>
const int M = 23*28*33;
const int m[]={23,28,33};
struct triple
{
	int d,x,y;
	triple(int d,int x,int y){this->x = x;this->y=y;this->d = d;}
};
triple gcdex(int a,int b)
{
	if(b==0)return triple(a,1,0);
	triple t = gcdex(b,a%b);
	return triple(t.d,t.y,t.x-t.y*(a/b));
}
int a[3];
int n,G;
int Mi[3];
int T[3];
int main()
{
	for (int i = 0; i<3; i++)
	{
		Mi[i] = M / m[i];
		triple t = gcdex(Mi[i], m[i]);
		T[i] = t.x;
		while (T[i]<0)T[i] += m[i];
	}

	for(;;)
	{
		G++;
		scanf("%d%d%d%d",&a[0],&a[1],&a[2],&n);
		if(a[0]==a[1] && a[1]==a[2] && a[2]==n && n==-1)break;
		int ans=0;
		for(int i=0;i<3;i++)
		{
			ans+=a[i]*Mi[i]*T[i];
		}
		ans%=M;
		if(ans-n<=0)ans+=M;
		printf("Case %d: the next triple peak occurs in %d days.\n",G,ans-n);
	}
}
