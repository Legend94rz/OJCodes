#include <iostream>
class Node
{
public:
	Node* pnext;
	int no;
	Node(int x){no=x;pnext=NULL;}
};
Node* head;
Node* tail;
using namespace std;
int n,k;
int main()
{
	cin>>k;	
	while ( k-- )
	{
		cin>>n;
		int m=0,ct=0;
		Node* t,* p;
		tail=head=new Node(0);
		for ( int i = 1; i <= n; i++ )
		{
			t=new Node(i);
			tail->pnext=t;
			tail=t;
		}
		while ( n>3 )
		{	
			p=head;
			t=head->pnext;
			int N=n;
			for ( int i = 1; (i <= N) && t; i++ )
			{
				if ( i % 2 == 0 && ct == 0 || i%3 == 0 && ct == 1)
				{
					p->pnext=t->pnext;
					n--;
				}
				p=t;
				t=t->pnext;
			}
			ct=1-ct;
		}
		t=head->pnext;cout<<t->no;t=t->pnext;
		while ( t )
		{
			cout<<' '<<t->no;
			t=t->pnext;
		}
		cout<<endl;
	}

	//system("pause");
}
