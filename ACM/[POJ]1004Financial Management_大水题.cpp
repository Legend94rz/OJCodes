#include <iostream>
#include <cstdio>
using namespace std;
double x,s;
int main()
{
	for(int i=0;i<12;i++)
	{
		cin>>x;
		s+=x;
	}
	printf("$%.2lf\n",s/12);
}