#include <iostream>
#include <stdio.h>
using namespace std;
char a[1001];
bool deal(string& s,int* a,int* b,int* c)
{
	int cz = 0,cj=0,pz,pj;
	for(int i=0;i<s.length();i++)
		if(s[i]=='z')
		{
			cz++;pz=i;
		}
		else if(s[i]=='j')
		{
			cj++;pj=i;
		}
	if(cz!=1 || cj!=1)return false;
	*a = pz;
	*b = pj-pz-1;
	*c = s.length()-pj-1;
	return true;
}
int main()
{
	//freopen("a.txt","r",stdin);
	int A,B,C;
	while(scanf("%s",&a)!=EOF)
	{
		string ta(a);
		if(ta.length()<=0)break;
		bool f = deal(ta,&A,&B,&C);
		if(C==B*A && f && B>0)
			cout<<"Accepted"<<endl;
		else
			cout<<"Wrong Answer"<<endl;
	}
	//system("pause");
}