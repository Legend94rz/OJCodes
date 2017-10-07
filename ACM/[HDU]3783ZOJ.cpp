#include <iostream>
#include <string>
using namespace std;
string s;
int Z,O,J;

int main()
{
	for(;;)
	{
		cin>>s;
		if(s=="E")break;
		Z=O=J=0;
		for(int i=0;i<s.length();i++)
		{
			switch (s[i])
			{
				case 'Z':Z++;break;
				case 'O':O++;break;
				case 'J':J++;break;
			}
		}
		for(;;)
		{
			if(Z>0){cout<<'Z';Z--;}
			if(O>0){cout<<'O';O--;}
			if(J>0){cout<<'J';J--;}
			if(Z==O && O==J && Z==0)break;
		}
		cout<<endl;
	}
}