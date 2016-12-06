#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};


bool isValidBSTHelper(Node* node, int min_limit, int max_limit, bool left_inclusive, bool right_inclusive)
{
	if (node == NULL)
		return true;

	bool bst;

	if (left_inclusive && right_inclusive)
		bst = node->data >= min_limit && node->data <= max_limit ? true : false;
	else if (left_inclusive)
		bst = node->data >= min_limit && node->data < max_limit ? true : false;
	else if (right_inclusive)
		bst = node->data > min_limit && node->data <= max_limit ? true : false;
	else
		bst = node->data > min_limit && node->data < max_limit ? true : false;

	if (!bst)
		return false;

	return isValidBSTHelper(node->left, min_limit, node->data, left_inclusive, false) && isValidBSTHelper(node->right, node->data, max_limit, false, right_inclusive);
}


bool checkBST(Node* root) 
{
	if (root == NULL)
		return true;

	return isValidBSTHelper(root->left, INT_MIN, root->data, true, false) && isValidBSTHelper(root->right, root->data, INT_MAX, false, true);
}

int main()
{
	return 0;
}