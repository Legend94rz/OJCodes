#include <iostream>
#include <string>
#include <vector>
using namespace std;
int POS;
class Single
{
private:
	char c;
public:
	int n;
	virtual void decode()
	{
		for ( int i = 0; i < n; i++ )
		{
			cout<<c;
		}
	}
	Single(int N,char C){ n=N;c=C;}
	Single(){}
};
class Pack : public Single
{
public:
	vector<Single*> list;
	virtual void decode()
	{
		for ( int j = 0; j < n; j++ )
		{
			for ( int i = 0; i < list.size(); i++ )
			{
				list[i]->decode();
			}
		}
	}
	Pack(int N){n=N;};
	Pack(){}
};
Single* root;
string s;
void prepare(string& s)
{
	for ( int i = s.length() - 1; i >= 0; i-- )
	{
		if((islower(s[i])|| s[i]=='(') && (i==0 || !isdigit(s[i-1])))
		{
			s.insert(i,1,'1');
		}
	}
	s="1("+s+")";
}
Single* build(int& p)
{
	int t=s[p]-'0';
	Single* sing=NULL;
	while(isdigit(s[p+1]))
	{
		t=t*10+s[p+1]-'0';
		p++;
	}
	if(s[p+1]=='(')
	{
		p+=2;
		sing=new Pack(t);
		while(s[p]!=')')		///Check
		{
			((Pack*)sing)->list.push_back(build(p));
		}
		p++;
	}
	else if(islower(s[p+1]))
	{
		sing=new Single(t,s[p+1]);
		p+=2;
	}
	return sing;
}
int m;
int main()
{
	cin>>m;
	while(m--)
	{
		cin>>s;
		POS=0;
		prepare(s);
		root=build(POS);
		root->decode();
		cout<<endl;
	}

	//system("pause");
}
