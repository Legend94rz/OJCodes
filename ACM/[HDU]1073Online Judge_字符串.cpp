#include <iostream>
#include <string>
using namespace std;
int n;
string s;
string data[2];
string blank[2];
char c,cn;
void move()
{
	c=cin.get();
	cn=cin.peek();
}
int main()
{
	cin>>n;
	while ( n-- )
	{
		for(int k=0;k<2;k++)
		{
			int i=0;blank[k]="";data[k]="";
			while(1)
			{
				cin>>s;
				if(s=="END")break;
				data[k]+=s;
				cn=cin.peek();
				while(cn==' '||cn=='\t'||cn=='\n')
				{
					blank[k]+=cn;
					move();
				}
			}
		}
		if(data[0]!=data[1])
			cout<<"Wrong Answer"<<endl;
		else
		if(blank[0]==blank[1])
			cout<<"Accepted"<<endl;
		else
			cout<<"Presentation Error"<<endl;
	}
}
