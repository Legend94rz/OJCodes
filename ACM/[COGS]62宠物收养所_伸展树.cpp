#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
const int E = 1000000;
#define Size(x) (x?x->sz:0)
struct Node
{
	Node* ch[2];
	Node* pre;
	int v, sz;
	Node(int v)
	{
		pre=ch[0]=ch[1]=NULL;
		sz=1;this->v=v;
	}
};
Node* root[2];
int n;
int a, b;
int ans;
void update(Node* x)
{
	if(x)
	{
		x->sz=Size(x->ch[0])+Size(x->ch[1])+1;
	}
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

	if(root[0]==y)root[0]=x;
	if(root[1]==y)root[1]=x;
	update(y);
}
void splay(Node* x,Node* f)
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
				if(y->ch[0]==x)
					Rotate(x,1),Rotate(x,0);
				else
					Rotate(y,0),Rotate(x,0);
	}
	update(x);
}
Node* insert(int r,int v)
{
	if(!root[r])
	{
		root[r]=new Node(v);
		return root[r];
	}
	Node* x = root[r];
	for(;x->ch[x->v < v]; x = x->ch[x->v < v]);
	Node* t=new Node(v);
	x->ch[x->v<v]=t;
	t->pre=x;
	splay(t,NULL);
	return t;
}
Node* findNext(int r, int v)//>=V
{
	Node* x=root[r];
	Node* tmp=root[r]->v>=v?root[r]:NULL;
	for(;x;x=x->ch[x->v<v])
	{
		if(x->v==v)
			return x;
		if(x->v>v)
			tmp=x;
	}
	return tmp;
}
Node* findPrev(int r, int v)//<=V
{
	Node* x=root[r];
	Node* tmp=root[r]->v<=v?root[r]:NULL;
	for(;x;x=x->ch[x->v<v])
	{
		if(x->v==v)
			return x;
		if(x->v<v)
			tmp=x;
	}
	return tmp;
}

void remove(int r,Node* t)
{
	splay(t,NULL);
	for(int i=0;i<2;i++)
		if(!t->ch[i])
		{
			root[r]=root[r]->ch[1-i];
			if(root[r])
				root[r]->pre=NULL;
			return;
		}
	Node* x=root[r]->ch[0];
	for(;x->ch[1]; x = x->ch[1]);
	splay(x,root[r]);
	x->ch[1]=root[r]->ch[1];
	x->ch[1]->pre=x;
	root[r]->ch[0]=root[r]->ch[1]=root[r]->pre=NULL;
	root[r]=x;root[r]->pre=NULL;
	update(x);

}
int main()
{
	freopen("pet.in","r",stdin);freopen("pet.out","w",stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		Node* t = insert(a, b);
		if (root[1 - a])
		{
			Node* P = findPrev(1 - a, b);
			Node* N = findNext(1 - a, b);
			if ((P && !N) || P&&N && abs(P->v - b) <= abs(N->v - b))
			{
				ans = (ans + abs(P->v - b)) % E;
				remove(1-a,P);
				remove(a,t);
			}
			else
			{
				ans = (ans + abs(N->v - b)) % E;
				remove(1-a,N);
				remove(a,t);
			}
		}
	}
	printf("%d\n",ans);
	fclose(stdin);fclose(stdout);
}
