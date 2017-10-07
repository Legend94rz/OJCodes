#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;
#define Size(x) (x==NULL?0:x->sz)
struct Node
{
	Node* ch[2];
	Node* pre;
	int val;
	int sz;
	bool reverse;
	Node(int v, Node* p)
	{
		ch[0] = ch[1] = NULL;
		pre = p; sz = 1; reverse = false; val = v;
	}
};
Node* root;
int n, m, l, r;
void pushdown(Node* x)
{
	if (x && x->reverse)
	{
		if (x->ch[0])
			x->ch[0]->reverse ^= 1;
		if (x->ch[1])
			x->ch[1]->reverse ^= 1;
		swap(x->ch[0], x->ch[1]);
		x->reverse = false;
	}
}
void update(Node* x)
{
	x->sz = 1;
	if (x->ch[0])
		x->sz += x->ch[0]->sz;
	if (x->ch[1])
		x->sz += x->ch[1]->sz;
}

void Rotate(Node* x, int direction)//0-左;1-右。左旋x即x位于父结点的右儿子，需要左旋;右旋反之
{
	Node* y = x->pre;
	pushdown(y), pushdown(x);
	//摘下x的子结点，挂到y上
	y->ch[!direction] = x->ch[direction];
	if (x->ch[direction])x->ch[direction]->pre = y;
	//连接x与y的父亲
	x->pre = y->pre;
	if (y->pre)
		y->pre->ch[y->pre->ch[1] == y] = x;
	//使x成为y的父亲
	y->pre = x;
	x->ch[direction] = y;
	update(y);
	if (root == y)
		root = x;
}
void splay(Node* x, const Node* f)
{
	for (pushdown(x); x->pre != f;)
		if (x->pre->pre == f)
			Rotate(x, x->pre->ch[0] == x);
		else
		{
			Node* y = x->pre;
			Node* z = y->pre;
			if (z->ch[0] == y)
				if (y->ch[0] == x)
					Rotate(y, 1), Rotate(x, 1);
				else
					Rotate(x, 0), Rotate(x, 1);
			else
				if (y->ch[1] == x)
					Rotate(y, 0), Rotate(x, 0);
				else
					Rotate(x, 1), Rotate(x, 0);
		}
	update(x);
}
void insert(int x, Node*& target, Node* parent)
{
	if (!target)
	{
		target = new Node(x, parent);
		if (parent)
			parent->ch[target->val >= parent->val] = target;
		splay(target,NULL);
	}
	else
		insert(x, target->ch[x >= target->val], target);
}
Node* find(int rank)
{
	Node* x;
	for (x = root;;)
	{
		pushdown(x);
		int tmp = Size(x->ch[0]);
		if (rank == tmp + 1)break;
		if (rank < tmp + 1)
			x = x->ch[0];
		else
			rank -= tmp + 1, x = x->ch[1];
	}
	return x;
}
void print(Node* p)
{
	if (!p)return;
	pushdown(p);
	print(p->ch[0]);
	if(p->val!=0 && p->val!=n+1)
		printf("%d ", p->val);
	print(p->ch[1]);
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n + 1; i++)
	{
		insert(i, root, NULL);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &l, &r);
		Node* a = find(l);
		Node* b = find(r + 2);
		splay(a, NULL);
		splay(b, a);
		if (b->ch[0])
			b->ch[0]->reverse ^= 1;
	}
	print(root);
	printf("\n");
}