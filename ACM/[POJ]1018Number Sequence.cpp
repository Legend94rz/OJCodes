#include <iostream>
#include <climits>
#include <cmath>
#include <cstdio>
using namespace std;
int n,x,T;
typedef __int64 int64;
int64 L;
int pow(int a,int b)
{
	return (int)pow((double)a,(double)b);
}
int64 getlen(int k)
{
	int c = (int)floor(log10((double)k))+1;
	if(c>1)
	{
		int s=0;
		for(int i=1;i<c;i++)
			s+=i*9*pow(10,i-1);
		s+=c*(k-pow(10,c-1)+1);
		return s;
	}
	return k;
}
int main()
{
	cin>>n;
	while(n--)
	{
		cin >> x;
		L=0;
		for (T = 1;; T++)
		{
			int l = getlen(T);
			if(L + l >= x)break;
			L+=l;
		}
		int r=x-L;
		int p=1;
		while(r>0)
		{
			int a = p*9*pow(10,p-1);
			if(r>a)
				r-=a;
			else
			{
				int tmp = r/p+pow(10,p-1)-1;
				if(r%p==0)
					cout<<tmp%10<<endl;
				else
					cout<<(tmp+1)/(int)pow(10,p-r%p)%10<<endl;
				break;
			}
			p++;
		}
	}
}
