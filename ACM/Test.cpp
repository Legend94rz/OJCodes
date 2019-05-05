#include <iostream>
#include <stack>
using namespace std;

void* st[10000];
int top;


struct Node
{
	Node* left;
	Node* right;
	int val;
};

#define RETURN 				 \
{							 \
int addr = (int)st[top--];	 \
if (addr == 1)				 \
	goto RETURN1;			 \
if (addr == 2)				 \
	goto RETURN2;			 \
}							 \



void F()
{
BEGIN:
	Node* p = NULL; 
	p = (Node*)st[top - 1];
	if (p == NULL)
	{
		RETURN
	}
	cout << p->val << endl;
	st[++top] = (void*)p->left;
	st[++top] = (void*)1;
	goto BEGIN;
RETURN1:
	top -= 1;

	p = (Node*)st[top - 1];
	st[++top] = (void*)p->right;
	st[++top] = (void*)2;
	goto BEGIN;
RETURN2:
	top -= 1;
	RETURN
}

int main()
{
	Node* root = new Node(); root->val = 1;
	Node* n1 = new Node(); root->left = n1; n1->val = 2;
	Node* n2 = new Node(); root->right = n2; n2->val = 3;
	Node* n3 = new Node(); n1->left = n3; n3->val = 4;
	Node* n4 = new Node(); n1->right= n4; n4->val = 5;


	st[++top] = root;
	st[++top] = 0;
	F();
}
