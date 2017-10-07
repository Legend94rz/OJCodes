#include <iostream>
#include <string>
using namespace std;
int n;
char c;
int hei,cu,a,shangH,xiaH;
string zBlank,bi,fenge,zhongBlank;
int main()
{
	cin>>n;
	while ( n-- )
	{
		cin>>c;
		cin>>hei;
		cu=hei/6+1;
		shangH=(hei-3)/2;
		xiaH=hei-3-shangH;
		zhongBlank=fenge = bi = zBlank = "";
		for ( int i = 0; i<cu; i++ )zBlank += ' ';
		for ( int i = 0; i<xiaH; i++ )zhongBlank += ' ';
		for(int i=0;i<cu;i++)bi+=c;
		for(int i=0;i<xiaH;i++)fenge+=c;
		cout << zBlank << fenge << endl;
		for(int i=0;i<shangH;i++)
			cout<< bi<<zhongBlank<<bi<<endl;
		cout << zBlank << fenge << endl;
		for ( int i = 0; i<xiaH; i++ )
			cout<<bi<<zhongBlank<<bi<<endl;
		cout << zBlank << fenge << endl;
		if(n)
			cout<<endl;
	}
	//system("pause");
}
