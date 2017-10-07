#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
string deal(string a)
{
	for (int i = a.length() - 1; i >= 0; i--)
	{
		if(a[i]==',')
			a.erase(i,1);
	}
	return a;
}
int main()
{
	char ta[20],tb[20];
	string a,b;
	while(scanf("%s %s",&ta,&tb)!=EOF)
	{
		a=deal(ta);b=deal(tb);
		int A = atoi(a.c_str());
		int B = atoi(b.c_str());
		cout<<A+B<<endl;
	}
}