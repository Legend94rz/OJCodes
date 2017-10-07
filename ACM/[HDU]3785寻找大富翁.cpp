#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
vector<int> a;
int n,m,t;
int main()
{
	for(;;)
	{
		scanf("%d%d",&n,&m);
		if(n==m && n==0)break;
		a.clear();
		for(int i=0;i<n;i++)
		{
			scanf("%d",&t);
			a.push_back(t);
		}
		partial_sort(a.begin(),a.begin()+((m<n)?m:n),a.end(),greater<int>());
		for(int i=0;i<((m<n) ? m : n);i++)
			if(i==0)
				printf("%d",a[i]);
			else
				printf(" %d", a[i]);
		printf("\n");
	}
}
