#include <iostream>
using namespace std;
int n;
int a[100], out[100];
int f[100];
bool check(int x)
{
	int p=0;
	int rest=2*n;
	while(rest>n)
	{
		p=(p+x-1)%rest+1;
		if(p>n)
		{
			rest--;p--;
		}
		else
			return false;
	}
	return true;
}
int main()
{
	for (;;)
	{
		cin >> n;
		if (n == 0)break;
		if (f[n] != 0)
			cout << f[n] << endl;
		else
		{
			bool flag=false;
			for (int k = 1;; k++)
			{
				for (int i = (n + 1)*k;i<=(n+1)*k+1; i++)
				{
					if (check(i))
					{
						cout << i << endl;
						f[n] = i;flag=true;
						break;
					}
				}
				if(flag)break;
			}
		}
	}
}
