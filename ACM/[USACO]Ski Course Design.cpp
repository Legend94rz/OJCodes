/*
USER: rz109291
PROG: skidesign
LANG: C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int n;
int a[2001];
int cmp(const void* a,const void* b)
{
	return *(const int*)a < *(const int*)b;
}
int main()
{
	freopen("skidesign.in","r",stdin);freopen("skidesign.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int ans=1<<30;
	for(int low = 0;low<=100;low++)
	{
		int temp=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]<low)
				temp+=pow(a[i]-low,2);
			if(a[i]>low+17)
				temp+=pow(low+17-a[i],2);
		}
		if (temp<ans)ans=temp;
	}
	printf("%d\n",ans);
	fclose(stdin);fclose(stdout);
}