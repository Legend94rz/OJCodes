#include <iostream>
#include <string>
using namespace std;
struct Node
{
	Node* left, *right;
	int data;
	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};
Node* root[1000];
int n;
string t;
void put(int x, Node** p)
{
	if (*p == NULL)
		*p = new Node(x);
	if (x < (*p)->data)
		put(x, &((*p)->left));
	else if (x > (*p)->data)
		put(x, &((*p)->right));
}
Node* build(string s, int index)
{
	for (size_t i = 0; i < s.length(); i++)
		put(s[i], &root[index]);
	return root[index];
}
bool match(Node* p1, Node* p2)
{
	if (p1 == NULL && p2 == NULL)return true;
	if (p1 != NULL && p2 != NULL)
		return p1->data == p2->data && match(p1->left, p2->left) && match(p1->right, p2->right);
	else
		return false;
}
int main()
{
	for (;;)
	{
		cin >> n;
		if(n==0)break;
		memset(root,0,sizeof(root));
		cin >> t;
		root[0] = build(t, 0);
		for (int i = 1; i <= n; i++)
		{
			cin >> t;
			root[i] = build(t, i);
			if (match(root[i], root[0]))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
}
