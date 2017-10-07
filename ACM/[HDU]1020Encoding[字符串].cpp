#include <iostream>
#include <string>
using namespace std;
int N;
char s[10010];
int main()
{
	cin>>N;
	for ( int i = 0; i < N; i++ )
	{
		memset(s,0,sizeof(s));
		cin>>s;int c=1;
		for ( int j = 0; s[j]!='\0';  )
		{
			int k=j;
			do{
				j++;
			}while(s[j]==s[k]);
			if(j-k>1)
				cout<<j-k;
			cout<<s[k];
		}
		cout<<endl;
	}
}
