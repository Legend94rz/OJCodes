#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define Size(x) (x?x->sz:0)
#define Val(x) (x?x->val:0x3f3f3f3f)
class Node
{
public:
	Node* pre,* ch[2];
	int sz,val;
	int mini,k,ind,minind;
	bool rev;
	Node(int x,int i)
	{
		pre=ch[1]=ch[0]=NULL;
		val=mini=x;k=sz=1;
		rev=false;
		minind=ind=i;
	}
	~Node()
	{
		if(ch[0])delete ch[0];
		if(ch[1])delete ch[1];
		pre=ch[0]=ch[1]=NULL;
	}
};
Node* root;
int n;
int a[100001];
void update(Node* x)
{
	x->sz = Size(x->ch[0])+Size(x->ch[1])+1;
	x->mini = x->val;x->k = Size(x->ch[0])+1;x->minind = x->ind;
	if(x->ch[0])
	{
		if(x->ch[0]->mini < x->mini || x->ch[0]->mini == x->mini && x->ch[0]->minind < x->minind)
		{
			x->mini = x->ch[0]->mini;
			x->minind = x->ch[0]->minind;
		}
	}
	if(x->ch[1])
	{
		if(x->ch[1]->mini < x->mini || x->ch[1]->mini == x->mini && x->ch[1]->minind < x->minind)
		{
			x->mini = x->ch[1]->mini;
			x->k = Size(x->ch[0])+1+x->ch[1]->k;
			x->minind = x->ch[1]->minind;
		}
	}
}
void rev(Node* x)
{
	if(x)
	{
		if(x->ch[0] && x->mini==x->ch[0]->mini)x->k = Size(x->ch[1])+1+x->ch[0]->k;
		if(x->ch[1] && x->mini==x->ch[1]->mini)x->k = x->ch[1]->k;
		swap(x->ch[0],x->ch[1]);
		x->rev^=1;
	}
}
void pushdown(Node* x)
{
	if(x && x->rev)
	{
		rev(x->ch[0]);rev(x->ch[1]);
		x->rev=false;
	}
}
void Rotate(Node* x,int c)
{
	Node* y=x->pre;
	pushdown(y),pushdown(x);

	y->ch[!c] = x->ch[c];
	if(x->ch[c])x->ch[c]->pre=y;

	x->pre = y->pre;
	if(y->pre) y->pre->ch[y->pre->ch[1]==y]=x;

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
Node* build(int l,int r)
{
	if(l>r)return NULL;
	int m=(l+r)>>1;
	Node* L = build(l,m-1);
	Node* R = build(m+1,r);
	Node* p = new Node(a[m],m);
	p->ch[0]=L;if(L)L->pre=p;
	p->ch[1]=R;if(R)R->pre=p;
	update(p);
	return p;
}
void init()
{
	root=new Node(0,-1);
	Node* tail=new Node(0,n);
	root->ch[1]=tail;
	tail->pre = root;
	Node* t=build(0,n-1);
	tail->ch[0]=t;
	t->pre=tail;
	splay(t,NULL);
}
Node* find(int k)
{
	for(Node* x=root;;)
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
int findMinPos(int l,int r)
{
	Node* x = find(l-1);
	Node* y = find(r+1);
	splay(x,NULL);
	splay(y,x);
	return y->ch[0]->k;
}
void reverse(int l,int r)
{
	Node* x = find(l - 1);
	Node* y = find(r + 1);
	splay(x, NULL);
	splay(y, x);
	rev(y->ch[0]);
}
void print(Node* x)
{
	if(!x)return ;
	pushdown(x);
	print(x->ch[0]);
	printf("%d ",x->val);
	print(x->ch[1]);
}
int main()
{
	for(;;)
	{
		scanf("%d",&n);
		if(!n)break;
		for (int i = 0; i < n; i++)
		{
			scanf("%d",&a[i]);
		}
		init();
		for(int s=1;s<=n;s++)
		{
			int k=findMinPos(s+1,n+1)+s;
			reverse(s+1,k);
			printf("%d ",k-1);
			//printf("\n=========\n");
			//print(root);
			//printf("\n");
			//printf("=========\n");
		}
		printf("\n");
		delete root;
	}
	//system("pause");
}