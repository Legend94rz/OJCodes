#include <cstdio>
#include <cmath>
int main()
{
	int n;
	double x, y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf %lf",&x,&y);
		printf("Property %d: This property will begin eroding in year %d.\n",i,(int)ceil(3.1415926*(x*x+y*y)/100));
	}
	printf("END OF OUTPUT.\n");
}