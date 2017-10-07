#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define Sum(x) (x?x->sum:0)
#define MaxS(x) (x?x->maxs:-0x3f3f3f3f)
struct coor
{
	int x,y;
};
struct Node
{
	int val,d,maxs,sum;
	Node* ch[2],* pre;
	Node(int v,int d)
	{
		val=v;sum=maxs=this->d=d;
		ch[0]=ch[1]=pre=NULL;
	}
};
int s,w,n;
coor a[20000];
Node* root;
int cmp(const void* a,const void* b)
{
	const coor* pa=(const coor*)a;
	const coor* pb=(const coor*)b;
	if(pa->x<pb->x)return -1;
	if(pa->x==pb->x && pa->y<pb->y)return -1;
	return 1;
}
void update(Node* x)
{
	if(x)
	{
		x->sum=Sum(x->ch[0])+Sum(x->ch[1])+x->d;
		x->maxs=max(MaxS(x->ch[0]),max(Sum(x->ch[0])+x->d,Sum(x->ch[0])+x->d+MaxS(x->ch[1])));
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

	update(y);
	if(root==y)root=x;
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
void edit(int target,int delta)
{
	if(!root)
	{
		root=new Node(target,delta);
		return;
	}
	Node* x=root;
	Node* f=root->pre;
	while(x)
	{
		if(target<x->val)
		{
			f=x;
			x=x->ch[0];
		}
		else if(target>x->val)
		{
			f=x;
			x=x->ch[1];
		}
		else
		{
			x->d+=delta;
			break;
		}
	}
	if(!x)
	{
		x=new Node(target,delta);
		f->ch[target>f->val]=x;
		x->pre=f;
	}
	splay(x,NULL);
}

void remove(int s,int t)
{
	for(int i=s;i>=1 && i<=t;i++)
	{
		edit(a[i].y,-1);
		edit(a[i].y+w+1,1);
	}
}
void insert(int s,int t)
{
	for(int i=s;i>=1 && i<=t;i++)
	{
		edit(a[i].y,1);
		edit(a[i].y+w+1,-1);
	}
}
int getmax()
{
	update(root);
	return root->maxs;
}
int main()
{
	freopen("kop.in","r",stdin);freopen("kop.out","w",stdout);
	scanf("%d %d",&s,&w);
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d",&a[i].x,&a[i].y);
	}
	qsort(&a[1],n,sizeof(coor),cmp);
	int ans;
	int l=0,r=0,i=1,j=1;
	ans=a[0].x=a[0].y=-0x3f3f3f3f;
	for(;;)
	{
		while(a[i].x==a[l].x && i<n)i++;
		remove(l,i-1);
		l=i;

		j=r+1;
		while(a[j].x-a[l].x<=s && j<=n)j++;
		insert(r+1,j-1);
		r=j-1;

		int t=getmax();
		if(t>ans)ans=t;
		if(r>=n)break;
	}
	printf("%d\n",ans);
	fclose(stdin);fclose(stdout);
}
