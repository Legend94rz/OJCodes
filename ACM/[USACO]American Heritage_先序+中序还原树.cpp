/*
ID: rz019291
LANG: C++
PROG: heritage
*/
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
string a, b;
int J;
struct Node {
	Node* left;
	Node* right;
	char c;
	Node(char c)
	{
		this->right = right;
		this->left = left;
		this->c = c;
	}
};

Node* build(int l, int r)//a's l,r
{
	if (l > r)return NULL;
	char c = b[++J];
	int k = a.find(c);
	Node* t = new Node(c);
	Node* L = build(l, k - 1);
	Node* R = build(k + 1, r);
	t->left = L;
	t->right = R;
	return t;
}

void post(Node* p)
{
	if (!p)return;
	post(p->left);
	post(p->right);
	cout << p->c;
}

int main()
{
	freopen("heritage.in", "r", stdin); freopen("heritage.out", "w", stdout);
	cin >> a >> b;
	J = -1;
	post(build(0, a.length()-1));
	cout << endl;
	fclose(stdin); fclose(stdout);
}