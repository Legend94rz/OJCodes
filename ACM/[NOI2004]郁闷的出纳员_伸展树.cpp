#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
#define Size(x) (x==NULL?0:x->sz)
#define Count(x) (x==NULL?0:x->cnt)
struct Node
{
	Node* ch[2];
	Node* pre;
	int val;
	int sz;
	int cnt;
	Node(int x,Node* parent)
	{
		ch[0]=ch[1]=NULL;
		pre=parent;
		sz=cnt=1;
		val = x;
	}
};
Node* root;
int n,x;
char c;
int ans;
int lim, lim0;
void update(Node* x)
{
	if(x)
		x->sz = Count(x)+Size(x->ch[0])+Size(x->ch[1]);
}
void Rotate(Node* x,int c)
{
	Node* y=x->pre;

	y->ch[!c]=x->ch[c];
	if(x->ch[c])x->ch[c]->pre=y;

	x->pre=y->pre;
	if(y->pre)y->pre->ch[y->pre->ch[1]==y]=x;

	y->pre=x;
	x->ch[c]=y;

	update(y);
	if(root==y)root=x;
}
void splay(Node* x,const Node* f)
{
	for(;x->pre!=f;)
	{
		Node* y=x->pre;
		Node* z=y->pre;
		if(z==f)
			Rotate(x,y->ch[0]==x);
		else
			if(z->ch[0]==y)
				if(y->ch[0]==x)
					Rotate(y,1),Rotate(x,1);
				else
					Rotate(x,0),Rotate(x,1);
			else
				if(y->ch[1]==x)
					Rotate(y,0),Rotate(x,0);
				else
					Rotate(x,1),Rotate(x,0);
	}
	update(x);
}
Node* find(int k)
{
	for(Node* x=root;;)
	{
		int tmp=Size(x->ch[1]);
		if(k<=tmp)
			x=x->ch[1];
		else if(k<=tmp+Count(x))
			return x;
		else
			k-=tmp+x->cnt,x=x->ch[0];
	}
}
void insert(int x)
{
	Node* f=NULL;
	Node** p=&root;
	for(;;)
	{
		if(!(*p))
		{
			*p=new Node(x,f);
			if(f)f->ch[x>f->val]=*p;
			break;
		}
		else if((*p)->val==x)
		{
			(*p)->cnt++;
			break;
		}
		else
		{
			f=*p;
			p=&(f->ch[x>(*p)->val]);
		}
	}
	splay(*p, NULL);
}
void remove()
{
	Node* f=NULL;
	Node* p=root;
	for(;p;)
	{
		if(p->val>=lim)
		{
			f=p;
			p=p->ch[0];
		}
		else
		{
			ans += Size(p->ch[0]) + Count(p);
			if (p->ch[1])
			{
				p->ch[1]->pre = f;
			}
			if (f)
				f->ch[f->ch[1] == p] = p->ch[1];
			else
				root = p->ch[1];
			p=p->ch[1];
		}
	}
	if(f)
		splay(f,NULL);
}
int main()
{
	scanf("%d %d\n",&n,&lim);
	lim0=lim;
	for (size_t i = 0; i < n; i++)
	{
		cin>>c>>x;
		switch (c)
		{
			case 'I':
				if(x<lim0)continue;
				insert(x+lim-lim0);
			break;
			case 'S':
				lim+=x;
				remove();
			break;
			case 'A':
				lim-=x;
			break;
			case 'F':
				if(x>Size(root))
					cout<<-1<<endl;
				else
					printf("%d\n",find(x)->val-lim+lim0);
			break;
		}
	}
	printf("%d\n",ans);
}