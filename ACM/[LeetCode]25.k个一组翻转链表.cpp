#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <tuple>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	tuple<ListNode*, ListNode*> rev(ListNode* p, int k, const int K)
	{
		if (p == NULL)
			return make_tuple((ListNode*)NULL, (ListNode*)NULL);
		if (k == K)
			return make_tuple(p, p->next);
		auto root = rev(p->next, k + 1, K);
		if (get<0>(root))
			p->next->next = p;
		return root;
	}

	ListNode* reverseKGroup(ListNode* head, int k)
	{
		auto pair = rev(head, 1, k);
		ListNode* nhead = get<0>(pair);
		if (nhead == NULL)
			return head;
		head->next = get<1>(pair);
		ListNode* pre = head;
		while (head->next)
		{
			ListNode* q = head->next;
			auto t = rev(head->next, 1, k);
			if (get<0>(t) == NULL)break;
			head->next->next = get<1>(t);
			head->next = get<0>(t);
			head = q;
		}
		return nhead;
	}
};

void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

ListNode* stringToListNode(string input) {
	// Generate list from the input
	vector<int> list = stringToIntegerVector(input);

	// Now convert that list into linked list
	ListNode* dummyRoot = new ListNode(0);
	ListNode* ptr = dummyRoot;
	for (int item : list) {
		ptr->next = new ListNode(item);
		ptr = ptr->next;
	}
	ptr = dummyRoot->next;
	delete dummyRoot;
	return ptr;
}

int stringToInteger(string input) {
	return stoi(input);
}

string listNodeToString(ListNode* node) {
	if (node == nullptr) {
		return "[]";
	}

	string result;
	while (node) {
		result += to_string(node->val) + ", ";
		node = node->next;
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
	string line;
	while (getline(cin, line)) {
		ListNode* head = stringToListNode(line);
		getline(cin, line);
		int k = stringToInteger(line);

		ListNode* ret = Solution().reverseKGroup(head, k);

		string out = listNodeToString(ret);
		cout << out << endl;
	}
	return 0;
}