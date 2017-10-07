#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;
#define Size(x) (x?x->sz:0)
#define Sum(x) (x?x->sum:0)
/*
一个是用int64
另一个是pushdown的时候有标记才下传，否则直接返回
*/
struct Node
{
	Node* ch[2],* pre;
	int sz;
	__int64 val,sum,delta;
	Node(int v)
	{
		sum=val=v;
		sz=1;delta=0;
		ch[0]=ch[1]=pre=NULL;
	}
};
char op[10];
int a[200001];
int x,y;
__int64 z;
int N,M;
Node* root;
void add(Node* x,__int64 c)
{
	if(x){
		x->delta+=c;
		x->val += c;
		x->sum+=c*x->sz;
	}
}
void pushdown(Node* x)
{
	if(x && x->delta)
	{
		add(x->ch[0],x->delta);add(x->ch[1],x->delta);
		x->delta=0;
	}
}
void update(Node* x)
{
	x->sz = Size(x->ch[0])+Size(x->ch[1])+1;
	x->sum = Sum(x->ch[0])+Sum(x->ch[1])+x->val;
}
void Rotate(Node* x,int c)
{
	Node* y=x->pre;
	pushdown(y),pushdown(x);

	y->ch[!c]=x->ch[c];
	if(x->ch[c])x->ch[c]->pre=y;

	x->pre=y->pre;
	if(y->pre)y->pre->ch[y->pre->ch[1]==y]=x;

	y->pre=x;
	x->ch[c]=y;

	update(y);
	if(root==y)root=x;
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
Node* find(int k)
{
	for(Node* x=root;;)
	{
		pushdown(x);
		int t=Size(x->ch[0]);
		if(k==t+1)return x;
		if(k<=t)x=x->ch[0];
		else
		{
			x=x->ch[1];
			k-=t+1;
		}
	}
}
Node* slice(int l,int r)
{
	Node* L = find(l-1);
	Node* R = find(r+1);
	splay(L,NULL);splay(R,L);
	return R->ch[0];
}
Node* build(int l, int r)
{
	if (l>r)return NULL;
	if (l == r)return new Node(a[l]);
	int m = (l + r) >> 1;
	Node* L = build(l, m - 1);
	Node* R = build(m + 1, r);
	Node* P = new Node(a[m]);
	P->ch[0] = L; P->ch[1] = R;
	if (L)L->pre = P;
	if (R)R->pre = P;
	update(P);
	return P;
}

void init()
{
	root=new Node(0);
	Node* tail=new Node(0);
	root->ch[1]=tail;
	tail->pre=root;
	Node* t=build(0,N-1);
	tail->ch[0]=t;
	t->pre=tail;
	splay(t,NULL);
}

int main()
{
	scanf("%d %d",&N,&M);
	for (int i = 0; i < N; i++)
	{
		scanf("%d",&a[i]);
	}
	init();
	for (int i = 0; i < M; i++)
	{
		scanf("%s",&op);
		if(op[0]=='Q')
		{
			scanf("%d%d",&x,&y);
			Node* t = slice(x+1,y+1);
			printf("%lld\n",t->sum);
		}
		else
		{
			scanf("%d%d%lld",&x,&y,&z);
			Node* t=slice(x+1,y+1);
			if(t)
			{
				add(t,z);
				splay(t,NULL);
			}
		}
	}
}