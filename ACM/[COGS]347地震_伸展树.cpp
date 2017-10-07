#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define Size(x) (x?x->sz:0)
#define Max(x) (x?x->max:-0x3f3f3f3f)
using namespace std;
struct Node{
	Node* ch[2],* pre;
	int sz;
	long long val,delta,max;
	Node(long long v)
	{
		val=max=v;
		sz=1;delta=0;
		ch[1]=ch[0]=pre=NULL;
	}
};
int N,M;
Node* root;
int a[1500000];
char op[10];
int x,y;
long long z;
void add(Node* x,long long c)
{
	if(x)
	{
		x->delta+=c;
		x->max+=c;
		x->val+=c;
	}
}
void pushdown(Node* x)
{
	if(x && x->delta)
	{
		add(x->ch[0],x->delta);
		add(x->ch[1],x->delta);
		x->delta=0;
	}
}
void update(Node* x)
{
	x->sz = Size(x->ch[0])+Size(x->ch[1])+1;
	x->max=max( Max(x->ch[0]), max( Max(x->ch[1]) , x->val ) );
}
Node* build(int l,int r)
{
	if(l>r)return NULL;
	if(l==r)return new Node(a[l]);
	int m=(l+r)>>1;
	Node* p=new Node(a[m]);
	Node* L=build(l,m-1);
	Node* R=build(m+1,r);
	p->ch[0]=L;
	p->ch[1]=R;
	if(L) L->pre=p;
	if(R) R->pre=p;
	update(p);
	return p;
}
void rotate(Node* x,int c)
{
	Node* y=x->pre;
	pushdown(y),pushdown(x);

	y->ch[!c]=x->ch[c];
	if(x->ch[c])x->ch[c]->pre=y;

	x->pre=y->pre;
	if(y->pre)y->pre->ch[y->pre->ch[1]==y]=x;

	y->pre=x;
	x->ch[c]=y;

	if(root==y)root=x;
	update(y);
}
void splay(Node* x,Node* f)
{
	for(pushdown(x);x->pre!=f;)
	{
		Node* y=x->pre;
		Node* z=y->pre;
		if(z==f)
			rotate(x,y->ch[0]==x);
		else
			if(z->ch[0]==y)
				if(y->ch[0]==x)
					rotate(y,1),rotate(x,1);
				else
					rotate(x,0),rotate(x,1);
			else
				if(y->ch[0]==x)
					rotate(x,1),rotate(x,0);
				else
					rotate(y,0),rotate(x,0);
	}
	update(x);
}
Node* find(int k)
{
	for(Node* x = root;;)
	{
		pushdown(x);
		int t=Size(x->ch[0]);
		if(k==t+1)return x;
		if(k<=t)
			x=x->ch[0];
		else
		{
			x=x->ch[1];
			k-=t+1;
		}
	}
}
Node* slice(int l,int r)
{
	Node* L=find(l-1);
	Node* R=find(r+1);
	splay(L,NULL);
	splay(R,L);
	return R->ch[0];
}
void init()
{
	root=new Node(0);
	Node* tail=new Node(0);
	root->ch[1]=tail;
	tail->pre=root;
	Node* t=build(0,N-1);
	t->pre=tail;
	tail->ch[0]=t;
	splay(t,NULL);
}
void print(Node* x)
{
	if(!x)return ;
	pushdown(x);
	print(x->ch[0]);
	printf("%lld ",x->val);
	print(x->ch[1]);
}
int main()
{
	freopen("equake.in","r",stdin);freopen("equake.out","w",stdout);
	scanf("%d %d",&N,&M);
	for (int i = 0; i < N; i++)
	{
		scanf("%d",&a[i]);
	}
	init();
	for (int i = 0; i < M; i++)
	{
		scanf("%s",&op);
		if(op[0]=='R')
		{
			scanf("%d%d%lld",&x,&y,&z);
			Node* t=slice(x+1,y+1);
			add(t,z);splay(t,NULL);
		}
		else if(op[0]=='I')
		{
			scanf("%d %d",&x,&y);
			for (int j = 0; j < y; j++)
			{
				scanf("%d",&a[j]);
			}
			Node* t=build(0,y-1);
			//Todo:区间对不对？
			slice(x+2,x+1);
			t->pre=root->ch[1];
			root->ch[1]->ch[0]=t;
			splay(t,NULL);
		}
		else if(op[0]=='Q')
		{
			scanf("%d%d",&x,&y);
			Node* t=slice(x+1,y+1);
			printf("%lld\n",t->max);
		}
		else
		{
			scanf("%d%d", &x, &y);
			Node* t = slice(x + 1, y + 1);
			t->pre=NULL;
			root->ch[1]->ch[0]=NULL;
			splay(root->ch[1],NULL);
		}
		//print(root);printf("\n");
	}
	fclose(stdin);fclose(stdout);
}
