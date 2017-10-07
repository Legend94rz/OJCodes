#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdarg>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define LOWER -0x3f3f3f3f
#define Size(x) (x?x->sz:0)
#define Sum(x) (x?x->sum:0)
#define MaxL(x) (x?x->maxL:LOWER)
#define MaxR(x) (x?x->maxR:LOWER)
#define MaxM(x) (x?x->maxM:LOWER)
//要注意各标记一定是表示每个结点它两个子树的性质，与该结点本身无关。
//因为rotate之后的update会用到结点它孩子结点上的性质，如果标记包含了本身，那么pushdown正好把标记传到子结点上，导致update用了一个未更新完全的半成品，这样的结果是不对的。
//若非要想表示成包含子结点， 那么rotate前面的pushdown要多下传几层，确保update(x)的时候，x的两个子结点都已经不带任何标记。
class Node
{
public:
	Node* ch[2], *pre;
	int val, sz, maxM, maxL, maxR, sum;
	bool isFlip, isSame;
	Node(int v)
	{
		ch[0] = ch[1] = pre = NULL;
		maxL = maxM = maxR = val = sum = v;
		sz = 1;
		isFlip = isSame = false;
	}
};
int N, M;
int a[1000001];
Node* root;
char op[20];
int pos, tot;
int max(int count, ...)
{
	int ans = LOWER;
	va_list vl;
	va_start(vl, count);
	for (int i = 0; i<count; i++)
	{
		int t = va_arg(vl, int);
		if (t>ans)ans = t;
	}
	va_end(vl);
	return ans;
}
void same(Node* x, int c)
{
	if (!x)return;
	x->isSame = true;
	x->val = c;
	x->maxL = x->maxR = x->maxM = x->sum = x->sz*x->val;
	if (x->val<0)
		x->maxL = x->maxR = x->maxM = x->val;
}
void flip(Node* x)
{
	if(!x)return;
	x->isFlip^=1;
	swap(x->ch[0],x->ch[1]);
	swap(x->maxL,x->maxR);
}
void pushdown(Node* x)
{
	if (!x)return;
	if (x->isFlip)
	{
		flip(x->ch[0]);flip(x->ch[1]);
		x->isFlip = false;
	}
	if (x->isSame)
	{
		same(x->ch[0], x->val); same(x->ch[1], x->val);
		x->isSame = false;
	}
}
void update(Node* x)
{
	if (!x)return;
	x->sz = Size(x->ch[0]) + Size(x->ch[1]) + 1;
	x->sum = Sum(x->ch[0]) + Sum(x->ch[1]) + x->val;
	x->maxL = max(3, MaxL(x->ch[0]), Sum(x->ch[0]) + x->val + MaxL(x->ch[1]), Sum(x->ch[0]) + x->val);
	x->maxR = max(3, MaxR(x->ch[1]), MaxR(x->ch[0]) + x->val + Sum(x->ch[1]), x->val + Sum(x->ch[1]));
	x->maxM = max(6, MaxM(x->ch[0]), MaxM(x->ch[1]), MaxR(x->ch[0]) + x->val + MaxL(x->ch[1]), MaxR(x->ch[0]) + x->val, x->val + MaxL(x->ch[1]), x->val);
}
void Rotate(Node* x, int c)
{
	Node* y = x->pre;
	pushdown(y);pushdown(x);

	y->ch[!c] = x->ch[c];
	if (x->ch[c])x->ch[c]->pre = y;

	x->pre = y->pre;
	if (y->pre)y->pre->ch[y->pre->ch[1] == y] = x;

	y->pre = x;
	x->ch[c] = y;

	if (root == y)root = x;
	update(y);
}
void splay(Node* x, Node* f)
{
	for (pushdown(x); x->pre != f;)
	{
		Node* y = x->pre;
		Node* z = y->pre;
		if (z == f)
			Rotate(x, y->ch[0] == x);
		else
			if (z->ch[0] == y)
				if (y->ch[0] == x)
					Rotate(y, 1), Rotate(x, 1);
				else
					Rotate(x, 0), Rotate(x, 1);
			else
				if (y->ch[0] == x)
					Rotate(x, 1), Rotate(x, 0);
				else
					Rotate(y, 0), Rotate(x, 0);
	}
	update(x);
}
Node* find(int k)
{
	for (Node* x = root;;)
	{
		pushdown(x);
		int tmp = Size(x->ch[0]);
		if (k == tmp + 1)
			return x;
		if (k <= tmp)
			x = x->ch[0];
		else
		{
			k -= tmp + 1;
			x = x->ch[1];
		}
	}
}
Node* slice(int a, int b)
{
	Node* x = find(a - 1);
	Node* y = find(b + 1);
	splay(x, NULL);
	splay(y, x);
	return y->ch[0];
}
Node* build(int l, int r)
{
	if (l>r)return NULL;
	if (l == r)return new Node(a[l]);
	int mid = (l + r) >> 1;
	Node* L = build(l, mid - 1);
	Node* p = new Node(a[mid]);
	Node* R = build(mid + 1, r);
	p->ch[0] = L; p->ch[1] = R;
	if (L)L->pre = p;
	if (R)R->pre = p;
	update(p);
	return p;
}

void init()
{
	root = new Node(0);
	Node* tail = new Node(0);
	root->ch[1] = tail;
	tail->pre = root;
	tail->ch[0] = build(0, N - 1);
	splay(tail, NULL);
}
void Insert()
{
	scanf("%d %d", &pos, &tot);
	for (int i = 0; i < tot; i++)
	{
		scanf("%d", &a[i]);
	}
	Node* tmp = build(0, tot - 1);
	slice(pos + 2, pos + 1);
	root->ch[1]->ch[0] = tmp;
	tmp->pre = root->ch[1];
	splay(root->ch[1], NULL);
}
void Delete()
{
	scanf("%d %d", &pos, &tot);
	Node* tmp = slice(pos + 1, pos + 1 + tot - 1);
	tmp->pre = NULL;
	root->ch[1]->ch[0] = NULL;
	splay(root->ch[1], NULL);
}
void MaxSum()
{
	Node* t = slice(2, root->sz - 1);
	printf("%d\n", t->maxM);
}
void MakeSame()
{
	int c;
	scanf("%d %d %d", &pos, &tot, &c);
	Node* t = slice(pos + 1, pos + 1 + tot - 1);
	same(t, c);
	splay(t, NULL);
}
void GetSum()
{
	scanf("%d %d", &pos, &tot);
	Node* t = slice(pos + 1, pos + 1 + tot - 1);
	printf("%d\n", Sum(t));
}
void Reverse()
{
	scanf("%d %d", &pos, &tot);
	Node* t = slice(pos + 1, pos + 1 + tot - 1);
	flip(t);
	splay(t, NULL);
}
int main()
{
	freopen("seq2005.in", "r", stdin); freopen("seq2005.out", "w", stdout);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	init();
	for (int i = 0; i<M; i++)
	{
		scanf("%s", &op);
		switch (op[0])
		{
		case 'I':Insert(); break;
		case 'D':Delete(); break;
		case 'M':
			if (op[2] == 'X')
				MaxSum();
			else
				MakeSame();
			break;
		case 'R':Reverse(); break;
		case 'G':GetSum(); break;
		}
	}
	fclose(stdin); fclose(stdout);
}
