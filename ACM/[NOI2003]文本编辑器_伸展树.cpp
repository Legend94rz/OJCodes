#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define Size(x) (x?x->sz:0)
const int MAXS = 2*1024*1024+1;
struct Node
{
	int sz;
	char c;
	Node* ch[2];
	Node* pre;
};
Node* root;
int n;
int cursor=0;
char op[10];
char str[MAXS];
Node Tree[MAXS];
int Len;
Node* newNode(char chr)
{
	Len++;Tree[Len].c=chr;
	Tree[Len].pre = Tree[Len].ch[0]=Tree[Len].ch[1]=NULL;
	Tree[Len].sz=1;
	return &Tree[Len];
}
Node* build(int l,int r)
{
	if(l>r)return NULL;
	if(l==r)return newNode(str[l]);
	int mid=(l+r)>>1;
	Node* p=newNode(str[mid]);
	p->ch[0] = build(l,mid-1);
	p->ch[1] = build(mid+1,r);
	if(p->ch[0])p->ch[0]->pre = p;
	if(p->ch[1])p->ch[1]->pre = p;
	p->sz += Size(p->ch[0])+Size(p->ch[1]);
	return p;
}
void print(Node* r)
{
	if(!r)return;
	print(r->ch[0]);
	printf("%c",r->c);
	print(r->ch[1]);
}
void update(Node* x)
{
	x->sz = Size(x->ch[0])+Size(x->ch[1])+1;
}

void Rotate(Node* x,int c)
{
	Node* y=x->pre;

	y->ch[!c]=x->ch[c];
	if(x->ch[c])x->ch[c]->pre=y;

	x->pre=y->pre;
	if(y->pre) y->pre->ch[y->pre->ch[1]==y]=x;

	y->pre=x;
	x->ch[c]=y;

	if(y==root)root=x;
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

Node* find(int k)
{
	for(Node* x=root;;)
	{
		int tmp=Size(x->ch[0]);
		if(tmp+1==k)
			return x;
		else if(k<=tmp)
			x=x->ch[0];
		else
		{
			k-=tmp+1;
			x=x->ch[1];
		}
	}
}


Node* slice(int a,int b)
{
	Node* x=find(a-1);
	Node* y=find(b+1);
	splay(x,NULL);
	splay(y,x);
	return y->ch[0];
}

void Insert()
{
	int m;
	scanf("%d",&m);
	for (int i=0;i<m;)
	{
		scanf("%c",&str[i]);
		if(str[i]=='\n')continue;
		i++;
	}
	Node* tmp=build(0,m-1);
	slice(cursor+2,cursor+1);
	root->ch[1]->ch[0]=tmp;
	tmp->pre = root->ch[1];
	splay(tmp,NULL);
}
void Move(){scanf("%d",&cursor); /*splay(find(cursor + 1), NULL);*/}
void Delete()
{
	int m;
	scanf("%d",&m);
	slice(cursor+2,cursor+2+m-1);
	root->ch[1]->ch[0]=NULL;
	splay(root->ch[1],NULL);
}
void Next(){cursor++; /*splay(find(cursor + 1), NULL);*/}
void Get()
{
	int m;
	scanf("%d",&m);
	Node* tmp = slice(cursor+2,cursor+2+m-1);
	print(tmp);
	printf("\n");
}
void Prev(){cursor--;/*splay(find(cursor+1),NULL);*/}
void init()
{
	root=newNode(0);
	Node* tail=newNode(127);
	root->ch[1]=tail;
	tail->pre=root;
	root->sz = 2;
}
int main()
{
	freopen("editor2003.in","r",stdin);freopen("2.out","w",stdout);
	scanf("%d",&n);
	init();
	for (int i = 0; i < n; i++)
	{
		scanf("%s",&op);
		switch (op[0])
		{
			case 'I':Insert();break;
			case 'M':Move();break;
			case 'N':Next();break;
			case 'P':Prev();break;
			case 'G':Get();break;
			case 'D':Delete();break;
		}
	}
	fclose(stdin);fclose(stdout);
}
