#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int T;
string a,b;
int A[1500],B[1500],C[1500];
int la,lb,lc;
void init(const string& a,int A[],int& L)
{
	L = a.size();
	for (int i = a.size() - 1,j=0; i >= 0; i--,j++)
	{
		A[j]=a[i]-'0';
	}
}
int add(int A[],int la,int B[],int lb)
{
	for(int i=0;i<la || i<lb;i++)
	{
		C[i] += A[i]+B[i];
		C[i+1] += C[i]/10;
		C[i]%=10;
	}
	int t = max(la,lb);
	while(C[t]>0)t++;
	return t;
}
int main()
{
	scanf("%d",&T);
	for(int k=1;k<=T;k++)
	{
		cin>>a>>b;
		memset(A, 0, sizeof(A)); memset(B, 0, sizeof(B));
		init(a,A,la);init(b,B,lb);
		memset(C, 0, sizeof(C));
		lc = add(A,la,B,lb);
		printf("Case %d:\n",k);
		printf("%s + %s = ",a.c_str(),b.c_str());
		for(int i=lc-1;i>=0;i--)
			printf("%d",C[i]);
		printf("\n");
		if(k!=T) printf("\n");
	}
}
