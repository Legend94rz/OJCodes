#include <iostream>
#include <string>
using namespace std;
string s;
struct Node
{
	char data;
	int count;
	Node* children[26];
	int L;
};
Node* root;
void solve(const string& s)
{
	Node* temp = root;
	for ( int i = 0; i < s.length(); i++ )
	{
		Node* t = NULL;
		for ( int j = 0; j<temp->L; j++ )
		{
			if ( temp->children[j] && temp->children[j]->data == s[i] ){ t = temp->children[j]; break; }
		}
		if ( !t )
		{
			t = new Node();
			t->data = s[i];
			temp->children[temp->L] = t;
			temp->L+=1;
		}
		temp = t;
		temp->count++;
	}
}
int find(string s)
{
	Node* temp = root;
	for ( int i = 0; i < s.length(); i++ )
	{
		Node* t = NULL;
		for ( int j = 0; j<temp->L; j++ )
		{
			if ( temp->children[j] && temp->children[j]->data == s[i] ){ t = temp->children[j]; break; }
		}
		if ( !t )return 0;
		temp = t;
	}
	return temp->count;
}
int main()
{
	root = new Node();
	while ( getline(cin, s), s != "" )
	{
		solve(s);
	}
	while ( getline(cin, s) )
	{
		cout << find(s) << endl;
	}
	//system("pause");
}
