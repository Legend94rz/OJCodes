#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;
#define LOWER -0x3f3f3f3f
#define UPPER 0x3f3f3f3f
#define Size(x) (x==NULL?0:x->sz)
#define min(a,b) ((a)<(b)?(a):(b))
#define getMin(x) (x==NULL?UPPER:x->min+x->delta)
typedef void (*F)();
struct Node
{
	bool flip;
	int sz;
	int val;
	int delta;
	int min;
	Node* pre;
	Node* ch[2];
	Node(int x,Node* f)
	{
		flip=false;sz=1;min=val=x;pre=f;
		ch[0]=ch[1]=0;delta=0;
	}
};
int N,M;
char op[10];
int a,b,c;
Node* root;
void pushdown(Node* x)
{
	if(x)
	{
		if(x->flip)
		{
			swap(x->ch[0],x->ch[1]);
			if(x->ch[0])x->ch[0]->flip^=1;
			if(x->ch[1])x->ch[1]->flip^=1;
			x->flip=false;
		}
		if(x->ch[0])
			x->ch[0]->delta+=x->delta;
		if(x->ch[1])
			x->ch[1]->delta+=x->delta;
		x->val+=x->delta;
		x->delta=0;
	}
}
void update(Node* x)
{
	x->sz = Size(x->ch[0])+Size(x->ch[1])+1;
	x->min = min( min(getMin(x->ch[0]),getMin(x->ch[1])) ,x->val);
}
void Rotate(Node* x,int c)
{
	Node* y=x->pre;
	pushdown(y),pushdown(x);

	if(x->ch[c])x->ch[c]->pre = y;
	y->ch[!c]=x->ch[c];
	
	x->pre = y->pre;
	if(y->pre)y->pre->ch[y->pre->ch[1]==y] = x;

	x->ch[c]=y;
	y->pre=x;

	if(y==root)root=x;
	update(y);
}
Node* find(int k)
{
	Node* t=NULL;
	for(t=root;;)
	{
		pushdown(t);
		int tmp = Size(t->ch[0]);
		if(k==tmp+1)
			break;
		else if(k<=tmp)
			t=t->ch[0];
		else
		{
			k-=tmp+1;
			t=t->ch[1];
		}
	}
	return t;
}
void splay(Node* x,Node* f)
{
	for(pushdown(x);x->pre!=f;)
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
				if(y->ch[0]==x)
					Rotate(x,1),Rotate(x,0);
				else
					Rotate(y,0),Rotate(x,0);
	}
	update(x);
}

Node* slice(int a,int b)
{
	Node* p = find(a-1);
	Node* n = find(b+1);
	splay(p,NULL);
	splay(n,p);
	return n->ch[0];
}

void ADD()
{
	scanf("%d %d %d",&a,&b,&c);
	if(a>b)swap(a,b);
	Node* t=slice(a+1,b+1);
	if(t)t->delta+=c;
}
void REVERSE()
{
	scanf("%d %d",&a,&b);
	if (a>b)swap(a, b);
	Node* t=slice(a+1,b+1);
	if(t)t->flip^=1;
}
void REVOLVE()
{
	scanf("%d %d %d",&a, &b, &c);
	if (a>b)swap(a, b);
	int l = b-a+1;
	if(c<0)
		c=c-(c/l)*l+l;
	c%=l;
	if(c==0)return;
	Node* p=find(b-c+1);
	Node* n=find(b+2);
	splay(p,NULL);
	splay(n,p);
	Node* tmp = n->ch[0];
	n->ch[0]=NULL;
	splay(n,NULL);

	n = find(a+1);
	p = find(a);
	splay(p,NULL);
	splay(n,p);
	n->ch[0]=tmp;
	splay(n,NULL);
}
void _insert(int a,int b)
{
	Node* p = find(a + 1);
	Node* n = new Node(b, p);
	n->ch[1] = p->ch[1];
	if (p->ch[1])p->ch[1]->pre = n;
	splay(n, NULL);
}
void INSERT()
{
	scanf("%d %d", &a, &b);
	_insert(a,b);
}
void DELETE()
{
	scanf("%d",&a);
	Node* t = slice(a+1,a+1);
	t->pre->ch[0]=NULL;
	splay(t->pre,NULL);
}
void MIN()
{
	scanf("%d %d",&a, &b);
	if (a>b)swap(a, b);
	Node* t=slice(a+1,b+1);
	printf("%d\n", getMin(t));
}
const char* StdOp[] = { "ADD","REVERSE","REVOLVE","INSERT","DELETE","MIN" };
F pf[]={ADD,REVERSE,REVOLVE,INSERT,DELETE,MIN};
void init()
{
	Node* x=new Node(-0x3f3f3f3f,NULL);
	Node* y=new Node(0x3f3f3f3f,NULL);
	x->ch[1]=y;
	y->pre=x;
	root=x;
	update(root);
}
int main()
{
	scanf("%d",&N);
	init();
	for(int i=0;i<N;i++)
	{
		scanf("%d",&a);
		_insert(i,a);
	}
	scanf("%d",&M);
	for(int i=0;i<M;i++)
	{
		scanf("%s",&op);
		for(int j=0;j<sizeof(StdOp)/sizeof(char*);j++)
			if(!strcmp(StdOp[j],op))
				pf[j]();
	}
}
