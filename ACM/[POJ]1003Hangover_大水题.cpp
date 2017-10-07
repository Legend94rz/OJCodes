#include <cstdio>
#include <cmath>
using namespace std;
double x;
int main()
{
	for (;;)
	{
		scanf("%lf", &x);
		if(abs(x)<=0.00001)break;
		double s = 0;
		int i;
		for(i=2;;i++)
		{
			s+=1.0/i;
			if(s>=x)
				break;
		}
		printf("%d card(s)\n",i-1);
	}
}
