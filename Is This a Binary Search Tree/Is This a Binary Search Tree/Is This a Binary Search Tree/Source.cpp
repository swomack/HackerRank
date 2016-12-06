#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};


void inOrderTraverse(Node* node, vector<int>& result)
{
	if (node == NULL)
		return;

	inOrderTraverse(node->left, result);
	result.push_back(node->data);
	inOrderTraverse(node->right, result);
}


bool checkBST(Node* root) 
{
	if (root == NULL)
		return true;

	vector<int> in_order;
	inOrderTraverse(root, in_order);

	for (int i = 0; i < in_order.size() - 1; i++)
	{
		if (in_order[i + 1] <= in_order[i])
			return false;
	}

	return true;
}

int main()
{
	return 0;
}