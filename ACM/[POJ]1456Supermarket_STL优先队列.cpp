#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <functional>
using namespace std;
struct prod
{
	int px,dx;
};
prod a[10001];
int n;
int cmp(const void* a,const void* b)
{
	const prod* pa = (const prod*)a;
	const prod* pb = (const prod*)b;
	if(pa->dx < pb->dx)
		return -1;
	else if(pa->dx > pb->dx)
		return 1;
	else if(pa->px < pb->px)
		return 1;
	else if(pa->px > pb->px)
		return -1;
	return 0;
}
int main()
{
	while(~scanf("%d",&n))
	{
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a[i].px,&a[i].dx);
		}
		qsort(a,n,sizeof(prod),cmp);
		priority_queue<int,vector<int>,greater<int>> q;
		int ans=0;
		for(int i=0;i<n;i++)
		{
			if(q.size()<a[i].dx)
			{
				q.push(a[i].px);
			}
			else if(q.top()<a[i].px && q.size()==a[i].dx)
			{
				q.pop();
				q.push(a[i].px);
			}
		}
		while(!q.empty())
		{
			ans+=q.top();
			q.pop();
		}
		printf("%d\n",ans);
	}
}