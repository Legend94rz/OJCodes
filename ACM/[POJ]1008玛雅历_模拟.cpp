#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int n;
int d,m,y;
char month1[10];
const char* Haab[]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", 
					"mol", "chen", "yax", "zac", "ceh", "mac", "kankin",
					"muan", "pax", "koyab", "cumhu", "uayet" };
const int L1 = 19;
const char* Tzolkin[]={0,"imix", "ik", "akbal", "kan", "chicchan", "cimi",
						"manik", "lamat", "muluk", "ok", "chuen", "eb",
						"ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau" };
const int L2 = 21;
int main()
{
	cin>>n;
	cout<<n<<endl;
	for(int i=0;i<n;i++)
	{
		scanf("%d. %s %d", &d, &month1, &y);
		int j;
		for(j=1;j<=L1;j++)
		{
			if(strcmp(Haab[j-1],month1)==0)
				break;
		}
		int ds;
		ds = 365*y + (j-1)*20 + d+1;
		int Y = ds/260;
		int r = ds%260;
		if(r==0)Y--;
		printf("%d %s %d\n",r%13==0?13:r%13,Tzolkin[r%20==0?20:r%20],Y);
	}
}