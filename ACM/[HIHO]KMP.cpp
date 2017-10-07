#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int n;
char T[1000001],P[10001];
int f[10001];
int tot;
int main()
{
	cin>>n;cin.get();
	while ( n-- )
	{
		tot=0;
		P[0]=T[0]=' ';
		cin.getline(&P[1],sizeof(P));
		cin.getline(&T[1],sizeof(T));
		//cout<<T<<endl;
		//cout<<P<<endl;
		int n=strlen(P);int m=strlen(T);
		int k=0;
		for(int i=2;i<=n;i++)
		{
			while(k>0 && P[k+1]!=P[i])k=f[k];
			if(P[k+1]==P[i])k++;
			f[i]=k;
		}
		k=0;
		for(int i=1;i<=m;i++)
		{
			while(k>0 && P[k+1]!=T[i])k=f[k];
			if(P[k+1]==T[i])k++;
			if(k==n-1){
				tot++;k=f[k];
			}
		}
		cout<<tot<<endl;
	}
	//system("pause");
}
