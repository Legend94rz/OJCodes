#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
int n;
class BigNum
{
public:
	int num[500];
	int l;
public:
	BigNum operator *(int x)
	{
		BigNum res(0);
		res.l=l+5;
		for ( int i = 0; i < res.l; i++ )
			res.num[i]+=num[i]*x;
		for ( int i = 0; i < res.l; i++ )
		{
			res.num[i+1]+=res.num[i]/10;
			res.num[i]%=10;
		}
		while(res.l>1 && res.num[res.l-1]==0)res.l--;
		return res;
	}
	BigNum operator*(const BigNum& bignum)
	{
		BigNum res(0);res.l=bignum.l+l+1;
		for(int i=0;i<l;i++)
			for(int j=0;j<bignum.l;j++)
				res.num[i+j]+=num[i]*bignum.num[j];
		for ( int i = 0; i < res.l; i++ )
		{
			res.num[i+1]+=res.num[i]/10;
			res.num[i]%=10;
		}
		//while(res.l>1&& res.num[res.l-1]==0)res.l--;
		return res;
	}
	BigNum operator +(const BigNum& bignum)
	{
		BigNum res(0);res.l=l;if(res.l<bignum.l)res.l=bignum.l;
		for ( int i = 0; i < res.l; i++ )
		{
			res.num[i]+=num[i]+bignum.num[i];
			res.num[i + 1] = res.num[i] / 10;
			res.num[i] %= 10;
		}
		if(res.num[res.l]>0)
			res.l++;
		return res;
	}
	BigNum(int x)
	{
		memset(num, 0, sizeof(num));
		num[0]=x;
		l=1;
	}
	BigNum(){memset(num,0,sizeof(num)); l=0;}
};
BigNum f[102];
int main()
{
	while(cin>>n,n)
	{
		memset(f, 0, sizeof(f));
		f[0]=1;f[1]=1;
		for ( int i = 2; i <= n; i++ )
		{
			for ( int j = 0; j < i; j++ )
			{
				f[i] = f[i] + f[j] * f[i - j - 1];
			}
		}
		for ( int j = 2; j <= n; j++ )
		{
			f[n] = f[n] * j;
		}
		for ( int i = f[n].l-1; i >=0; i-- )
		{
			cout<<f[n].num[i];
		}
		cout<<endl;
	}
	//system("pause");
}
